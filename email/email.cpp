#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <streambuf>
#include <unistd.h>
#include <map>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#include <sys/timerfd.h>

#ifdef NO_PRIO
  #include "noprio_macros.h"
#else
  #include <cilk/cilk_priority.h>
#endif

#include "email_protocol.h"
#include "error.h"

#include "email_priorities.h"
// Inbox needs the priorities
#include "inbox.h"

#include "../bench/include/common/ktiming.h"
#include "../bench/include/common/getoptions.h"

#define BACKLOG   (64)

#define CACHE_LINE_SIZE (64) 

clockmark_t totalTime;
static int compressionPeriod = 1000000;
static int compressionChunkSize = 50;
static int maxMessageCount = 90000;//3000000;
static int maxUsers = 180;
static int maxCompressionTimes = 0; 
static volatile bool done = false;
static inbox **userMailboxes;
static cilk::pfuture<void, Low> **waitForPendingFutures;
std::map<std::string, int> usernameToUserId;
static clockmark_t **compressionTimes;
static int *missedCompressions;
static int *totalCompressions;

CilkPrioCommandPrototype(int, acceptConnections, const char *const /* port */);
CilkPrioCommandPrototype(void, clientLoop, int /* clientFd */, int /* userIdNo */);
CilkPrioCommandPrototype(void, periodicCompress, inbox* /* mailbox */);
CilkPrioCommandPrototype(int, compressChunkIfNotAlready, inbox* /* mailbox */, int /* firstMessageIdInChunk */, cilk::pfuture<int, PrintOrCompressP>* /* myHandle */, clockmark_t /* startTime */, clockmark_t* /* storeTime */);
CilkPrioCommandPrototype(void, waitForAll, inbox* /* myInbox */, cilk::pfuture<void, PeriodicCompressP>* /* periodicCompressHandle */, cilk::pfuture<void, SortP>* /* sortHandle */);
CilkPrioCommandPrototype(void, sendEmail, int /* clientFd */, int /* from */, std::string* /* to */, std::string* /* subject */, std::string* /* msg */, cilk::pfuture<void, SendP>* /* prevSend */, clockmark_t /* respStart */);
CilkPrioCommandPrototype(void, sortInbox, int /* clientFd */, int /* sortFieldId */, inbox* /* myInbox */, cilk::pfuture<void, SortP>* /* prevSortHandle */, clockmark_t /* respStart */); 
CilkPrioCommandPrototype(int, printEmail, int /* clientFd */, inbox* /* myInbox */, int /* emailId */, cilk::pfuture<int, PrintOrCompressP>* /* myPrintHandle */, clockmark_t /* respStart */);

std::vector<int>* closeSocketsHack;

void __attribute__((destructor)) closeAllSockets() {
  for (int sockFd : *closeSocketsHack) {
    close(sockFd);
  }
  delete closeSocketsHack;
  // This is more a formality than anything else;
  // The mailboxes should exist for the duration anyway
  for (int i = 0; i < maxUsers; i++) {
    delete userMailboxes[i];
    delete [] compressionTimes[i];
  }
  delete [] userMailboxes;
  delete [] compressionTimes;
}

void setFileNonblocking(int fd) {
  int prevFlags = fcntl(fd, F_GETFL);
  checkError(prevFlags == -1, "Error in fcntl(..., F_GETFL): ");
  int err = fcntl(fd, F_SETFL, prevFlags | O_NONBLOCK);
  checkError(err == -1, "Error in fcntl(..., F_SETFL): ");
}

int openServerSocket(const char *const port) {
  struct addrinfo hints;
  struct addrinfo *serverInfo;
  int serverFd = 0;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int err = getaddrinfo(NULL, port, &hints, &serverInfo);
  checkError(err != 0, "Error in getaddrinfo(...): ");

  serverFd = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);
  checkError(serverFd < 0, "Error in socket(...): ");

  err = bind(serverFd, serverInfo->ai_addr, serverInfo->ai_addrlen);
  checkError(err < 0, "Error in bind(...): ");

  err = listen(serverFd, BACKLOG);
  checkError(err != 0, "Error in listen(...): ");

  setFileNonblocking(serverFd);

  return serverFd;
}

