#include <cilk/cilk_priority.h>
#include <atomic>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <memory>

// NOTE: If you EVER want to spawn anything from a function,
//       every funtion between main and that function
//       MUST be defined using the CilkPrioCommandPrototype
//       and CilkPrioCommandDefine sequence of macros; otherwise
//       the compiler cannot track the priority and generate
//       compiler errors appropriately. In fact, attempting
//       to pspawn, command_run, or pfuture_create will generate
//       a compiler error.

// Alias DebitP for the lowest priority
typedef cilk::Low DebitP;
// Declare priority CreditP, higher priority than DebitP
CilkDeclareNewPriority(CreditP, DebitP);
// CreditP and QueryP are the same priority
typedef CreditP QueryP;
// LoopP is the highest priority
CilkDeclareNewPriority(LoopP, CreditP);

#define MAX_INPUT_SIZE (1024)

#define NUM_ACCOUNTS (10)

#define OVERDRAFT_FEE (20)

// Account balances
std::atomic_int accounts[NUM_ACCOUNTS];
std::shared_ptr<cilk::pfuture<void, DebitP>> debitFutures[NUM_ACCOUNTS] = {[0 ... NUM_ACCOUNTS-1] = NULL};
std::shared_ptr<cilk::pfuture<void, CreditP>> creditFutures[NUM_ACCOUNTS] = {[0 ... NUM_ACCOUNTS-1] = NULL};
std::shared_ptr<cilk::pfuture<void, QueryP>> queryFutures[NUM_ACCOUNTS] = {[0 ... NUM_ACCOUNTS-1] = NULL};

// You MUST use the CilkPrioCommandPrototype macro, followed by
// the CilkPrioCommandDefine macro in order to define a function
// that can spawn or be spawned

// The following is SIMILAR but not EQUIVALENT to:
//    std::string getInput(int);
CilkPrioCommandPrototype(std::string, getInput, int);
// The following is SIMILAR but NOT EQUIVALENT to:
//    std::string getInput(int fd) {
//      ... function body ...
//    }
CilkPrioCommandDefine(std::string, getInput, (int fd), {
  char buf[MAX_INPUT_SIZE];

  /** The following is how to handle it with I/O futures;
   ** however, we don't really need the future in this
   ** particular example.
   **/
  //cilk::pfuture<io_future_result, LoopP> readFut;
  //cilk_pread(&readFut, fd, buf, MAX_INPUT_SIZE);
  //io_future_result res = cilk_pfuture_get(&readFut);
  //if (res.ret_val < 0) {
  //  return std::string("ERROR");
  //} else {
  //  // strip the newline
  //  return std::string(buf, ret_val-1);
  //}
  
  // cilk_read_sync is more efficient than a
  // cilk_read/iosync pair since some steps inside
  // the runtime can be optimized since we don't need
  // to give a future handle to the user;
  // cilk_read_sync will return the appropriate ret_val
  // and set the errno value appropriately
  int ret_val = cilk_read_sync(fd, buf, MAX_INPUT_SIZE);
  if (ret_val <= 0) {
    return std::string("ERROR");
  } else {
    // strip the newline; the read result
    // is also not NULL terminated, so we
    // should pass in the string size
    return std::string(buf, ret_val-1);
  }
}
);

// The CilkPrioWrapTemplate macro should be used around any templates passed in to a CilkPrioCommandPrototype
// or CilkPrioCommandDefine macro, since otherwise commas within template parameters will cause problems with
// their macro expansion
CilkPrioCommandPrototype(void, Credit, CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, CreditP>>), int, int);
CilkPrioCommandDefine(void, Credit, (CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, CreditP>> curr), int acctNo, int value), {
  std::shared_ptr<cilk::pfuture<void, CreditP>> prev = creditFutures[acctNo];
  creditFutures[acctNo] = curr;
  if (prev != NULL) {
    // You MUST only get futures by using cilk_pfuture_get
    cilk_pfuture_get(prev);
  }
  __sync_synchronize(); // memory fence
  accounts[acctNo].fetch_add(value, std::memory_order_seq_cst);
}
);

