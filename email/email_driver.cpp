#include "email_protocol.h"
#include <algorithm>
#include <atomic>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
#include <thread>
#include <pthread.h> // barriers not in c++ standard yet
#include <cinttypes>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "../bench/include/common/ktiming.h"
#include "../bench/include/common/getoptions.h"

#include "error.h"

static int numberOfUsers = 180;
static int numberOfCommands = 5000;
static int messageSize = (8 * 1024);
static pthread_barrier_t connectBarrier;

static int         **timingOperations;
static clockmark_t **timingData;
static int         **sortSizes;
static clockmark_t **respTimes;
static std::atomic_int hasPrintedConnectionMessages;
static std::atomic_int numConnected;

int openConnection(const char *port) {
  int sockFd = 0;

	struct addrinfo hints;
	struct addrinfo *res;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo("127.0.0.1", port, &hints, &res);

	sockFd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	checkError(sockFd < 0, "Error opening socket: ");

  bool printConnectionMessages = !hasPrintedConnectionMessages.fetch_add(1);
	
	int ret = connect(sockFd, res->ai_addr, res->ai_addrlen);
  if (printConnectionMessages && ret == -1 && errno == ECONNREFUSED) printf("Waiting for server to start listening...\n");
  while (ret == -1 && errno == ECONNREFUSED) {
    usleep(50000);
    ret = connect(sockFd, res->ai_addr, res->ai_addrlen);
  }
	checkError(ret < 0, "Error connecting socket: ");

  int arrivalNumber = numConnected.fetch_add(1);
  if (arrivalNumber == 0) printf("First connected!\n");
  if (arrivalNumber == numberOfUsers-1) printf("Last one connected!\n");
  fflush(stdout);

  return sockFd;
}