CilkPrioCommandDefine(void, waitForAll, (inbox *myInbox, cilk::pfuture<void, PeriodicCompressP>* periodicCompressHandle, cilk::pfuture<void, SortP>* sortHandle), {

  if (sortHandle) {
    cilk_pfuture_get(sortHandle);
    delete sortHandle;
  }

  cilk_pfuture_get(periodicCompressHandle);
  delete periodicCompressHandle;

  std::atomic<cilk::pfuture<int, PrintOrCompressP>*>* compressionStates = myInbox->getCompressionStates();
  cilk::pfuture<int, PrintOrCompressP> *currCompressHandle;

  for (int i = 0; i < maxMessageCount / compressionChunkSize; i++) {
    currCompressHandle = compressionStates[i].exchange((cilk::pfuture<int, PrintOrCompressP>*)COMPRESS__ABORT);
    if (currCompressHandle) {
      cilk_pfuture_get(currCompressHandle);
      delete currCompressHandle;
    }
  }
});

CilkPrioCommandDefine(void, sendEmail, (int clientFd, int from, std::string *to, std::string *subject, std::string *msg, cilk::pfuture<void, SendP> *prevSend, clockmark_t respStart), {
  commandResponse sendResp;
  sendResp.header.type = EMAIL_RESP_TYPE__SEND;
  sendResp.header.unused = 0;
  sendResp.header.length = sizeof(sendResponse);

  auto userIdIterator = usernameToUserId.find(*to);
  if (userIdIterator != usernameToUserId.end()) {
    int toUserId = userIdIterator->second;
    email *mail = new email(userMailboxes[from]->getUsername(), *to, *subject, *msg);
    userMailboxes[toUserId]->addEmail(mail);
    sendResp.send.msgSent = 1;
  } else {
    sendResp.send.msgSent = 0;
    printf("Could not find user %s!\n", to->c_str());
  }

  respAddTimestamp(&sendResp, respStart);
  writePacket(clientFd, &sendResp.header);

  delete to;
  delete subject;
  delete msg;

  if (prevSend != nullptr) {
    cilk_pfuture_get(prevSend);
    delete prevSend;
  }
});

CilkPrioCommandDefine(void, sortInbox, (int clientFd, int sortFieldId, inbox *myInbox, cilk::pfuture<void, SortP>* prevSortHandle, clockmark_t respStart), {
  inbox *copyOfMyInbox = myInbox->copy();
  int currN = copyOfMyInbox->getMsgCount();
  copyOfMyInbox->sortFirstNEmailsById(currN, sortFieldId);

  commandResponse sortResp;
  sortResp.header.type = EMAIL_RESP_TYPE__SORT;
  sortResp.header.unused = 0;
  std::stringbuf pktBuf;
  pktBuf.pubsetbuf(sortResp.sort.sortedMessageSubjects, MAX_MSG_LENGTH);
  std::ostream emailString(&pktBuf);
  copyOfMyInbox->printSubjects(emailString);
  long length = emailString.tellp()+1l;
  sortResp.header.length = length;
  sortResp.sort.sortedMessageSubjects[length-1] = '\0';
  respAddTimestamp(&sortResp, respStart);
  writePacket(clientFd, &sortResp.header);

  if (prevSortHandle) {
    cilk_pfuture_get(prevSortHandle);
    delete prevSortHandle;
  }

  delete copyOfMyInbox;
});

CilkPrioCommandDefine(int, printEmail, (int clientFd, inbox *myInbox, int emailId, cilk::pfuture<int, PrintOrCompressP> *myPrintHandle, clockmark_t respStart), {
  // We are getting random IDs; just make sure the ID is valid (unless empty)
  int msgCount = myInbox->getMsgCount();
  if (msgCount == 0) msgCount = 1;
  emailId = emailId % msgCount;

  commandResponse printResp;
  printResp.header.type = EMAIL_RESP_TYPE__PRINT;
  printResp.header.unused = 0;

  cilk::pfuture<int, PrintOrCompressP> *prevHandle = myInbox->exchangeCompressionHandle(emailId, myPrintHandle);

  int compressed = 0;

  if (prevHandle) {
    if ((uintptr_t)prevHandle == COMPRESS__ABORT) {
      printResp.header.length = 0;
      respAddTimestamp(&printResp, respStart);
      writePacket(clientFd, &printResp.header);
      //close(clientFd);
      return (int)COMPRESS__ABORT;
    }
    compressed = cilk_pfuture_get(prevHandle);
    delete prevHandle;
  } 

  if (compressed == COMPRESS__ABORT) {
    printResp.header.length = 0;
    respAddTimestamp(&printResp, respStart);
    writePacket(clientFd, &printResp.header);
    //close(clientFd);
    return (int)COMPRESS__ABORT;
  }

  if (compressed) {
    myInbox->decompressContainingChunk(emailId);
  }

  std::stringbuf pktBuf;
  pktBuf.pubsetbuf(printResp.print.rawMessage, MAX_MSG_LENGTH);
  std::ostream emailString(&pktBuf);
  myInbox->printEmail(emailString, emailId);
  long length = emailString.tellp()+1l;
  printResp.header.length = length;
  printResp.print.rawMessage[length-1] = '\0';
  respAddTimestamp(&printResp, respStart);
  writePacket(clientFd, &printResp.header);

  return 0;
});

