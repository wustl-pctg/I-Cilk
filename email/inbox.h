#pragma once

#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#ifdef NO_PRIO
  #include "noprio_macros.h"
#else
  #include <cilk/cilk_priority.h>
#endif

#include "email_priorities.h"
#include "email_cilksort.h"
#include "email_protocol.h"
#include "huffman.h"

class email {
  private:
    std::string from;
    std::string to;
    std::string subject;
    // Use a vector<uint8_t> instead of a string
    // in order to allow for local storage of the
    // compressed message
    std::vector<uint8_t> msg;
    std::chrono::system_clock::time_point date;
    int emailId;
    // TODO: Implement a "compression group" so that
    //       we can sort in place

  public:
    email(std::string from, std::string &to, std::string &subject, std::string &msg) { 
      this->date = std::chrono::system_clock::now();

      this->from = std::string(from);
      this->to = std::string(to);
      this->subject = std::string(subject);
      // Make sure to copy the NULL byte! This is needed in compress/decompress
      this->msg = std::vector<uint8_t>((uint8_t*)msg.c_str(), (uint8_t*)msg.c_str()+msg.size()+1);
    }


    ~email() { }

    email* msgFreeCopy() {
      std::string msg = std::string();
      email *copy = new email(this->from, this->to, this->subject, msg);
      return copy;
    }

    std::vector<uint8_t>* getMsg() {
      return &this->msg;
    }

    void setId(int id) {
      this->emailId = id;
    }

    int compareByField(const email *const other, int fieldId) {
      int absFieldId = std::abs(fieldId);
      int reverseOrderMultiplier = (fieldId < 0 ? -1 : 1);

      if (absFieldId == FIELD_ID__FROM) {
        return reverseOrderMultiplier * this->from.compare(other->from);
      } else if (absFieldId == FIELD_ID__SUBJECT) {
        return reverseOrderMultiplier * this->subject.compare(other->subject);
      } else if (absFieldId == FIELD_ID__DATE) {
        if (this->date < other->date) {
          return reverseOrderMultiplier * (-1);
        } else if (this->date > other->date) {
          return reverseOrderMultiplier * 1;
        } else {
          // Unecessary multiplication; just being consistent
          return reverseOrderMultiplier * 0;
        }
      }

      printf("Invalid field id: %d\n", fieldId);
      assert(!"Invalid Sort Field ID!");
    }

    void print(std::ostream &out) {
      auto tmpTime = std::chrono::system_clock::to_time_t(this->date);
      std::string dateString = std::ctime(&tmpTime);
      out << "Message ID: " << this->emailId << std::endl
          << "From: " << this->from << std::endl
          << "To: " << this->to << std::endl
          << "Date: " << dateString // date already has a newline
          << "Subject: " << this->subject << std::endl
          << (char*)this->msg.data() << std::endl;
    }

    void printSubject(std::ostream &out) {
      out << this->subject;
    }
};

#define COMPRESS__ABORT ((uintptr_t) -1)

class inbox {
  private:
    int maxMessages;
    int compressionChunkSize;
    void **compressionDictionary;
    std::atomic_int msgCount;
    std::atomic<email*> *messages;
    std::atomic<cilk::pfuture<int, PrintOrCompressP>*> *compressionStates;
    std::string username;

  public:
    inbox(int maxMessages, int compressionChunkSize, int slim = 0) {
      this->username = std::string("ERROR");
      this->maxMessages = maxMessages;
      this->compressionChunkSize = compressionChunkSize;
      msgCount.store(0, std::memory_order_seq_cst);
      //messages = new std::atomic<email*>[maxMessages];
      //for (int i = 0; i < maxMessages; i++) {
      //  std::atomic_init(&messages[i], (email*)NULL);
      //}
      messages = (std::atomic<email*> *) calloc(maxMessages, sizeof(std::atomic<email*>));
      if (!slim) {
        this->compressionDictionary = (void**) calloc(maxMessages / compressionChunkSize + 1, sizeof(void*));
        this->compressionStates = new std::atomic<cilk::pfuture<int, PrintOrCompressP>*>[maxMessages / compressionChunkSize];
        for (int i = 0; i < this->maxMessages / this->compressionChunkSize; i++) {
          this->compressionStates->store(0);
        }
      }
    }