void emailUserThread(int localId, std::string port) {
  int target = 0;
  uint32_t emailUserIdNo = 0;

  std::mt19937 generator(localId);
  std::uniform_int_distribution<int> commandDistribution(1, 100);
  std::uniform_int_distribution<int> userDistribution(0, numberOfUsers-2);
  std::uniform_int_distribution<int> sortDistribution(1, 6);
  std::uniform_int_distribution<int> emailNumberDistribution(0, numberOfUsers*numberOfCommands);
  emailCommand userCommand;
  userCommand.header.unused = 0;
  commandResponse appResponse;

  int sockFd = openConnection(port.c_str());

  readResponsePacket(sockFd, &appResponse);
  assert(appResponse.header.type == EMAIL_RESP_TYPE__CONNECT);
  assert(appResponse.header.length == sizeof(connectionResponse));
  emailUserIdNo = appResponse.connect.userId;

  strncpy(userCommand.send.msgBuffer, "userNumber1@cse.wustl.edu", MAX_MSG_LENGTH);
  strncpy(userCommand.send.msgBuffer+26, "subject number1", MAX_MSG_LENGTH-26);
  char *msgBegin = userCommand.send.msgBuffer+27+16;
  for (int i = 0; i < messageSize; i++) {
    msgBegin[i] = ' ' + (commandDistribution(generator)%('~'+1)); 
  }
  msgBegin[messageSize] = '\0';

  clockmark_t *myTimingData = new clockmark_t[numberOfCommands];
  clockmark_t *myRespTimes = new clockmark_t[numberOfCommands];
  int *myTimingOperations = new int[numberOfCommands];
  int *mySortSizes = new int[numberOfCommands];

  pthread_barrier_wait(&connectBarrier);

  for (int i = 0; i < numberOfCommands; i++) {
    myTimingOperations[i] = commandDistribution(generator);

    if (myTimingOperations[i] <= 40) myTimingOperations[i] = EMAIL_CMD_TYPE__SEND;
    else if (myTimingOperations[i] <= 65) myTimingOperations[i] = EMAIL_CMD_TYPE__SORT;
    else myTimingOperations[i] = EMAIL_CMD_TYPE__PRINT;

    if (myTimingOperations[i] == EMAIL_CMD_TYPE__SEND) {
      userCommand.header.type = EMAIL_CMD_TYPE__SEND;
      // TODO: Too many magic numbers
      userCommand.header.length = messageSize+1+26+16;

      target = userDistribution(generator);
      if (target >= emailUserIdNo) target++;

      // May truncate, but that is fine
      snprintf(userCommand.send.msgBuffer, 26, "userNumber%d@cse.wustl.edu", target);
      snprintf(userCommand.send.msgBuffer+27, 16, "%dth subject subject subject subject", i+4);

      // Technically, we should create a new message;
      // However, that is not necessary. All other
      // packets in the union are too small to overwrite
      // the original random message.

    } else if (myTimingOperations[i] == EMAIL_CMD_TYPE__PRINT) {
      userCommand.header.type = EMAIL_CMD_TYPE__PRINT;
      userCommand.header.length = sizeof(userCommand.print);
      userCommand.print.emailPrintId = emailNumberDistribution(generator);
    } else if (myTimingOperations[i] == EMAIL_CMD_TYPE__SORT) {
      userCommand.header.type = EMAIL_CMD_TYPE__SORT;
      userCommand.header.length = sizeof(userCommand.sort);
      userCommand.sort.sortFieldId = sortDistribution(generator) - 3;
      if (userCommand.sort.sortFieldId <= 0) userCommand.sort.sortFieldId--;
    }

    __sync_synchronize();
    myTimingData[i] = ktiming_getmark();
    writePacket(sockFd, &userCommand.header);
    readResponsePacket(sockFd, &appResponse);
    //myTimingData[i] = ktiming_diff_usec(myTimingData[i], ktiming_getmark());
    myRespTimes[i] = respGetTimestamp(&appResponse) - myTimingData[i];
    myTimingData[i] = ktiming_getmark() - myTimingData[i]; // equivalent to ktiming_diff_usec
    __sync_synchronize();

    if (myTimingOperations[i] == EMAIL_CMD_TYPE__PRINT) {
      assert(appResponse.header.type == EMAIL_RESP_TYPE__PRINT);
      if (appResponse.header.length != sizeof(int64_t))  {
        //printf("%s", appResponse.print.rawMessage);
      } else {
        myTimingOperations[i] = -1;
        printf("Aborted Print!\n");
      }
    } else if (myTimingOperations[i] == EMAIL_CMD_TYPE__SORT) {
      assert(appResponse.header.type == EMAIL_RESP_TYPE__SORT);
      if (appResponse.header.length != (sizeof(int64_t)+1)) {
        mySortSizes[i] = appResponse.header.length - sizeof(int64_t); // remove the size of the timestamp
        //printf("%s", appResponse.sort.sortedMessageSubjects);
      } else {
        myTimingOperations[i] = -1;
        //printf("Nothing to sort!\n");
      }
    } else if (myTimingOperations[i] == EMAIL_CMD_TYPE__SEND) {
      assert(appResponse.header.type == EMAIL_RESP_TYPE__SEND);
      if (appResponse.send.msgSent != 1) {
        myTimingOperations[i] = -1;
        printf("ERROR sending message!\n");
      } else {
        //printf("Sent message!\n");
      }
    }
  }

  userCommand.header.type = EMAIL_CMD_TYPE__QUIT;
  userCommand.header.length = 0;
  writePacket(sockFd, &userCommand.header);
  timingData[localId] = myTimingData;
  timingOperations[localId] = myTimingOperations;
  respTimes[localId] = myRespTimes;
  sortSizes[localId] = mySortSizes;
}

const char *specifiers[] = {"-clients", "-messages", "-port", 0};
int opt_types[] = {INTARG, INTARG, INTARG, 0};

