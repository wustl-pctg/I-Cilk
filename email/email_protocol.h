#pragma once

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#ifndef NO_CILK
  #include <cilk/cilk_io.h>
#else
  #include <unistd.h>
  #define cilk_read_sync(args...) read(args)
  #define cilk_write_sync(args...) write(args)
#endif

#include "error.h"

#define MAX_MSG_LENGTH (50 * 1024)

// TODO: An enum would probably be safer
#define EMAIL_CMD_TYPE__QUIT  (0)
#define EMAIL_CMD_TYPE__SEND  (1)
#define EMAIL_CMD_TYPE__SORT  (2)
#define EMAIL_CMD_TYPE__PRINT (3)

#define EMAIL_RESP_TYPE__CONNECT  (4)
#define EMAIL_RESP_TYPE__SEND     (5)
#define EMAIL_RESP_TYPE__SORT     (6)
#define EMAIL_RESP_TYPE__PRINT    (7)

#define FIELD_ID__FROM               (1)
#define FIELD_ID__DATE               (2)
#define FIELD_ID__SUBJECT            (3)

#define FIELD_ID__FROM_DESCENDING    (-(FIELD_ID__FROM))
#define FIELD_ID__DATE_DESCENDING    (-(FIELD_ID__FROM))
#define FIELD_ID__SUBJECT_DESCENDING (-(FIELD_ID__SUBJECT))

typedef struct PacketHeader {
  uint8_t type;
  uint8_t unused;
  uint16_t length;
} PacketHeader;

typedef struct sendCommand {
  char msgBuffer[MAX_MSG_LENGTH];
} sendCommand;

typedef struct sortCommand {
  int32_t sortFieldId;
} sortCommand;

typedef struct printCommand {
  uint32_t emailPrintId;
} printCommand;

typedef struct emailCommand {
  PacketHeader header;
  union {
    sendCommand send;
    sortCommand sort;
    printCommand print;
  };
} emailCommand;

// Response packets below

typedef struct connectionResponse {
  uint32_t userId;
} connectionResponse;

typedef struct sendResponse {
  int32_t msgSent;
} sendResponse;

typedef struct sortResponse {
  char sortedMessageSubjects[MAX_MSG_LENGTH];
} sortResponse;

typedef struct printResponse {
  char rawMessage[MAX_MSG_LENGTH];
} printResponse;

typedef struct commandResponse {
  PacketHeader header;
  union {
    connectionResponse connect;
    sendResponse send;
    sortResponse sort;
    printResponse print;
  };
} commandResponse;

static inline void respAddTimestamp(commandResponse *pkt, uint64_t &timestamp) {
  int64_t *dest = (int64_t*)(((uint8_t*)pkt) + sizeof(PacketHeader) + pkt->header.length);
  pkt->header.length += sizeof(timestamp);
  *dest = timestamp;
}

static inline int64_t respGetTimestamp(commandResponse *pkt) {
  int64_t *loc = (int64_t*)(((uint8_t*)pkt) + sizeof(PacketHeader) + pkt->header.length - sizeof(int64_t));
  return *loc;
}

static inline int readFullSize(int sourceFd, uint8_t *destination, int size) {
  int nRead = 0;
  int offset = 0;

  do {
    nRead = cilk_read_sync(sourceFd, destination + offset, size);
    if (nRead > 0) {
      offset += nRead;
      size -= nRead;
    }
  } while (nRead > 0 && size > 0);
  //checkError(nRead == -1, "Error in read: ");
  if (nRead > 0) {
    return offset;
  }
  if (nRead == 0) {
    printf("Why do you hate me?\n");
  }

  // Error
  return nRead;
}

static inline int readGenericPacket(int sourceFd, PacketHeader *input) {
  int ret = readFullSize(sourceFd, (uint8_t*)input, sizeof(PacketHeader));
  if (ret == sizeof(PacketHeader) && input->length > 0 && input->length < MAX_MSG_LENGTH) {
    ret = readFullSize(sourceFd, (uint8_t*)input+ret, input->length);
  } else if (input->length >= MAX_MSG_LENGTH) {
    ret = -1;
  }

  return ret;
}

static inline int readCommandPacket(int sourceFd, emailCommand *input) {
  return readGenericPacket(sourceFd, &input->header);
}

static inline void writePacket(int destFd, PacketHeader *output) {
  cilk_write_sync(destFd, output, sizeof(PacketHeader) + output->length);
}

static inline int readResponsePacket(int sourceFd, commandResponse *input) {
  return readGenericPacket(sourceFd, &input->header);
}

static inline void getSendParameters(emailCommand *input, char **to, char **subject, char **msg) {
  int maxStrLen = MAX_MSG_LENGTH;
  *to = input->send.msgBuffer;
  *subject = (*to)+strnlen(*to, maxStrLen)+1;
  maxStrLen -= (*subject) - (*to);
  *msg = (*subject)+strnlen(*subject, maxStrLen)+1;
  if ((*msg) - (*to) >= MAX_MSG_LENGTH) {
    fprintf(stderr, "ERR: Sent message too long!\n");
    exit(EXIT_FAILURE);
  }
}