CilkPrioCommandDefine(void, clientLoop, (int clientFd, int userIdNo), {
  emailCommand input;
  char *to = NULL;
  char *subject = NULL;
  char *msg = NULL;

  setFileNonblocking(clientFd);
  __sync_synchronize();
  inbox *myInbox = userMailboxes[userIdNo];

  cilk::pfuture<void, PeriodicCompressP> *periodicCompressHandle = new cilk::pfuture<void, PeriodicCompressP>();
  cilk_pfuture_create(periodicCompressHandle, periodicCompress, myInbox);

  cilk::pfuture<void, SendP> *sendHandle = nullptr;
  cilk::pfuture<void, SendP> *prevSendHandle = nullptr;
  cilk::pfuture<void, SortP> *sortHandle = nullptr;
  cilk::pfuture<void, SortP> *prevSortHandle = nullptr;
  memset(&input, '\0', sizeof(input.header));
  clockmark_t respStart;

  // Loop until disconnect or quit command
  while (readCommandPacket(clientFd, &input) >= sizeof(PacketHeader)) {
    respStart = ktiming_getmark();
    if (input.header.type == EMAIL_CMD_TYPE__SEND) {
      getSendParameters(&input, &to, &subject, &msg);

      prevSendHandle = sendHandle;
      sendHandle = new cilk::pfuture<void, SendP>();
      cilk_pfuture_create(sendHandle, sendEmail, clientFd, userIdNo, new std::string(to), new std::string(subject), new std::string(msg), prevSendHandle, respStart);

    } else if (input.header.type == EMAIL_CMD_TYPE__SORT) {
      prevSortHandle = sortHandle;
      sortHandle = new cilk::pfuture<void, SortP>();
      cilk_pfuture_create(sortHandle, sortInbox, clientFd, input.sort.sortFieldId, myInbox, prevSortHandle, respStart);

    } else if (input.header.type == EMAIL_CMD_TYPE__PRINT) {

      cilk::pfuture<int, PrintOrCompressP> *printHandle = new cilk::pfuture<int, PrintOrCompressP>();
      cilk_pfuture_create(printHandle, printEmail, clientFd, myInbox, input.print.emailPrintId, printHandle, respStart);

    } else if (input.header.type == EMAIL_CMD_TYPE__QUIT) {

      break;

    } else {

      printf("Err: Unsupported command type (%X)\n", input.header.type);
      break;

    }
  }

  waitForPendingFutures[userIdNo] = new cilk::pfuture<void, Low>();
  cilk_pfuture_create(waitForPendingFutures[userIdNo], waitForAll, myInbox, periodicCompressHandle, sortHandle);
});

int periodicCompressInitializeTimer(long usecPeriod) {
  int timerFd = timerfd_create(CLOCK_MONOTONIC, 0);
  checkError(timerFd == -1, "Error in timerfd_create: ");

  struct itimerspec timeout;
  timeout.it_interval = {
    .tv_sec = usecPeriod / 1000000,
    .tv_nsec = (usecPeriod % 1000000) * 1000
  }; 

  timeout.it_value = timeout.it_interval;

  int ret = timerfd_settime(timerFd, 0, &timeout, NULL);
  checkError(ret == -1, "Error in timerfd_settime: ");
  
  setFileNonblocking(timerFd);

  return timerFd;
}

CilkPrioCommandDefine(int, compressChunkIfNotAlready, (inbox *mailbox, int firstMessageIdInChunk, cilk::pfuture<int, PrintOrCompressP>* myHandle, clockmark_t startTime, clockmark_t *storeTime), {
  cilk::pfuture<int, PrintOrCompressP> *prevHandle = mailbox->exchangeCompressionHandle(firstMessageIdInChunk, myHandle);

  int compressed = 0;

  if (prevHandle != NULL) {
    if ((uintptr_t)prevHandle == COMPRESS__ABORT) {
      return (int)COMPRESS__ABORT;
    }
    compressed = cilk_pfuture_get(prevHandle);
    delete prevHandle;
  }

  if (compressed == COMPRESS__ABORT) return (int)COMPRESS__ABORT;

  if (!compressed) {
    mailbox->compressContainingChunk(firstMessageIdInChunk);
    if (storeTime) *storeTime = ktiming_getmark() - startTime;
  }

  return 1;
});