int main(int argc, char *argv[]) {
  char port[1024];
  int portNo = 9001;

  get_options(argc, argv, specifiers, opt_types, &numberOfUsers, &numberOfCommands, &portNo);

  sprintf(port, "%d", portNo);

  hasPrintedConnectionMessages.store(0);
  numConnected.store(0);
  timingData = new clockmark_t*[numberOfUsers];
  respTimes = new clockmark_t*[numberOfUsers];
  timingOperations = new int*[numberOfUsers];
  sortSizes = new int*[numberOfUsers];
  pthread_barrier_init(&connectBarrier, NULL, numberOfUsers);
  std::thread allUserThreads[numberOfUsers];

  for (int i = 0; i < numberOfUsers; i++) {
    allUserThreads[i] = std::thread(emailUserThread, i, std::string(port));
  }
  for (int i = 0; i < numberOfUsers; i++) {
    allUserThreads[i].join();
  }

  clockmark_t* allRespTimes = new clockmark_t[numberOfUsers*numberOfCommands];

  int sendCount = 0;
  clockmark_t* sendTimingData = new clockmark_t[numberOfUsers*numberOfCommands];
  double* normalizedSendTimingData = new double[numberOfUsers*numberOfCommands];
  //clockmark_t* sendRespTimes = new clockmark_t[numberOfUsers*numberOfCommands];
  int sortCount = 0;
  clockmark_t* sortTimingData = new clockmark_t[numberOfUsers*numberOfCommands];
  //clockmark_t* sortRespTimes = new clockmark_t[numberOfUsers*numberOfCommands];
  double* normalizedSortTimingData = new double[numberOfUsers*numberOfCommands];
  int printCount = 0;
  clockmark_t* printTimingData = new clockmark_t[numberOfUsers*numberOfCommands];
  double* normalizedPrintTimingData = new double[numberOfUsers*numberOfCommands];
  //clockmark_t* printRespTimes = new clockmark_t[numberOfUsers*numberOfCommands];

  for (int i = 0; i < numberOfUsers; i++) {
    for (int j = 0; j < numberOfCommands; j++) {
      if (timingOperations[i][j] == EMAIL_CMD_TYPE__SEND) {
        sendTimingData[sendCount] = timingData[i][j];
        normalizedSendTimingData[sendCount] = timingData[i][j] / (messageSize + 26 + 16.0);
        //sendRespTimes[sendCount] = respTimes[i][j];
        sendCount++;
      } else if (timingOperations[i][j] == EMAIL_CMD_TYPE__SORT) {
        sortTimingData[sortCount] = timingData[i][j];
        //sortRespTimes[sortCount] = respTimes[i][j];
        // TODO: Adding 1 to be safe; I'm not 100% sure the null byte is being tagged on at the end.
        int nSorted = ((sortSizes[i][j]+1) / 16);
        if (sortSizes[i][j] < 15) printf("Size: %d\n", sortSizes[i][j]);
        assert(sortSizes[i][j] >= 15);
        normalizedSortTimingData[sortCount] = timingData[i][j] / (nSorted*1.0);
        sortCount++;
      } else if (timingOperations[i][j] == EMAIL_CMD_TYPE__PRINT) {
        assert(timingOperations[i][j] == EMAIL_CMD_TYPE__PRINT);
        printTimingData[printCount] = timingData[i][j];
        normalizedPrintTimingData[printCount] = timingData[i][j] / (messageSize + 26 + 16.0);
        //printRespTimes[printCount] = respTimes[i][j];
        printCount++;
      } else {
        // i.e., the op did not succeed
        assert(timingOperations[i][j] == -1);
      }
      allRespTimes[i*numberOfCommands + j] = respTimes[i][j];
    }
    delete [] timingOperations[i];
    delete [] timingData[i];
    delete [] respTimes[i];
  }

  delete [] timingOperations;
  delete [] timingData;
  delete [] respTimes;

  std::sort(allRespTimes, allRespTimes+(numberOfUsers*numberOfCommands));
  std::sort(sendTimingData, sendTimingData+sendCount);
  std::sort(normalizedSendTimingData, normalizedSendTimingData+sendCount);
  std::sort(sortTimingData, sortTimingData+sortCount);
  std::sort(normalizedSortTimingData, normalizedSortTimingData+sortCount);
  std::sort(printTimingData, printTimingData+printCount);
  std::sort(normalizedPrintTimingData, normalizedPrintTimingData+printCount);

  //printf("--SEND TIMING (avg of %d)--\n", sendCount);
  //printf("*Total Time*\n");
  print_csv_summary(sendTimingData, sendCount, "send (raw us)");
  //printf("*normalized*\n");
  //print_runtime_summary(normalizedSendTimingData, sendCount);
  print_csv_summaryDbl(normalizedSendTimingData, sendCount,"send (us/byte)");
  //printf("*Resp Time*\n");
  //print_runtime_summary(sendRespTimes, sendCount);
  //printf("--SORT TIMING (avg of %d)--\n", sortCount);
  //printf("*Total Time*\n");
  print_csv_summary(sortTimingData, sortCount, "sort (raw us)");
  //printf("*normalized*\n");
  //print_runtime_summary(normalizedSortTimingData, sortCount);
  print_csv_summaryDbl(normalizedSortTimingData, sortCount, "sort (us/msg)");
  //printf("--PRNT TIMING (avg of %d)--\n", printCount);
  //printf("*Total Time*\n");
  print_csv_summary(printTimingData, printCount,"print (raw us)");
  //printf("*normalized*\n");
  //print_runtime_summary(normalizedPrintTimingData, sendCount);
  print_csv_summaryDbl(normalizedPrintTimingData, printCount, "print (us/byte)");
 // printf("*Resp Time*\n");
  //print_runtime_summary(printRespTimes, printCount);
  print_csv_summary(allRespTimes, numberOfUsers*numberOfCommands, "resp (us)");

  delete [] sendTimingData;
  delete [] sortTimingData;
  delete [] printTimingData;
  delete [] allRespTimes;

  return EXIT_SUCCESS;
}