CilkPrioCommandPrototype(void, waitForCredit, CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, CreditP>>), CilkPrioWrapTemplate(cilk::pfuture<void, cilk::Low> *));
CilkPrioCommandDefine(void, waitForCredit, (CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, CreditP>> credit), CilkPrioWrapTemplate(cilk::pfuture<void, cilk::Low> *prevWait)), {
  if (credit) cilk_pfuture_get(credit);
  if (prevWait) cilk_pfuture_get(prevWait);
}
);

CilkPrioCommandPrototype(void, Debit, CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, DebitP>>), int, int);
CilkPrioCommandDefine(void, Debit, (CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, DebitP>> curr), int acctNo, int value), {
  std::shared_ptr<cilk::pfuture<void, DebitP>> prev = debitFutures[acctNo];
  debitFutures[acctNo] = curr;
  if (prev != NULL) {
    // You MUST only get futures by using cilk_pfuture_get
    cilk_pfuture_get(prev);
  }
  std::shared_ptr<cilk::pfuture<void, CreditP>> prevCredit = creditFutures[acctNo];
  if (prevCredit != NULL) {
    // You MUST only get futures by using cilk_pfuture_get
    cilk_pfuture_get(prevCredit);
  }
  __sync_synchronize(); // memory fence
  int old_balance = accounts[acctNo].fetch_sub(value, std::memory_order_seq_cst);
  if (old_balance < value) {
    accounts[acctNo].fetch_sub(OVERDRAFT_FEE, std::memory_order_seq_cst);
    printf("Account %d has insufficient funds ($%d); charging overdraft fee of $%d\n", acctNo, old_balance, OVERDRAFT_FEE);
  }

}
);

CilkPrioCommandPrototype(void, waitForDebit, CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, DebitP>>), CilkPrioWrapTemplate(cilk::pfuture<void, cilk::Low> *));
CilkPrioCommandDefine(void, waitForDebit, (CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, DebitP>> debit), CilkPrioWrapTemplate(cilk::pfuture<void, cilk::Low> *prevWait)), {
  if (debit) cilk_pfuture_get(debit);
  if (prevWait) {
    cilk_pfuture_get(prevWait);
    delete prevWait;
  }
}
);

CilkPrioCommandPrototype(void, Query, CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, QueryP>>), int);
CilkPrioCommandDefine(void, Query, (CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, QueryP>> curr), int acctNo), {
  std::shared_ptr<cilk::pfuture<void, QueryP>> prev = queryFutures[acctNo];
  queryFutures[acctNo] = prev;
  if (prev != NULL) {
    // You MUST only get futures by using cilk_pfuture_get
    cilk_pfuture_get(prev);
  }
  __sync_synchronize(); // memory fence
  printf("Account %d contains: %d\n", acctNo, accounts[acctNo].load());
}
);

CilkPrioCommandPrototype(void, waitForQuery, CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, QueryP>>), CilkPrioWrapTemplate(cilk::pfuture<void, cilk::Low> *));
CilkPrioCommandDefine(void, waitForQuery, (CilkPrioWrapTemplate(std::shared_ptr<cilk::pfuture<void, QueryP>> query), CilkPrioWrapTemplate(cilk::pfuture<void, cilk::Low> *prevWait)), {
  if (query) cilk_pfuture_get(query);
  if (prevWait) cilk_pfuture_get(prevWait);
}
);