    ~inbox() {
      for (int i = 0; i < msgCount.load(); ++i) {
        delete messages[i].load();
      }

      /*for (int i = 0; i < msgCount.load() / compressionChunkSize; i++) {
        if (compressionStates[i]) {
          delete compressionStates[i];
        }
      }*/
      free(messages);
    }

    std::string getUsername() {
      return this->username;
    }

    void setUsername(std::string&& name) {
      this->username = name;
    }

    std::atomic<cilk::pfuture<int, PrintOrCompressP>*>* getCompressionStates() {
      return compressionStates;
    }

    inbox* copy() {
      int n = this->msgCount.load();
      inbox *theCopy = new inbox(n, this->compressionChunkSize);
      theCopy->msgCount.store(n);
      
      for (int i = 0; i < n; i++) {
        theCopy->messages[i] = this->messages[i].load()->msgFreeCopy();
      }
      return theCopy;
    }

    int getMsgCount() {
      return msgCount.load();
    }

    void addEmail(email *mail) {
      email *expected = NULL;
      int idx = msgCount.load(std::memory_order_seq_cst);
      do {
        mail->setId(idx);
        // Not sure why, but the compxchg appears to spuriously fail on our machine
        while (messages[idx] == NULL) messages[idx].compare_exchange_strong(expected, mail);
      } while(idx < maxMessages && messages[idx++].load() != mail);

      if (idx < maxMessages) {
        msgCount.fetch_add(1, std::memory_order_seq_cst);
      } else {
        printf("ERROR: Mailbox full!\n"); fflush(stdout);
      }
    }

    void printEmail(std::ostream& out, int which) {
      if (which < msgCount.load(std::memory_order_seq_cst)) {
        messages[which].load()->print(out);
      } else {
        //printf("Email %d does not exist for user %s!\n", which, this->username.c_str());
      }
    }

    void printSubjects(std::ostream& out) {
      for (int i = 0; i < msgCount.load(); i++) {
        messages[i].load()->printSubject(out);
        out << '\n';
      }
    }

    inline int emailIdToContainingChunk(int emailId) {
      return emailId / compressionChunkSize;
    }

    cilk::pfuture<int, PrintOrCompressP>* exchangeCompressionHandle(int firstMessageIdInChunk, cilk::pfuture<int, PrintOrCompressP> *newHandle) {
      int chunk = emailIdToContainingChunk(firstMessageIdInChunk);
      assert(chunk < maxMessages / compressionChunkSize);
      return compressionStates[chunk].exchange(newHandle);
    }

    void compressContainingChunk(int emailId) {
      int chunk = emailIdToContainingChunk(emailId);
      std::vector<uint8_t>* toCompress[compressionChunkSize];
      for (int i = 0; i < compressionChunkSize; i++) {
        toCompress[i] = messages[i+chunk*compressionChunkSize].load()->getMsg();
      }
      huffmanCompression(&compressionDictionary[chunk], toCompress, compressionChunkSize);
    }

    void decompressContainingChunk(int emailId) {
      int chunk = emailIdToContainingChunk(emailId);
      std::vector<uint8_t>* toCompress[compressionChunkSize];
      for (int i = 0; i < compressionChunkSize; i++) {
        toCompress[i] = messages[i+chunk*compressionChunkSize].load()->getMsg();
      }
      huffmanDecompression(&compressionDictionary[chunk], toCompress, compressionChunkSize);
    }

    void sortFirstNEmailsById(int n, int fieldId) {
      cilksort((email**)messages, n, fieldId); 
    }
};