CilkPrioCommandDefine(void, periodicCompress, (inbox *mailbox), {
  int timerFd = periodicCompressInitializeTimer(compressionPeriod);
  uint64_t timeouts = 0;
  int msgCount = 0;
  cilk::pfuture<int, PrintOrCompressP>* currCompressionHandle;

  int myId = usernameToUserId[mailbox->getUsername()];
  clockmark_t *myCompressionTimes = new clockmark_t[maxCompressionTimes];
  clockmark_t *nextStorage = myCompressionTimes;
  int localMissedCompressions = 0;
  int localTotalCompressions = 0;

  // Wait for the timer to fire (via read)
  // Continue looping until the timer fails or the program is done
  while (cilk_read_sync(timerFd, &timeouts, sizeof(timeouts)) 
      && !done) {
    localMissedCompressions += timeouts - 1;
    localTotalCompressions++;
    msgCount = mailbox->getMsgCount();
    for (int i = 0; i < msgCount / compressionChunkSize; i++) {
      currCompressionHandle = new cilk::pfuture<int, PrintOrCompressP>();
      cilk_pfuture_create(currCompressionHandle, compressChunkIfNotAlready, mailbox, i*compressionChunkSize, currCompressionHandle, ktiming_getmark(), nextStorage);
      if (nextStorage && nextStorage < myCompressionTimes+maxCompressionTimes-1) {
        nextStorage++;
      } else {
        nextStorage = NULL;
      }
    }
  }

  close(timerFd);
  totalCompressions[myId] = localTotalCompressions;
  missedCompressions[myId] = localMissedCompressions;
  compressionTimes[myId] = myCompressionTimes;
});

CilkPrioCommandDefine(int, acceptConnections, (const char *const port), {
  cilk_enable_spawn_in_this_func();

  int serverFd = openServerSocket(port);

  int clientFd = 0;

  commandResponse connectionResponse;
  connectionResponse.header.type = EMAIL_RESP_TYPE__CONNECT;
  connectionResponse.header.length = sizeof(connectionResponse.connect);
  // Alias numConnections to the userId field in the packet
  uint32_t &numConnections = connectionResponse.connect.userId;
  numConnections = 0;

  while (numConnections < maxUsers) {
    clientFd = cilk_accept_sync(serverFd,  NULL, NULL);
    checkError(clientFd == -1, "Error in accept(serverFd, ...): ");

    if (numConnections == maxUsers-1) {
      // Start the timing here; the driver
      // has a barrier such that all requests will
      // start after all clients have connected
      totalTime = ktiming_getmark();
    }

    // Tell the client its user id!
    writePacket(clientFd, &connectionResponse.header);
    cilk_pspawn_void(LoopP, clientLoop, clientFd, numConnections);

    // Okay for now; not timed
    closeSocketsHack->push_back(clientFd);
    ++numConnections;
  }
  cilk_psync;
  // Wait until all clients are done
  done = true;
  __asm__ volatile ("" ::: "memory");
  close(serverFd);

  return numConnections;
});

const char *specifiers[] = {"-L", "-rho", "-delta", "-clients", "-messages", "-compressPeriodUs", "-compressChunk", "-port", 0};
int opt_types[] = {INTARG, DOUBLEARG, DOUBLEARG, INTARG, INTARG, INTARG, INTARG, INTARG, 0};