CilkPrioCommandPrototype(CilkPrioWrapTemplate(cilk::pfuture<void, cilk::Low> *), loop);
CilkPrioCommandDefine(CilkPrioWrapTemplate(cilk::pfuture<void, cilk::Low> *), loop, (void), {
  std::string prefix;
  int acctNo;
  int value;
  cilk::pfuture<void, cilk::Low> *prev = NULL;
  cilk::pfuture<void, cilk::Low> *ret = NULL;
  while(1) {

    // In order to call one of the "functions" defined above, such as getInput,
    // you must use the cilk_run_command macro. Pass the "function" name, followed
    // by the arguments
    std::istringstream tokens(cilk_run_command(getInput, STDIN_FILENO));
    tokens >> prefix;

    prev = ret;
    
    if (prefix.compare("quit") == 0) {
      return ret;
    } else {
      tokens >> acctNo;

      // If the input was not an int, or the account number is invalid...
      // This is fine on quit, since we don't need any more input
      if (tokens.fail() || acctNo >= NUM_ACCOUNTS || acctNo < 0) {
        continue;
      }

      if (prefix.compare("query") == 0) {
          std::shared_ptr<cilk::pfuture<void, QueryP>> queryFut = std::make_shared<cilk::pfuture<void, QueryP>>();
          cilk_pfuture_create(queryFut.get(), Query, queryFut, acctNo);
          ret = new cilk::pfuture<void, cilk::Low>();
          cilk_pfuture_create(ret, waitForQuery, queryFut, prev);
      } else {

        tokens >> value;

        if (tokens.fail()) {
          continue;
        }

        if (prefix.compare("credit") == 0) {

          std::shared_ptr<cilk::pfuture<void, CreditP>> creditFut = std::make_shared<cilk::pfuture<void, CreditP>>();
          // You MUST start futures using cilk_pfuture_create
          cilk_pfuture_create(creditFut.get(), Credit, creditFut, acctNo, value);
          //ret = new cilk::pfuture<void, cilk::Low>();
          //cilk_pfuture_create(ret, syncWithCredit, prev, creditFut);
          ret = new cilk::pfuture<void, cilk::Low>();
          cilk_pfuture_create(ret, waitForCredit, creditFut, prev);

        } else if (prefix.compare("debit") == 0) {

          std::shared_ptr<cilk::pfuture<void, DebitP>> debitFut = std::make_shared<cilk::pfuture<void, DebitP>>();
          cilk_pfuture_create(debitFut.get(), Debit, debitFut, acctNo, value);
          ret = new cilk::pfuture<void, cilk::Low>();
          cilk_pfuture_create(ret, waitForDebit, debitFut, prev);
        }
      }
    }
  } 
  return ret;
}
);

CilkPrioCommandPrototype(void, StartLoop);
CilkPrioCommandDefine(void, StartLoop, (void), {
  cilk::pfuture<cilk::pfuture<void, cilk::Low>*, LoopP> *fut = new cilk::pfuture<cilk::pfuture<void, cilk::Low>*, LoopP>();
  cilk_pfuture_create(fut, loop);
  cilk::pfuture<void, cilk::Low> *chainedWait = cilk_pfuture_get(fut);
  if (chainedWait) cilk_pfuture_get(chainedWait);
  //return fut;
}
);

int main(int nargs, char *args[]) {
  memset(accounts, 0, sizeof(accounts[0]) * NUM_ACCOUNTS);

  // cilk_paccept or cilk_accept_sync could be used
  // for getting the transactions over the network;
  // this is really more of just an example though
  int saved_flags = fcntl(STDIN_FILENO, F_GETFL);
  fcntl(STDIN_FILENO, F_SETFL, saved_flags | O_NONBLOCK);

  cilk_run_command(StartLoop);
  //cilk_pfuture_get(fut);

  // The following would create a future directly calling
  // the loop "function":
  // cilk::pfuture<void, LoopP> loopFut;
  // cilk_pfuture_create(&loopFut, loop);
  // cilk_pfuture_get(&loopFut);
  // Alternatively, this could be achieved with pspawn:
  // cilk_enable_spawn_in_this_func(); // necessary to allow spawning
  // cilk_pspawn_void(LoopP, loop);
  // cilk_psync;
  //
  // For spawning with return values:
  // what was "int val = cilk_spawn func(args...);"
  // is now "int val = 0; cilk_pspawn(LoopP, &val, func, args...);"
  // Don't forget cilk_enable_spawn_in_this_func()!!!!

  return 0;
}