int main(int argc, char *argv[]) {
  int cilk_quantum_length_us = cilk_get_quantum_length_us();
  double cilk_rho = cilk_get_rho();
  double cilk_util_bound = cilk_get_util_bound();
  double cilk_init_desire = cilk_get_initial_desire();
  int cilk_rr_worker_count = cilk_get_round_robin_worker_count();
  int cilk_reserved_w_per_lvl = cilk_get_reserved_workers_per_level();
  char port[1024];
  int portNo = 9001;

  get_options(argc, argv, specifiers, opt_types, &cilk_quantum_length_us, &cilk_rho, &cilk_util_bound, &maxUsers, &maxMessageCount, &compressionPeriod, &compressionChunkSize, &portNo);

  sprintf(port, "%d", portNo);
  printf("%s\n", port);

  // Make sure maxMessageCount is an even multiple of compression chunk size
  maxMessageCount += (maxMessageCount % compressionChunkSize);
  maxCompressionTimes = (maxMessageCount / compressionChunkSize) * 100;

  // TODO: Now read in new values from command line (if supplied)
  
  cilk_set_quantum_length_us(cilk_quantum_length_us);
  cilk_set_rho(cilk_rho);
  cilk_set_util_bound(cilk_util_bound);
  cilk_set_initial_desire(cilk_init_desire);
  cilk_set_round_robin_worker_count(cilk_rr_worker_count);
  cilk_set_reserved_workers_per_level(cilk_reserved_w_per_lvl);
  cilk_reset_desires();

  compressionTimes = new clockmark_t*[maxUsers];

  missedCompressions = new int[maxUsers];
  totalCompressions = new int[maxUsers];

  // TODO: Must fix
  closeSocketsHack = new std::vector<int>();

  cilk_enable_diff_prio_spawn_in_this_func();

  userMailboxes = new inbox*[maxUsers];
  for (int i = 0; i < maxUsers; i++) {
    userMailboxes[i] = new inbox(maxMessageCount, compressionChunkSize);
  }

  waitForPendingFutures = (cilk::pfuture<void, Low>**) calloc(maxUsers, sizeof(inbox*));

  char tmpUsername[1024];
  for (int i = 0; i < maxUsers; i++) {
    // Make sure the addresses are all the same length (easier for benchmarking)
    snprintf(tmpUsername, 26, "userNumber%d@cse.wustl.edu", i);
    usernameToUserId[tmpUsername] = i;
    userMailboxes[i]->setUsername(tmpUsername);
  }

  int success = 0;
  cilk_pspawn(LoopP, &success, acceptConnections, port);
  cilk_psync;
  totalTime = ktiming_getmark() - totalTime;

  int max = 0;
  int currCount = 0;
  int totalCount = 0;

  for (int i = 0; i < maxUsers; i++) {
    if (waitForPendingFutures[i]) {
      cilk_pfuture_get(waitForPendingFutures[i]);
      delete waitForPendingFutures[i];
    }
  }

  for (int i = 0; i < maxUsers; i++) {
    if (userMailboxes[i]) {
      currCount = userMailboxes[i]->getMsgCount();
      totalCount += currCount;
      max = (max < currCount ? currCount : max);
      //delete userMailboxes[i];
    }
  }

  printf("Max messages in mailbox: %d\n", max);
  printf("Avg messages in mailbox: %lf\n", totalCount / (double)maxUsers);

  free(waitForPendingFutures);
  //free(userMailboxes);
  std::vector<clockmark_t> allCompressionTimes;

  int compressionPeriodCount = 0;
  int compressionPeriodsMissedCount = 0;
  
  for (int i = 0; i < maxUsers; i++) {
    compressionPeriodCount += totalCompressions[i];
    compressionPeriodsMissedCount += missedCompressions[i];
    clockmark_t *currCompTiming = compressionTimes[i];
    for (int j = 0; j < maxCompressionTimes; j++) {
      clockmark_t eachTimestamp = currCompTiming[j];
      if (eachTimestamp > 0) {
        allCompressionTimes.push_back(eachTimestamp);
      }
    }
    //delete compressionTimes[i];
  }
  //delete [] compressionTimes;
  delete [] totalCompressions;
  delete [] missedCompressions;

  clockmark_t *rawData = new clockmark_t[allCompressionTimes.size()];
  double *normalizedData = new double[allCompressionTimes.size()];
  for (int i = 0; i < allCompressionTimes.size(); i++) {
    rawData[i] = allCompressionTimes[i];
    normalizedData[i] = allCompressionTimes[i] / (compressionChunkSize*8192.0);
  }
  std::sort(rawData, rawData+allCompressionTimes.size());
  std::sort(normalizedData, normalizedData+allCompressionTimes.size());
  //printf("--COMP TIMING (avg of %lu)--\n", allCompressionTimes.size());
  print_csv_summary(rawData, allCompressionTimes.size(),"comp (raw)");
  //printf("*normalized*\n");
  print_csv_summaryDbl(normalizedData, allCompressionTimes.size(), "comp (us/byte)");
  delete [] rawData;
  delete [] normalizedData;

  printf("Total Execution Time: %lf\n", 1e-9 * totalTime);
  printf("Missed compression periods: %d\n", compressionPeriodsMissedCount);
  printf("Total compression periods hit: %d\n", compressionPeriodCount);

  return EXIT_SUCCESS;
}
