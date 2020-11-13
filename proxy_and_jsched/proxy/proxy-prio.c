#include <cilk/cilk_priority.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timerfd.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <netdb.h>
#include <sys/un.h>
#include <fcntl.h>
#include "../utils/util.h"
#include "../utils/arg.h"
#include "../utils/timing.h"
#include "../utils/ktiming.h"

/* runtime data config options */
//#define UTIL_RESET //turn on to reset utils on first hit of con 0

/* proxy config options */
//#define FUT_HIT_WB //turn on to enable 5 priorities (seperate prio for future write back)
#define PRIO //ALWAYS KEEP ON!
#define REAL_IO //turn on to enable real IO (actually read content from web/disk after opening connection/fd)
//#define USE_WEB //turn on to get web data from web
#define USE_DISK //turn on to get web data from disk
#define USE_DISK_TIMERFD //turn on to get web data from disk with timerfd for IO
//DONT USE DISK AND WEB AT THE SAME TIME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/* config end */
#define FIRST_HIT 2


#ifdef UTIL_RESET
extern void reset_overall_util_tracking();
int did_reset = 0;
#endif


const char* SITE_PATH = "pldi-websites";
//const char* SITE_PATH = "/project/adams/home/goldstein.n/spaa20-websites";
#define HTTP_PREFIX_OFFSET 4
#define HTTP_POSTFIX_OFFSET 3
#define FULL_OFFSET (HTTP_PREFIX_OFFSET+HTTP_POSTFIX_OFFSET)




#define ssize 32 //string size of vector size
#define vsize 2 //amount of times you want to try and hash
#define initSize (1<<14) //starting table size

#define BUFSIZE 64 //a reasonable size of most buffers
#define MAX_OBJECT_SIZE (1<<20) //max size of a sites info to be added to cache
#define MAX_INC 1024 //max amount of clients that can connect

#define SOCK_PATH "./sock" //sock path if local socket is specified

#define max_tables 64 //max tables to create

//return values for checking table.  Returned by lookupQuery
#define notIn -3 
#define in -1
#define unk -2


//return values to driver
#define PROXY_TIMEOUT 5
#define PROXY_ERROR 4
#define PROXY_MISS 3
#define PROXY_HIT 2

#define TIMEOUT_ERROR -2
#define OTHER_ERROR -1
#define SUCCESS 0


#define REQUEST_TIMEOUT_MS 2500
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))

//simplify socket syntax
typedef struct sockaddr SA; 
typedef void handler_t(int);


//priorities: StatP(background task)<ResizeP(resize table)<WebP(get site)<HitP_WB(write back from hits)<LoopP(loop handling requests)==IOP(IO priority)

#ifdef PRIO
CilkDeclareNewPriority(StatP, cilk::Low);
CilkDeclareNewPriority(ResizeP, StatP);
CilkDeclareNewPriority(WebP, ResizeP);
#ifdef FUT_HIT_WB
CilkDeclareNewPriority(HitP_WB, WebP);
CilkDeclareNewPriority(LoopP, HitP_WB);
#else
CilkDeclareNewPriority(LoopP, WebP);
#endif
typedef LoopP IOP;
typedef WebP DiskP;
#endif
#ifdef PRIO_NONE
typedef cilk::Low StatP;
typedef cilk::Low ResizeP;
typedef cilk::Low WebP;
typedef cilk::Low HitP_WB;
typedef cilk::Low LoopP;
typedef cilk::Low IOP;
typedef cilk::Low DiskP;
#endif
#ifdef PRIO_TEST
CilkDeclareNewPriority(StatP, cilk::Low);
CilkDeclareNewPriority(ResizeP, StatP);
CilkDeclareNewPriority(WebP, ResizeP);
CilkDeclareNewPriority(LoopP, WebP);
typedef LoopP IOP;
typedef WebP DiskP;
typedef WebP HitP_WB;
/*typedef cilk::Low StatP;
  CilkDeclareNewPriority(TestP, cilk::Low);
  typedef TestP ResizeP;
  typedef TestP WebP;
  typedef cilk::Low HitP_WB;
  typedef cilk::Low LoopP;
  //CilkDeclareNewPriority(HitP_WB, cilk::Low);
  //CilkDeclareNewPriority(LoopP, HitP_WB);
  typedef LoopP IOP;
  typedef WebP DiskP;*/
#endif



typedef struct resp{
  unsigned int len;
  unsigned int result;
  struct timespec lat;
}resp;
#define lat_offset 8

//struct for holding a parsed request
typedef struct reqNode{
  char buf[BUFSIZE];
  int cat_flag;
  struct reqNode* next;
  struct reqNode* prev;


} reqNode_t;


//head struct for parsed requests
typedef struct reqHead{
  int size; 
  struct reqNode* head;
  struct reqNode* tail;

} reqHead_t;


//a given cache block storing web info
typedef struct cacheBlock{

  //the tag for finding a block, in this lab, the tag
  //will be the URI from any given request
  char tag[BUFSIZE];

  //size to store the size of the buf so that it does not
  //need to be calculated each time it is needed
  unsigned long sizeBuf;
  volatile unsigned long hits;
  //buffer which actually holds the data that the server
  //would have sent back for the given request
  char* buf;

} cacheBlock;



extern int h_errno;    /* Defined by BIND for DNS errors */
extern char **environ; /* Defined by libc */

/* Misc constants */
#define	MAXLINE	 8192  /* Max text line length */
#define	READLINE 128  /* Max text line length */
#define LISTENQ  1024  /* Second argument to listen() */

//defines for returns from parsing a request
#define doWeb 1 
#define endLoop 2
#define doNothing 3

//struct to hold all strings relating to headers
typedef struct headerStruct{

  const char* connStatus;
  const char* proxStatus;
  char hostHeader[BUFSIZE];
  char UsrAgntHeader[BUFSIZE];
  char connHeader[BUFSIZE];
  char proxConnHeader[BUFSIZE];

} headerStruct;


//for storing sizes returned in server to client (just cleaner to pass as struct)
typedef struct sizesCache{
  ssize_t bytes;
  ssize_t check;
  ssize_t oldCheck;
} sizesCache;

//struct to hold strings relating to parsing 
typedef struct parseInfo{
  char hostname[BUFSIZE];
  char portNum[BUFSIZE];
  char path[BUFSIZE];
  char get[16]; 
  char method[16]; 
} parseInfo;


//a sub table in the Hashtable
typedef struct SubTable {
  volatile cacheBlock** InnerTable; //rows (table itself)
  int TableSize; //size
} SubTable;

// head of cache: this is the main hahstable
typedef struct HashTable{
  volatile SubTable** TableArray; //array of tables
  unsigned int ** seeds;
  volatile unsigned long copying;
  volatile unsigned long start;
  volatile unsigned long cur; //current max index (max exclusive)
  int hashAttempts;
  cilk::pfuture<int, ResizeP>* r_fut;
} HashTable;



int verbose=0; //verbose mode (bool)
char* portspec=NULL; //port to listen on
int real=0; //send back entire webpage data
int test=0; //send back result (hit,miss,error)


int* statSize=NULL; //size of cache when getting stats 
struct timespec* statStart=NULL; //start time of stat collection
struct timespec* statEnd=NULL; //end time of stat collection
const unsigned long nsMult = 1000*1000*1000;
int iss = 1024;
suseconds_t format_ts(struct timespec t);


//files to getting util/quantlen info
extern FILE* utilOutput;
extern bool closeUtilOutput;

//cilk variables
int cilk_quantum_length_us ;
double cilk_rho ;
double cilk_util_bound ;
double cilk_init_desire ;
int cilk_rr_worker_count ;
int cilk_reserved_w_per_lvl ;

int cons=0; //amount of connections to expect
int bgsec=0; //period of stat collection
int rseed=0; //seed for random number
int runNum=0;
#define Version "0.1"
static ArgOption args[] = {
  // Kind,        Type,   name,      reqd, variable,  help
  { KindOption,   Integer,"-v",         0, &verbose,                 "Turn on verbosity" },
  { KindOption,   Set,    "--test",     0, &test,                    "Send back hit/miss/error only" },
  { KindOption,   Set,    "--real",     0, &real,                    "Send back all data" },
  { KindOption,   String, "--port",     0, &portspec,                "Port to listen on" },
  { KindOption,   Integer,"--cons",     0, &cons,                    "Number of clients" },
  { KindOption,   Integer,"--rnum",     0, &runNum,                  "Run num (for data collect)" },
  { KindOption,   Integer,"--bgsec",    0, &bgsec,                   "Interval for stats collection task" },
  { KindOption,   Integer,"--seed",     0, &rseed,                   "Random number seed" },
  { KindOption,   Integer,"--quantlen", 0, &cilk_quantum_length_us,  "Set cilk quantum length in us" },
  { KindOption,   Double, "--cilkrho",  0, &cilk_rho,                "Set cilk rho value" },
  { KindOption,   Double, "--cilkutil", 0, &cilk_util_bound,         "Set cilk util bound" },
  { KindOption,   Double, "--cilkinit", 0, &cilk_init_desire,        "Set cilk initial desire" },
  { KindOption,   Integer,"--cilkWrks", 0, &cilk_rr_worker_count,    "Set cilk round robin worker count" },
  { KindOption,   Integer,"--cilkres",  0, &cilk_reserved_w_per_lvl, "Set cilk reserverd work per level" },
  { KindHelp,     Help,   "-h" },
  { KindEnd }
};
static ArgDefs argp = { args, "Proxy Priority", Version, NULL };
volatile unsigned long maxCon=0; //stores amount of connections currently active
volatile int end_stats=0; //bool to tell statcollection to stop
volatile struct HashTable* global=NULL; //hash table head




volatile  SubTable*
createTable(volatile HashTable* head, int tsize); //create new subtable
volatile HashTable* initTable(volatile HashTable* head, int InitSize, int HashAttempts); //initialize the hashtable
int lookup(volatile HashTable* head,volatile  SubTable* ht, cacheBlock* ent, unsigned int s); //check subtable slot for entry match (inserting)
void 
freeTable(volatile SubTable* ht); //free a subtable
cacheBlock* checkTableQuery(volatile HashTable* head, char* tag); //checks if entry is in cache
int 
lookupQuery(volatile SubTable* ht, char* tag, unsigned int s); //check subtable slot for entry (querying)


cacheBlock* createBlock(char* buf, unsigned long sizeBuf,char* bufTag); //create a cacheblock
void freeBlock(cacheBlock* block); //free a cacheblock
unsigned int hashStr(char * str,  unsigned int * vec); //hash a string (url)
unsigned int * initVec(); //initialize vectors for hashing

int getType(reqHead_t* head,reqNode_t * parseReq, 
	    parseInfo* info, char* uri,
	    volatile int clientfd, volatile int conNum); //check if request is get or quit
int lowGetType(char* info); //debuging function for making sure a request is wellformed before adding to linked list
void printLL(reqHead_t* head, int direction, volatile int clientfd,volatile int conNum);  //print linked list of requests
void removeNode(reqHead_t* head,reqNode_t* node); //remove a node from the request linked list
void addNode(reqHead_t* head, char* info); //add node to request linked list
void printRequest(char * req); //print request (include \n\r stuff just for debugging)
int Open_listenfd(char *port); //listen wraper
int open_listenfd(char *port); //listen inner
handler_t *Signal(int signum, handler_t *handler); //establish custom sig handler
int open_clientfd(char *hostname, char *port); //establish a connection with a hostname/port
int open_clientfd_disk(char *hostname, int is_https); //establish a connection with a hostname/port 
suseconds_t difftimevals(struct timespec t1, struct timespec t2); //get diff time between two timevals (us)
suseconds_t to_usecs(struct timespec t); //convert timeval to us
void memCatMe(char* bufDest, char* bufSrc, 
	      ssize_t bufDestOffset, ssize_t bufSrcSize); //memcat that takes offsets
 
int parseURI(volatile int clientfd, char* uri, 
	     parseInfo* info, char* request); //parse a URI (handles http, https) in request, path, hostname, etc..


//create headers to send to server (currently doesnt take custom headers so
//certain pages will not return there data and just return an error message
void createHeaders(parseInfo* info,headerStruct* headers);


 
int CASincr(cacheBlock* ent); //increment hits for a cacheblock



CilkPrioCommandPrototype(char*, webTransfer, int, int,char*, char*, parseInfo*, char*, struct timespec, cilk::pfuture<char*,  WebP>*); //get info from URL and send back to client
CilkPrioCommandPrototype(char*, diskTransfer, int, int,char*, char*, parseInfo*, char*, struct timespec, cacheBlock*, cilk::pfuture<char*,  DiskP>*); //get info from URL and send back to client
CilkPrioCommandPrototype(int, handleConnection, int,int); //handle a client wrapper
CilkPrioCommandPrototype(int, handleConnection_kernel, int,int,reqHead_t*); //handle a clients requests
CilkPrioCommandPrototype(int, getInitialRequest, int,char*,int,reqHead_t*, struct timespec*, int); //get a request from a client
CilkPrioCommandPrototype(int, sendHeader, int,int,char*); //send a given header to server
CilkPrioCommandPrototype(int, sendHeaders,  
			 int,int,char*, headerStruct, struct timespec); //send all headers to server
CilkPrioCommandPrototype(int, writeError, volatile int, struct timespec, int); //handle error (write back error to client)

CilkPrioCommandPrototype(int, serverToClient, 
			 int,int,char*,char*,sizesCache*,int, struct timespec); //read from URL server and write back to client
CilkPrioCommandPrototype(int, diskToClient, 
			 int,int,char*,char*,sizesCache*,int, struct timespec); //read from URL data from disk and write back to client

CilkPrioCommandPrototype(int, tryAndReadFromCache, int,char*,int, struct timespec, cacheBlock**); //check cache and if hit read back to client
#ifdef FUT_HIT_WB
CilkPrioCommandPrototype(void, cacheRespWriteBack, int, char*, int, struct timespec, cilk::pfuture<void, HitP_WB>*); //write back for cache hits
#endif
CilkPrioCommandPrototype(cacheBlock**, collectStats, int); //function called by doStats to actually collect
CilkPrioCommandPrototype(int, doStats, int); //background task to collect stats periodically
CilkPrioCommandPrototype(double, printTable, volatile HashTable*); //print cache
CilkPrioCommandPrototype(int, resize,volatile  HashTable*,volatile  SubTable*, cilk::pfuture<int, ResizeP>*); //moves items from small tables to larger ones in cache
CilkPrioCommandPrototype(int, insertTable,volatile  HashTable*, int, cacheBlock*); //insert a cacheblock into cache
CilkPrioCommandPrototype(int, letConnect, char*); //gets all the client connection and starts their handle connection
CilkPrioCommandPrototype(int, getAll, volatile int, int); //get all outstanding futures

CilkPrioCommandPrototype(int, addDrop, 
			 volatile HashTable*, volatile SubTable* , unsigned long, cacheBlock*,int);//create new subtable if cant find space
CilkPrioCommandPrototype(void, recursive, cacheBlock**, int, int); //sort function




cilk::pfuture<cacheBlock**, StatP>* s_fut; //future for do stats


//get whether a block has been resized
int getBool(volatile cacheBlock* ent){ 
  return ((unsigned long)ent)&1;
}

//get valid ptr
cacheBlock* getPtr(volatile cacheBlock* ent){
  unsigned long mask=1;
  return (cacheBlock*)(((unsigned long)ent)&(~mask));
}

//set ptr for resize 
void setPtr(volatile cacheBlock** ent){
  volatile cacheBlock* newEnt=(volatile cacheBlock*)((unsigned long)(*ent)|1);
  __atomic_store(ent, &newEnt, __ATOMIC_SEQ_CST);
}

#ifdef USE_WEB
cilk::pfuture<char*, WebP> **web_futs; //futures for web transfer
#endif //USE_WEB
#ifdef USE_DISK
cilk::pfuture<char*, DiskP> **disk_futs; //futures for web transfer
#endif //USE_DISK
#ifdef FUT_HIT_WB
cilk::pfuture<void, HitP_WB> **hit_wb_futs; //futures for cache writeback
#endif

//User-Agent-Header constant
const char *header_user_agent = "Mozilla/5.0"
  " (X11; Linux x86_64; rv:45.0)"
  " Gecko/20180601 Firefox/45.0";


int main(int argc, char** argv) {
  portspec=(char*)calloc(16, sizeof(char));
  strcpy(portspec,"6005");
  cilk_quantum_length_us = cilk_get_quantum_length_us();
  cilk_rho = cilk_get_rho();
  cilk_util_bound = cilk_get_util_bound();
  cilk_init_desire = cilk_get_initial_desire();
  cilk_rr_worker_count = cilk_get_round_robin_worker_count();
  cilk_reserved_w_per_lvl = cilk_get_reserved_workers_per_level();
  progname = argv[0];
  ArgParser* ap = createArgumentParser(&argp);
  int ok = parseArguments(ap, argc, argv);
  if (ok) {
    fprintf(stderr,"Error parsing arguments");
    return -1;
  } 
  
  cilk_set_quantum_length_us(cilk_quantum_length_us);
  cilk_set_rho(cilk_rho);
  cilk_set_util_bound(cilk_util_bound);
  cilk_set_initial_desire(cilk_init_desire);
  cilk_set_round_robin_worker_count(cilk_rr_worker_count);
  cilk_set_reserved_workers_per_level(cilk_reserved_w_per_lvl);
  if(verbose){
    printf("rho: %lf, ql: %d, ut: %lf\n",cilk_rho, cilk_quantum_length_us, cilk_util_bound);
  }
  

  if(real&&test){
    fprintf(stderr,"You cant specify both real and test!\n");
    return -1;
  }

  
  statSize=(int*)calloc(iss, sizeof(int));
  statStart=(struct timespec*)calloc(iss, sizeof(struct timespec));
  statEnd=(struct timespec*)calloc(iss, sizeof(struct timespec));

  fprintf(stdout,"----------------------------------------------------\n");
  fprintf(stdout,"Run: %d\n", runNum);
  for(int i =0;i<argc;i++){
    fprintf(stdout,"%s ", argv[i]);
  }
  fprintf(stdout,"items,time(us)\n");
  fprintf(stdout,"\n");
  fflush(stdout);
  
#ifdef FUT_HIT_WB
  hit_wb_futs=(cilk::pfuture<void, HitP_WB> **)calloc(MAX_INC, sizeof(cilk::pfuture<void, HitP_WB>*));
#endif
#ifdef USE_WEB
  web_futs=(cilk::pfuture<char*, WebP> **)calloc(MAX_INC, sizeof(cilk::pfuture<char*, WebP>*));
#endif //USE_WEB
#ifdef USE_DISK
  disk_futs=(cilk::pfuture<char*, DiskP> **)calloc(MAX_INC, sizeof(cilk::pfuture<char*, DiskP>*));
#endif //USE_DISK
  if(rseed){
    srand(rseed);
  }
  else{
    srand(time(NULL));
  }
  global=initTable(global, initSize, vsize);
  
  //redirect the sigpipe signal
  signal(SIGPIPE, SIG_IGN);
  cilk_enable_diff_prio_spawn_in_this_func(); 
  int s_ret=0,c_ret=0;
  cilk_pspawn(StatP,&s_ret,doStats, 1);
  cilk_pspawn(LoopP,&c_ret, letConnect, portspec);
  cilk_psync;
  unsigned long* ulr=(unsigned long*)statStart, *ulw=(unsigned long*)statEnd;
  unsigned long* statTimes = (unsigned long*)calloc(iss, sizeof(unsigned long));
  int stat_count=0;
  while(ulr[(stat_count<<1)]&&
	ulr[(stat_count<<1)+1]&&
	ulw[(stat_count<<1)]&&
	ulw[(stat_count<<1)+1]&&
	stat_count<iss){
    statTimes[stat_count] = difftimevals(statEnd[stat_count], statStart[stat_count]);
    stat_count++;
  }

  char buf[256] = "";
  printf("Event, Avg(us), Max(us), Min(us), Stdev(us), Stdev(%%), 50%%(us), 90%%(us), 95%%(us), 99%%(us)\n");
  //  printf("--Stat Timing (avg of %d)--\n", stat_count);
  sprintf(buf, "Stat Timing (avg of %d)", stat_count);
  //  print_runtime_summary(statTimes, stat_count);
  print_csv(statTimes, stat_count, buf);
  double* stats_dbl=(double*)calloc(sizeof(double), stat_count);
  for(int i=0;i<stat_count;i++){
    if(statSize[i]){
      stats_dbl[i]=((double)statTimes[i])/statSize[i];
    }
  }
  //  printf("--Stat Timing (avg of %d)-- [NORMALIZED]\n", stat_count);
  sprintf(buf, "Stat Timing (avg of %d) [NORMALIZED]", stat_count);
  //  print_runtime_summaryDbl(stats_dbl, stat_count);
  print_csvDbl(stats_dbl, stat_count, buf);
  fflush(stdout);
  return 0;
}


//accept client connections and spawn func to handle them
//port: port to listen on
CilkPrioCommandDefine(int, letConnect, (char* port), {
    int listenfd, clientfd; //file descriptors for use in creating connections
    socklen_t clientlen; //variable for socket IO
    struct sockaddr_storage clientaddr; //struct for socket IO
    volatile int conNum=0;
    cilk_enable_diff_prio_spawn_in_this_func();

    //specify l for port for local socket (between client and server)
    listenfd=Open_listenfd(port);
    int old_flags=fcntl(listenfd, F_GETFL,0);
    if(fcntl(listenfd, F_SETFL, old_flags|O_NONBLOCK)<0){
      fprintf(stderr,"Error setting client fd\n");
      fprintf(stderr,"%s\n", strerror(errno));
      fprintf(stdout,"Error setting client fd\n");
      fprintf(stdout,"%s\n", strerror(errno));
      fflush(stdout);
      return 0;
    }


    //loop which will continue running until program halted, 
    //this will create threads which will handle each new client which comes
    while(cons>maxCon){
      clientlen=sizeof(struct sockaddr_storage);
      //start cilk_accept_syncing connections from clients

      if((clientfd=cilk_accept_sync(listenfd, (SA*) &clientaddr, &clientlen))<0){    
	fprintf(stderr,"server is not able to connect to clients\n");
	fprintf(stderr, "%s\n",strerror(errno));
	fprintf(stdout,"server is not able to connect to clients\n");
	fprintf(stdout, "%s\n",strerror(errno));
	fflush(stdout);
	return 0;
      }

      old_flags=fcntl(clientfd, F_GETFL,0);
      if(fcntl(clientfd, F_SETFL, old_flags|O_NONBLOCK)<0){
	fprintf(stderr,"Error setting client fd\n");
	fprintf(stderr,"%s\n", strerror(errno));
	fprintf(stdout,"Error setting client fd\n");
	fprintf(stdout,"%s\n", strerror(errno));
	fflush(stdout);
	return 0;
      }
      __atomic_add_fetch(&conNum,1,__ATOMIC_RELAXED);
      
      __atomic_add_fetch(&maxCon, 1, __ATOMIC_RELAXED);
      if(verbose){
	fprintf(stderr,"client %d connected on fd: %d!\n",conNum, clientfd);
	fprintf(stdout,"client %d connected on fd: %d!\n",conNum, clientfd);
	fflush(stdout);
      }
      int h_ret=0;
      cilk_pspawn(LoopP,&h_ret,handleConnection,clientfd, conNum);

    }
    cilk_psync;
    return 0;

  });

#ifdef FUT_HIT_WB
//send back cache hit data at lower priority that lookup
//clientfd: client to write to
//conNum: connection number of the client
//cacheResponse: data to write back
//returnSize: sizeof data to write back (real only)
//recTime: latency time
//h: previous cacheResp future (for getting basically)
CilkPrioCommandDefine(void, cacheRespWriteBack, (volatile int clientfd, char* cacheResponse, int returnSize, struct timespec recTime, cilk::pfuture<void, HitP_WB>* h), {
    if(h){
      cilk_pfuture_get(h);
    }
    if(real){
      resp server_resp = ((resp*)cacheResponse)[0];
      if(verbose>1){
	fprintf(stderr,"Sending back[Cache]: %d { %u , %u==%u , %lu }\n",
		  
		clientfd,
		server_resp.len,
		server_resp.result,
		PROXY_HIT,
		format_ts(server_resp.lat));
      }
      server_resp.lat = recTime;
      int ret_val= cilk_write_sync(clientfd, &server_resp, sizeof(resp));
      if(ret_val==-1){
	fprintf(stderr, "Issue writing cached file to client\n");
	return;

      }
      ret_val= cilk_write_sync(clientfd, cacheResponse+sizeof(resp), returnSize-sizeof(resp));
      if(ret_val==-1){
	fprintf(stderr, "Issue writing cached file to client\n");
	return;
      }
    }
    else if(test){
      resp server_resp;
      server_resp.lat = recTime;
      server_resp.len = sizeof(resp);
      server_resp.result = PROXY_HIT;
      if(verbose>1){
	fprintf(stderr,"Sending back[Cache]: %d -> { %u , %u==%u , %lu }\n",
		clientfd,
		server_resp.len,
		server_resp.result,
		PROXY_HIT,
		format_ts(server_resp.lat));
      }
	
      int ret_val= cilk_write_sync(clientfd, &server_resp, sizeof(resp));
      if(ret_val==-1){
	fprintf(stderr, "Issue writing cached file to client\n");
	return;
      }
    }
    return;
  });
#endif

//get data for URL and send back to client/add to cache
//actually makes a request as opposed to disk with takes data from
//prefetch sites at SITE_PATH
//clientfd: client to write to
//conNum: local conNum for client
//uri: uri to get info from
//request: full request (i.e path and stuff)
//info: grequest type/method
//bufForCache: buffer storing all data for the webpage
//h: previous call
CilkPrioCommandDefine(char*, webTransfer, (volatile int clientfd, volatile int conNum, char* uri, char* request, parseInfo* info,char* bufForCache, struct timespec recTime, cilk::pfuture<char*, WebP>* h), {

    //have to get at begining because errors all write back
    if(h){
      char* p_ret=cilk_pfuture_get(h);
      if(p_ret){
	free(p_ret);
      }
    }
    int serverfd=0;

    //initializing buffers for headers
    headerStruct headers;
    //constants for the connection headers sent to server
    headers.connStatus= "close";
    headers.proxStatus= "close";

    //cacheing variables
    sizesCache sizes={0, 0, 0};
    if(-1==parseURI(clientfd, uri, info, request)){
      cilk_run_command(writeError,clientfd, recTime, 0);
      return request;
    }
    //create headers to send
    createHeaders(info, &headers);
    //connect to webpage

    if((serverfd=open_clientfd(info->hostname,info->portNum))<0){
      fprintf(stderr,"cant connect to server: %s\n", info->hostname);
      fprintf(stderr,"%s\n", strerror(errno));
      cilk_run_command(writeError,clientfd, recTime, 0);
      return request;
    }
    int old_flags=fcntl(serverfd, F_GETFL,0);
    if(fcntl(serverfd, F_SETFL, old_flags|O_NONBLOCK)<0){
      fprintf(stderr,"Error setting server fd: %s\n", info->hostname);
      fprintf(stderr,"%s\n", strerror(errno));
      close(serverfd);
      cilk_run_command(writeError,clientfd, recTime, 0);
      return request;
    }
    //send headers to webpage

    int hres=cilk_run_command(sendHeaders,serverfd, clientfd,
			      request, headers, recTime);
    if(hres){
      close(serverfd);
      return request;
    }

    /*    
	  struct termios termios;
	  tcgetattr(serverfd, &termios);
	  termios.c_lflag &= ~ICANON;
	  termios.c_cc[VTIME] = 1; 
	  tcsetattr(serverfd, TCSANOW, &termios);
    */

    
    int ret = cilk_run_command(serverToClient,clientfd, serverfd,uri, bufForCache,&sizes,conNum, recTime);
    if(ret<SUCCESS){
      fprintf(stderr,"Error transmitting info from server to client for %s\n", uri);
      close(serverfd);
      cilk_run_command(writeError,clientfd, recTime, ret);
      return request;
    }
    close(serverfd);
    return request;
  });


//for simulating IO based on file size
#define BYTES_PER_SEC (12800000)

//computes second portion of sleep time
//res: file size
unsigned long sleep_time_sec(int res){
  return res/(BYTES_PER_SEC);
}

//computes nanoseconds portion of sleep time
//res: file size
unsigned long sleep_time_ns(int res){
  res = res%(BYTES_PER_SEC);
  double perc = ((double)res)/(BYTES_PER_SEC);
  return (unsigned long)(perc*(1000*1000*1000));
}


//get data for URL and send back to client/add to cache
//reads data from disk at SITE_PATH
//clientfd: client to write to
//conNum: local conNum for client
//uri: uri to get info from
//request: full request (i.e path and stuff)
//info: grequest type/method
//bufForCache: buffer storing all data for the webpage
//h: previous call
CilkPrioCommandDefine(char*, diskTransfer, (volatile int clientfd, volatile int conNum, char* uri, char* request, parseInfo* info,char* bufForCache, struct timespec recTime, cacheBlock *first_hit, cilk::pfuture<char*, WebP>* h), {


    //have to get at begining because errors all write back
    if(h){
      char* p_ret=cilk_pfuture_get(h);
      if(p_ret){
	free(p_ret);
      }
    }
#ifdef USE_DISK_TIMERFD
    if(first_hit){
      int res = first_hit->sizeBuf;
      if(verbose > 0){
	fprintf(stderr,"Sending back fake miss: [%d][%d] (%lu, %lu)-> %s\n", conNum, res, sleep_time_sec(res), sleep_time_ns(res), uri);
      }
      int timerfd = timerfd_create(CLOCK_MONOTONIC,0);
      int old_flags=fcntl(timerfd, F_GETFL,0);
      if(fcntl(timerfd, F_SETFL, old_flags|O_NONBLOCK)<0){
	fprintf(stderr,"Error setting timer fd\n");
	fprintf(stderr,"%s\n", strerror(errno));
	cilk_run_command(writeError,clientfd, recTime, 0);
	close(timerfd);
	return request;
      }

      struct itimerspec timspec;
      memset(&timspec, 0, sizeof(timspec));
      struct timespec now;
      timspec.it_value.tv_sec = sleep_time_sec(res);
      timspec.it_value.tv_nsec =  sleep_time_ns(res);

      int ret = timerfd_settime(timerfd, 0, &timspec, 0);
      if(ret < 0){
	perror("timerfd_settime:");
	cilk_run_command(writeError,clientfd, recTime, 0);
	close(timerfd);
	return request;
      }
      uint64_t expirations = 0;

      if(verbose > 1){
	clock_gettime(CLOCK_MONOTONIC, &now);
	fprintf(stderr,"starting sleep[%d]: %lu\n", conNum, format_ts(now));
      }
      
      ret = cilk_read_sync(timerfd, (char*)&expirations, sizeof(expirations));
      if(ret != sizeof(uint64_t)){
	perror("read:");
	cilk_run_command(writeError,clientfd, recTime, 0);
	close(timerfd);
	return request;
      }
      if(verbose > 2){
	clock_gettime(CLOCK_MONOTONIC, &now);
	fprintf(stderr,"end sleep[%d]: %lu\n", conNum, format_ts(now));
      }
      //this is a great piece of useful code!
      char* bull_shit_buffer = (char*)calloc(res, sizeof(char));
      memcpy(bull_shit_buffer, first_hit->buf, res);
      free(bull_shit_buffer);
      resp server_resp;
      server_resp.len=sizeof(resp);
      server_resp.result=PROXY_MISS;
      server_resp.lat=recTime;
      int ret_val= cilk_write_sync(clientfd, (char*)(&server_resp), sizeof(resp));
      if(ret_val==-1){
	fprintf(stderr, "Issue writing server response to client\n");
	cilk_run_command(writeError,clientfd, recTime, 0);
	close(timerfd);
	return request;
      }
      close(timerfd);
      return request;
    }
    
    else{
#endif //USE_DISK_TIMERFD
    int serverfd=0;

    //cacheing variables
    sizesCache sizes={0, 0, 0};
    if(-1==parseURI(clientfd, uri, info, request)){
      cilk_run_command(writeError,clientfd, recTime, 0);
      return request;
    }

    if((serverfd=open_clientfd_disk(info->hostname, uri[HTTP_PREFIX_OFFSET] == 's'))<0){
      fprintf(stderr,"cant connect to server\n");
      fprintf(stderr,"%s\n", strerror(errno));
      cilk_run_command(writeError,clientfd, recTime, 0);
      return request;
    }

    int old_flags=fcntl(serverfd, F_GETFL,0);
    if(fcntl(serverfd, F_SETFL, old_flags|O_NONBLOCK)<0){
      fprintf(stderr,"Error setting server fd\n");
      fprintf(stderr,"%s\n", strerror(errno));
      close(serverfd);
      cilk_run_command(writeError,clientfd, recTime, 0);
      return request;
    }
    
    int ret = cilk_run_command(diskToClient,clientfd, serverfd,uri, bufForCache,&sizes,conNum, recTime);
    if(ret<SUCCESS){
      fprintf(stderr,"Error transmitting info from server to client for %s\n", uri);
      close(serverfd);
      cilk_run_command(writeError,clientfd, recTime, ret);
      return request;
    }
    close(serverfd);
    return request;

#ifdef USE_DISK_TIMERFD
    }
#endif
  });




//wrapper to handle connection for a client
//clientfd: clients filedescrptor
//conNumL clients local conNum
CilkPrioCommandDefine(int, handleConnection, (volatile int clientfd, volatile int conNum), {

    int return_val;
    reqHead_t *head=(reqHead_t*)calloc(1,sizeof(reqHead_t));
    head->size=0;
    head->tail=NULL;
    head->head=NULL;


    return_val=cilk_run_command(handleConnection_kernel,clientfd, conNum, head);
    if(return_val==endLoop){
      free(head);
      close(clientfd);
      int tempMC=__atomic_sub_fetch(&maxCon, 1, __ATOMIC_RELAXED);
      if(verbose){
	printf("quit num: %d\n", tempMC);
      }
      cilk::pfuture<int,cilk::Low>* gettemp= new cilk::pfuture<int,cilk::Low>();
      cilk_pfuture_create(gettemp, getAll, conNum, tempMC);
    }
  
    else if(return_val==-1){
      fprintf(stderr,"was an error\n");
    }
    return 0;
  });

//get all outstanding futures
//conNum: local version of conNum
//temp: amount of connections stil out
CilkPrioCommandDefine(int, getAll, (volatile int conNum, int temp), {
    if(!temp){
      if(global->r_fut){
	int ret=cilk_pfuture_get(global->r_fut);
	if(!ret){
	  printf("Error Resizing\n");
	}
      }
      end_stats=1;
    }
    return 0;
  });


//handles a clients connection (read requests/call appropriate functions
//clientfd: fd for client
//conNum: clients local conNum
//head: head of request LL
CilkPrioCommandDefine(int, handleConnection_kernel, (volatile int clientfd,volatile int conNum,reqHead_t* head), {

    char * initialRequest=(char*)malloc(READLINE+16);
    char* bufForCache=(char*)calloc(MAX_OBJECT_SIZE,sizeof(char));
    struct timespec recTime;
    int take_time = 1;
    //get initialRequest from client
    while(1){
      memset(initialRequest, 0, READLINE+16);
      if(cilk_run_command(getInitialRequest,
			  clientfd,
			  initialRequest,
			  conNum,
			  head,
			  &recTime,
			  take_time)==-1){
	return endLoop;
      }
      take_time = 0;
      while(head->head!=NULL&&(!head->head->cat_flag)){
	take_time = 1;
	char* mem_needed=(char*)calloc(BUFSIZE+BUFSIZE+sizeof(parseInfo),1);
	char* request=mem_needed;
	char* uri=mem_needed+BUFSIZE;
	parseInfo* info=(parseInfo*)(mem_needed+BUFSIZE+BUFSIZE);
	int initTest=getType(head, head->head, info, uri, clientfd, conNum);

	//webpage request
	if(initTest==doWeb){
	  cacheBlock* first_hit = NULL;
	  int res = cilk_run_command(tryAndReadFromCache,clientfd, uri, conNum, recTime, &first_hit);
	  if(res == -1){
	    free(request);
	  }
	  else{
#ifdef USE_WEB
	    cilk::pfuture<char*, WebP>* temp= new cilk::pfuture<char*, WebP>();
	    cilk_pfuture_create(temp, webTransfer,clientfd, conNum, uri, request, info,bufForCache, recTime ,web_futs[conNum]);
	    web_futs[conNum]=temp;
#endif //USE_WEB
#ifdef USE_DISK
	    cilk::pfuture<char*, DiskP>* temp= new cilk::pfuture<char*, DiskP>();
	    cilk_pfuture_create(temp, diskTransfer,clientfd, conNum, uri, request, info,bufForCache, recTime, first_hit ,disk_futs[conNum]);
	    disk_futs[conNum]=temp;
#endif //USE_DISK
	  }


	}
	//if client says quit end its connection
	else if(initTest==endLoop){
	  free(initialRequest);
	  return endLoop;
	}
      }
    }
    free(initialRequest);
    return 0;
  });


//better print function (includes stuff like /n that matter for web requests) (debuging)
//req: request to print
void printRequest(char* req){
  int index=0;
  while(req[index]){
    if(req[index]=='\n'){
      printf("\%c",req[index]);
    }
    else if(req[index]=='\r'){
      printf("\%c",req[index]);
    }
    else{
      printf("%c",req[index]);
    }
    index++;
  }


}


//takes the initial client request (initialRequest) and parses it with 
//sscanff into a uri, get, and method. Returns 1 if the request was a 
//get request (which is only request proxy handles) and 0 otherwise.
//clientfd: fd for client
//initialRequest: buf to read request into
//conNum: client local conNum
//head: head of LL
CilkPrioCommandDefine(int, getInitialRequest, (volatile int clientfd, char* initialRequest, volatile int conNum,reqHead_t* head, struct timespec* recTime, int take_time), {
    //reading first line of client request for server
    
    int ret_val=cilk_read_sync(clientfd, initialRequest,READLINE);
    if(take_time){
      clock_gettime(CLOCK_MONOTONIC, recTime);
    }
    if(ret_val==-1){
      fprintf(stderr,"failed on: %s\n", initialRequest);
      fprintf(stderr,"Error reading initial request\n");
      return -1;
    }
    

    if(ret_val){
      int cat_flag=0;
      if(initialRequest[0]=='\n'){
	if(head->tail){
	  head->tail->cat_flag=0;
	}
      }
      if(initialRequest[strlen(initialRequest)-1]!='\n'){
	cat_flag=1;
      }

      //parsing request basically create a new one at each new line
      char* parseReq;
      parseReq=strtok_r(initialRequest, "\n", &initialRequest);
  
      while(parseReq!=NULL){
	//adds to tail of LL
	addNode(head,(parseReq));
	parseReq=strtok_r(NULL, "\n", &initialRequest);
      }
      if(head->tail){
	head->tail->cat_flag=cat_flag;
      }
      return 0;
    }
    return 1;
  });


//basic test if its well formed request (debuging)
//info: request to test
int lowGetType(char* info){
  if(!strncmp(info,"quit",4)){
    return 0;
  }

  if(!strncmp(info,"GET",3)){
    return 0;
  }
  return 1;

}
    

//adds node to parsed request list
//head: head of LL
//info: request to add
void addNode(reqHead_t* head, char* info){

  if(head->head==NULL){
    reqNode_t* newNode=(reqNode_t*)calloc(1,sizeof(reqNode_t));
    newNode->cat_flag=0;
    strcpy(newNode->buf,info);
    head->head=newNode;
    head->tail=newNode;
    newNode->prev=NULL;
    newNode->next=NULL;
    head->size++;
  }
  else{
    if(head->head->cat_flag){
      strcat(head->head->buf, info);
      head->head->cat_flag=0;
    }


    else{
      reqNode_t* newNode=(reqNode_t*)calloc(1,sizeof(reqNode_t));
      newNode->cat_flag=0;
      strcpy(newNode->buf,info);
      newNode->next=NULL;
      newNode->prev=head->tail;
      head->tail->next=newNode;
      head->tail=newNode;
      head->size++;
    }
  }


}

//print request linked list (debugging really)
//head: head of ll to print
//direction: print forward or backward (1 is head to tail)
//clientfd: fd of the client
//conNum_l: connection number of the client whose LL in being printed
void printLL(reqHead_t* head, int direction, volatile int clientfd, volatile int conNum){
  if(direction){
    printf("----------forward start %d/%d----------\n", clientfd,conNum);
    reqNode_t* iter=head->head;

    int i=1;
    while(iter!=NULL){
      printf("%d: %s\n",i, iter->buf);
      i++;
      iter=iter->next;
    }
    printf("size=%d\n", head->size);
    printf("----------forward end %d/%d----------\n",clientfd, conNum);
  }
  else{
    printf("----------backward start----------\n");
    reqNode_t* iter=head->tail;

    int i=1;
    while(iter!=NULL){
      printf("%d: %s\n",i, iter->buf);
      i++;
      iter=iter->prev;
    }
    printf("size=%d\n", head->size);
    printf("----------backward end----------\n");
  }

}

//remove node from request linked list
//head: head of LL
//node: node to be removed
void removeNode(reqHead_t* head,reqNode_t* node){
  if(head->head==NULL){
    return;
  }
  if(node->prev==NULL&&node->next==NULL){
    head->head=NULL;
    head->tail=NULL;
  }
  else if(node->prev==NULL&&node->next!=NULL){
    head->head=node->next;
    head->head->prev=NULL;
  }
  else if(node->next==NULL&&node->prev!=NULL){
    node->prev->next=NULL;
    head->tail=node->prev;
  }
  else{
    node->prev->next=node->next;
    node->next->prev=node->prev;
  }
  free(node);
  head->size--;

}


//get what type of operation
//head: head of LL
//parseReq: request to parse
//info: set method/type
//uri: buf to store uri in
//clientfd: fd for client
//conNum: local conNum for client
int getType(reqHead_t* head,reqNode_t * parseReq,
	    parseInfo* info, char* uri,
	    volatile int clientfd, volatile int conNum){
  if(!strncmp(parseReq->buf,"quit",4)){
    if(verbose){
      printf("do quit -- %d\n", conNum);
    }
    removeNode(head,parseReq);
    return endLoop;
  }

  //checks if it is a get operation. Program will only process get requests
  if(!(strncmp(parseReq->buf,"GET http",8))){ 

    if(sscanf(parseReq->buf,"%s %s %s", info->get, uri, info->method)>1){
   
      strcpy(info->method,"HTTP/1.0\r\n");
      removeNode(head,parseReq);
      return doWeb;
    }
  }
  fprintf(stderr,"%d/%d --- no hits on %s\n", clientfd, conNum,parseReq->buf);
  removeNode(head,parseReq);
  return doNothing;

}



//turns timeval to us
//t: timeval struct to be converted
suseconds_t to_usecs(struct timespec t) {
  return (t.tv_sec * nsMult + t.tv_nsec) / 1000;
}

suseconds_t to_nsecs(struct timespec t) {
  return (t.tv_sec * nsMult + t.tv_nsec);
}
suseconds_t format_ts(struct timespec t) {
  return to_nsecs(t);
}
//return difference between to timeval structs in us
//t1: timeval to be subtracted from
//t2: timeval whose value with be subtracted from t1
suseconds_t difftimevals(struct timespec t1, struct timespec t2) {
  return (format_ts(t1) - format_ts(t2));
}


//pares uri, handles hostname included or not (defaults 80) and https/http
//basically dead code with current usage
//clientfd: fd for client
//uri: uri to be parsed
//info: method/type
//request: request to make and send to server
int parseURI(volatile int clientfd, char* uri, 
	     parseInfo* info, char* request){
   
  //scan the uri for hostname, port, and path then concatinate path for request
  if(sscanf(uri,"https://%[^:]:%[^/]%s",
	    info->hostname,info->portNum,info->path)>2){

    strcpy(info->method,"HTTP/1.1\r\n");
    sprintf(request, "%s %s %s",info->get, info->path, info->method);

  } 
  //if scan returns <=1, means port was not scanned so no port declared in 
  //which case default to port=80
  else if(sscanf(uri,"https://%[^/]%s", info->hostname, info->path)>1){
    strcpy(info->portNum,"80");
    strcpy(info->method,"HTTP/1.1\r\n");
    sprintf(request, "%s %s %s",info->get, info->path, info->method);

  }
  //parsing http (so both https:// and http:// work)
  else if(sscanf(uri,"http://%[^:]:%[^/]%s",
		 info->hostname,info->portNum,info->path)>2){
    strcpy(info->method,"HTTP/1.0\r\n");
    sprintf(request, "%s %s %s",info->get, info->path, info->method);

  } 
  //if scan returns <=1, means port was not scanned so no port declared in 
  //which case default to port=80
  else if(sscanf(uri,"http://%[^/]%s", info->hostname, info->path)>1){
    strcpy(info->portNum,"80");
    strcpy(info->method,"HTTP/1.0\r\n");
    sprintf(request, "%s %s %s",info->get, info->path, info->method);
   
  }
  else{
    fprintf(stderr,"error in parsing uri\n");
    return -1;

  }
  return 0;
}

//if error write back error to client
//clientfd: client to write to
CilkPrioCommandDefine(int, writeError,(volatile int clientfd, struct timespec recTime, int wb_error),{
    resp error_resp;
    error_resp.len=sizeof(resp);
    if(wb_error==TIMEOUT_ERROR){
      error_resp.result=PROXY_TIMEOUT;
    }
    else{
      error_resp.result=PROXY_ERROR;
    }
    error_resp.lat = recTime;
    fprintf(stderr,"Writing error back -> %d\n", clientfd);
    int ret_val= cilk_write_sync(clientfd, &error_resp, sizeof(resp));
    if(ret_val==-1){
      fprintf(stderr,"Error in writing error....\n");
      exit(0);
    }
    return 1;
  });

 
//helper function to send a given header to the server. If the header is
//serverfd: fd for server
//clientfd: fd for client
//headertosend: buf to send to server
CilkPrioCommandDefine(int, sendHeader, (int serverfd,volatile int clientfd, char* headerToSend),{
    //sending web headers to address.
    int ret_val= cilk_write_sync(serverfd, headerToSend, strlen(headerToSend));
    if(ret_val==-1){
      fprintf(stderr,"error in write here %d\n", serverfd);
      return -1;
    }
    return 0;
  });


//will send all the headers to the server, using the sendHeader 
//helper function. It will also//send any additional headers to 
//the server that the client requests
//serverfd: servres fd
//clientfd: fd of client
//request: request (create headers partially from that)
//headers: has fields for all the headers
CilkPrioCommandDefine(int, sendHeaders, 
		      (int serverfd, volatile int clientfd,
		       char* request,
		       headerStruct headers, struct timespec recTime), {


  
			//sending the predefined headers to the server
			if(cilk_run_command(sendHeader,serverfd, clientfd, request)){
			  cilk_run_command(writeError,clientfd, recTime, 0);
			  return -1;
			}
			if(cilk_run_command(sendHeader,serverfd, clientfd, headers.hostHeader)){
			  cilk_run_command(writeError,clientfd, recTime, 0);
			  return -1;
			}
			if(cilk_run_command(sendHeader,serverfd, clientfd, headers.UsrAgntHeader)){
			  cilk_run_command(writeError,clientfd, recTime, 0);
			  return -1;
			}
			if(cilk_run_command(sendHeader,serverfd, clientfd, headers.connHeader)){
			  cilk_run_command(writeError,clientfd, recTime, 0);
			  return -1;
			}
			if(cilk_run_command(sendHeader,serverfd, clientfd, headers.proxConnHeader)){
			  cilk_run_command(writeError,clientfd, recTime, 0);
			  return -1;
			}
			return 0;
		      });

//helper function to create the specific headers that must be 
//sent (like Connection: closed)
//info: info on the URL (method/type/etc..)
//headers: field for each header (cleaner in struct)
void createHeaders( parseInfo* info, headerStruct *headers){
      
  //create all predefined headers
  sprintf(headers->hostHeader, "Host: %s\r\n", info->hostname);
  sprintf(headers->UsrAgntHeader, "User-Agent: %s\r\n",header_user_agent);
  sprintf(headers->connHeader, "Connection: %s\r\n", headers->connStatus);
  sprintf(headers->proxConnHeader, "Proxy-Connection: %s\r\n\r\n", 
	  headers->proxStatus);
}





//function that actually gets the servers response and sends it back 
//to the client.
//clientfd: clients fd
//serverfd: servers fd
//uri: uri get info from
//bufforcache: buf to fill in so can cache
//sizescache: fields to store different info on buf size/amt read/etc..
//conNum: local conNum for client
CilkPrioCommandDefine(int, diskToClient, 
		      (volatile int clientfd,int serverfd,char* uri,char* bufForCache,sizesCache* sizes,volatile int conNum, struct timespec recTime), {

			//reads from server, while amount of data is small enough to fit in cache
			//copy into large buffer and eventually write to cache
			//char serverResponse[MAXLINE+16]=""; 
			//reading server response to a line, if it is no 0 write it to the client

			memset(sizes,0, sizeof(sizesCache));
			sizes->check=sizeof(resp);
			if(verbose>1){
			  fprintf(stderr,"Getting[%d] Web Data From(%d): %s\n", conNum, serverfd, uri);
			}
#ifdef REAL_IO
			while((sizes->bytes=cilk_read_sync(serverfd,
							   (bufForCache+sizes->check),
							   MAXLINE
							   ))>0){


			  //			  fprintf(stderr,"Spin[%d]: %lu + %lu -> %lu < %d(%d)\n", conNum, sizes->bytes, sizes->check, sizes->check+sizes->bytes, MAX_OBJECT_SIZE, (sizes->check+sizes->bytes) < MAX_OBJECT_SIZE);

			  sizes->check+=sizes->bytes;
			  if(sizes->check+MAXLINE > MAX_OBJECT_SIZE){
			    break;
			  }
			}
#endif
			if(sizes->bytes==-1){
			  fprintf(stderr,
				  "Issue reading from server -> {\n"
				  "\tFD      : %d\n"
				  "\tURI     : %s\n"
				  "\tREAD    : %lu\n"
				  "\tERR     : %s\n"
				  "\tTIMEOUT : %d\n"
				  "\tTRY_READ: %lu\n"
				  "}\n",
				  serverfd,
				  uri,
				  sizes->check,
				  strerror(errno),
				  errno==EWOULDBLOCK,
				  read(serverfd,
				       (bufForCache+sizes->check),
				       MAXLINE
				       ));
			  return (errno==EWOULDBLOCK) ? TIMEOUT_ERROR : OTHER_ERROR;
			  //return OTHER_ERROR;

			}
			resp server_resp;
			server_resp.len=sizes->check*real + sizeof(resp)*test;
			server_resp.result=PROXY_MISS;
			server_resp.lat=recTime; 
			if(real||test){
			  if(verbose>1){
			    fprintf(stderr,"Sending back[Miss]: %s -> [%d]{ %u , %u==%u , %lu }\n\n",
				    uri,
				    conNum,
				    server_resp.len,
				    server_resp.result,
				    PROXY_MISS,
				    format_ts(server_resp.lat));
			  }
			  int ret_val= cilk_write_sync(clientfd, (char*)(&server_resp), sizeof(resp));
			  if(ret_val==-1){
			    fprintf(stderr, "Issue writing server response to client\n");
			    return OTHER_ERROR;
			  }
			}
			if(real){
			  int ret_val = cilk_write_sync(clientfd, bufForCache+sizeof(resp), sizes->check-sizeof(resp));
			  if(ret_val==-1){
			    fprintf(stderr, "Issue writing server response(2) to client\n");
			    return OTHER_ERROR;
			  }

			}
		      
			//if size fits read to cache
			if(sizes->check<MAX_OBJECT_SIZE){
			  server_resp.result=PROXY_HIT;
			  memcpy(bufForCache, &server_resp, sizeof(resp));
			  cacheBlock* toadd=createBlock(bufForCache,(unsigned long)sizes->check, uri);
			  
			  cilk_run_command(insertTable,global, global->start, toadd);


			}

			return SUCCESS;
		      });



#ifdef WEB_TRANSFER
//function that actually gets the servers response and sends it back 
//to the client.
//clientfd: clients fd
//serverfd: servers fd
//uri: uri get info from
//bufforcache: buf to fill in so can cache
//sizescache: fields to store different info on buf size/amt read/etc..
//conNum: local conNum for client
CilkPrioCommandDefine(int, serverToClient, 
		      (volatile int clientfd,int serverfd,char* uri,char* bufForCache,sizesCache* sizes,volatile int conNum, struct timespec recTime), {

			//reads from server, while amount of data is small enough to fit in cache
			//copy into large buffer and eventually write to cache
			//char serverResponse[MAXLINE+16]=""; 
			//reading server response to a line, if it is no 0 write it to the client

			memset(sizes,0, sizeof(sizesCache));
			sizes->check=sizeof(resp);
			if(verbose>1){
			  fprintf(stderr,"Getting[%d] Web Data From(%d): %s\n", conNum, serverfd, uri);
			}
#ifdef REAL_IO
			while((sizes->bytes=cilk_read_sync_timeout(serverfd,
								   (bufForCache+sizes->check),
								   MAXLINE,
								   REQUEST_TIMEOUT_MS
								   ))>0){


			  //			  fprintf(stderr,"Spin[%d]: %lu + %lu -> %lu < %d(%d)\n", conNum, sizes->bytes, sizes->check, sizes->check+sizes->bytes, MAX_OBJECT_SIZE, (sizes->check+sizes->bytes) < MAX_OBJECT_SIZE);
			  sizes->check+=sizes->bytes;
			  if(sizes->check+MAXLINE>MAX_OBJECT_SIZE){
			    break;
			  }
			}
#endif
			int did_timeout = 0;
			if(sizes->bytes==-1){
			  if(errno==EWOULDBLOCK){
			    did_timeout = 1;
			  }
			  else{
			  fprintf(stderr,
				  "Issue reading from server -> {\n"
				  "\tFD      : %d\n"
				  "\tURI     : %s\n"
				  "\tREAD    : %lu\n"
				  "\tERR     : %s\n"
				  "\tTIMEOUT : %d\n"
				  "\tTRY_READ: %lu\n"
				  "}\n",
				  serverfd,
				  uri,
				  sizes->check,
				  strerror(errno),
				  errno==EWOULDBLOCK,
				  read(serverfd,
				       (bufForCache+sizes->check),
				       MAXLINE
				       ));
			  return OTHER_ERROR;
			  }
			}
			
			resp server_resp;
			server_resp.len=sizes->check*real + sizeof(resp)*test;
			server_resp.result= did_timeout ? PROXY_TIMEOUT : PROXY_MISS;
			server_resp.lat=recTime; 
			if(real||test){
			  if(verbose>1){
			    fprintf(stderr,"Sending back[Miss]: %s -> [%d]{ %u , %u==%u , %lu }\n\n",
				    uri,
				    conNum,
				    server_resp.len,
				    server_resp.result,
				    did_timeout ? PROXY_TIMEOUT : PROXY_MISS,
				    format_ts(server_resp.lat));
			  }
			  int ret_val= cilk_write_sync(clientfd, (char*)(&server_resp), sizeof(resp));
			  if(ret_val==-1){
			    fprintf(stderr, "Issue writing server response to client\n");
			    return OTHER_ERROR;
			  }
			}
			if(real && (!did_timeout)){
			  int ret_val = cilk_write_sync(clientfd, bufForCache+sizeof(resp), sizes->check-sizeof(resp));
			  if(ret_val==-1){
			    fprintf(stderr, "Issue writing server response(2) to client\n");
			    return OTHER_ERROR;
			  }
			}
		      
			//if size fits read to cache
			if(sizes->check<MAX_OBJECT_SIZE){
			  server_resp.result=PROXY_HIT;
			  memcpy(bufForCache, &server_resp, sizeof(resp));
			  cacheBlock* toadd=createBlock(bufForCache,(unsigned long)sizes->check, uri);
			  cilk_run_command(insertTable,global, global->start, toadd);


			}

			return SUCCESS;
		      });

#endif


//just memcat
//bufDest: destination
//bufSrc: source
//bufDestOffset: offset for desination
//BufSrcSize: sizeof source buf
void memCatMe(char* bufDest, char* bufSrc, ssize_t bufDestOffset,
	      ssize_t bufSrcSize){

  memcpy(bufDest+bufDestOffset, bufSrc, bufSrcSize);
}

//try and read from cache, return false if does not exist
//clientfd: fd for client
//uri: uri to check for
//conNum: local version of conNum
CilkPrioCommandDefine(int, tryAndReadFromCache, (volatile int clientfd,char* uri,volatile int conNum, struct timespec recTime, cacheBlock **first_hit), {

#ifdef UTIL_RESET
    if(!did_reset && conNum == 1){
      did_reset = 1;
      reset_overall_util_tracking();
    }
#endif
   
    //will point to response to read back
    char* cacheResponse=NULL;
    //    volatile int isIn=0;
    unsigned long returnSize=0;

    //reading from old cache
    cacheBlock* testBlock=checkTableQuery(global, uri);
    if(testBlock!=NULL){
      if(CASincr(testBlock)==FIRST_HIT){
#ifdef USE_DISK_TIMERFD
	*first_hit = testBlock;
	return testBlock->sizeBuf;
#endif
      }
      //isIn=1;
      returnSize=testBlock->sizeBuf;
      cacheResponse=testBlock->buf;
      /* }
	 if(isIn==1){*/
      if(verbose){
	fprintf(stderr,"site[%d][%d][%lu]: %s\n", conNum, clientfd, returnSize, uri);
      }
#ifdef FUT_HIT_WB
      cilk::pfuture<void, HitP_WB>* temp= new cilk::pfuture<void, HitP_WB>();
      cilk_pfuture_create(temp,
			  cacheRespWriteBack,
			  clientfd,
			  cacheResponse,
			  returnSize,
			  recTime,
			  hit_wb_futs[conNum]);
      hit_wb_futs[conNum] = temp;
#else
      if(real){
      resp server_resp = ((resp*)cacheResponse)[0];
      if(verbose>1){
	fprintf(stderr,"Sending back[Cache]: %d { %u , %u==%u , %lu }\n",
		  
		clientfd,
		server_resp.len,
		server_resp.result,
		PROXY_HIT,
		format_ts(server_resp.lat));
      }
      server_resp.lat = recTime;
      int ret_val= cilk_write_sync(clientfd, &server_resp, sizeof(resp));
      if(ret_val==-1){
	fprintf(stderr, "Issue writing cached file to client\n");
	return -1;

      }
      ret_val= cilk_write_sync(clientfd, cacheResponse+sizeof(resp), returnSize-sizeof(resp));
      if(ret_val==-1){
	fprintf(stderr, "Issue writing cached file to client\n");
	return -1;
      }
    }
    else if(test){
      resp server_resp;
      server_resp.lat = recTime;
      server_resp.len = sizeof(resp);
      server_resp.result = PROXY_HIT;
      if(verbose>1){
	fprintf(stderr,"Sending back[Cache]: %d -> { %u , %u==%u , %lu }\n",
		clientfd,
		server_resp.len,
		server_resp.result,
		PROXY_HIT,
		format_ts(server_resp.lat));
      }
	
      int ret_val= cilk_write_sync(clientfd, &server_resp, sizeof(resp));
      if(ret_val==-1){
	fprintf(stderr, "Issue writing cached file to client\n");
	return -1;
      }
    }
#endif
      return -1;
    }
    return 0;
  
  });

//listen on port wrapped (from csapp)
//port: portnum to listen on
int Open_listenfd(char *port) {
  int rc;

  if ((rc = open_listenfd(port)) < 0) {
    fprintf(stderr,"error in open\n");
  }
  return rc;
}

//real listen (from csapp)
//port: port to listen on
int open_listenfd(char *port) {
  struct addrinfo hints, *listp, *p;
  int listenfd, rc, optval=1;

  /* Get a list of potential server addresses */
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_socktype = SOCK_STREAM;             /* Accept connections */
  hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG; /* ... on any IP address */
  hints.ai_flags |= AI_NUMERICSERV;            /* ... using port number */
  if ((rc = getaddrinfo(NULL, port, &hints, &listp)) != 0) {
    fprintf(stderr, "getaddrinfo failed (port %s): %s\n",
	    port, gai_strerror(rc));
    return -2;
  }

  /* Walk the list for one that we can bind to */
  for (p = listp; p; p = p->ai_next) {
    /* Create a socket descriptor */
    listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (listenfd < 0) {
      continue;  /* Socket failed, try the next */
    }

    /* Eliminates "Address already in use" error from bind */
    setsockopt(listenfd, SOL_SOCKET,    //line:netp:csapp:setsockopt
	       SO_REUSEADDR, (const void *) &optval , sizeof(int));

    /* Bind the descriptor to the address */
    if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0) {
      break; /* Success */
    }

    if (close(listenfd) < 0) { /* Bind failed, try the next */
      fprintf(stderr, "open_listenfd close failed: %s\n",
	      strerror(errno));
      return -1;
    }
  }

  /* Clean up */
  freeaddrinfo(listp);
  if (!p) { /* No address worked */
    return -1;
  }

  /* Make it a listening socket ready to accept connection requests */
  if (listen(listenfd, LISTENQ) < 0) {
    close(listenfd);
    return -1;
  }
  return listenfd;
}

//change signal for signum
//signum: signal number of change
//handler: new function for signal
handler_t *Signal(int signum, handler_t *handler) {
  struct sigaction action, old_action;

  action.sa_handler = handler;
  sigemptyset(&action.sa_mask); /* Block sigs of type being handled */
  action.sa_flags = SA_RESTART; /* Restart syscalls if possible */

  if (sigaction(signum, &action, &old_action) < 0) {
    fprintf(stderr,"signal error\n");
  }

  return old_action.sa_handler;
}



//for access to web page. (from csapp)
//hostname: host to connect to
//port: port to connect on
int open_clientfd(char *hostname, char *port) {
  int cfd, rc;
  struct addrinfo hints, *listp;
  struct addrinfo *p;

  /* Get a list of potential server addresses */
  if(verbose>1){
    fprintf(stderr,"Getting addr info: %s\n", hostname);
  }
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_socktype = SOCK_STREAM;  /* Open a connection */
  hints.ai_flags = AI_NUMERICSERV;  /* ... using a numeric port arg. */
  hints.ai_flags |= AI_ADDRCONFIG;  /* Recommended for connections */
  if ((rc = getaddrinfo(hostname, port, &hints, &listp)) != 0) {
    fprintf(stderr, "getaddrinfo failed (%s:%s): %s\n",
	    hostname, port, gai_strerror(rc));
    return -2;
  }
  if(verbose >1){
  fprintf(stderr,"got addr info!\n");
  }
  /* Walk the list for one that we can successfully connect to */
  for (p = listp; p; p = p->ai_next) {
    /* Create a socket descriptor */
    cfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (cfd < 0) {
      continue; /* Socket failed, try the next */
    }
    /* Connect to the server */
    if (connect(cfd, p->ai_addr, p->ai_addrlen) != -1) {
      break; /* Success */
    }

    /* Connect failed, try another */
    if (close(cfd) < 0) { //line:netp:openclientfd:closefd
      fprintf(stderr, "open_clientfd: close failed: %s\n",
	      strerror(errno));
      return -1;
    }
  }
  /* Clean up */
  freeaddrinfo(listp);
  if (!p) {   /* All connects failed */
    return -1;
  } else {      /* The last connect succeeded */
    return cfd;
  }
}


//for access to disk webpage (basically open)
//hostname: host to connect to
//port: port to connect on
int open_clientfd_disk(char *hostname, int is_https) {
  char full_path[BUFSIZE<<1] = "";
  if(is_https){
    sprintf(full_path, "%s/%s/https.txt", SITE_PATH, hostname);
  }else{
    sprintf(full_path, "%s/%s/http.txt", SITE_PATH, hostname);
  }
  int fd = open(full_path, O_RDONLY);
  if(fd == -1){
    fprintf(stderr,"Error trying to open disk site for:\n\t%s\nat\n\t%s\n", hostname, full_path);
  }
  return fd;
}






//string hashing function (just universal vector hash)
//str: string (uri) to hash
//vec: vector to use for hashing
unsigned int hashStr(char * str, unsigned int * vec){
  unsigned int hash=vec[0];
  unsigned int UI_MAX=0;
  UI_MAX=~UI_MAX;
  int i=0;
  while(str[i]&&i<ssize){
    hash+=(str[i]*vec[i+1])&UI_MAX;
    i++;
  }
  return hash;
}

//create vectors
unsigned int * initVec(){
  unsigned int * vec=(unsigned int*)calloc((ssize+1),sizeof(unsigned int));
  for(int i =0;i<ssize+1;i++){
    unsigned int v_tmp=rand();
    v_tmp=((v_tmp>>1)<<1)+1;
    vec[i]=v_tmp;
  }
  return vec;
}


//increment hits for a cacheblock
//ent: block whose hit field needs to be incremented
int CASincr(cacheBlock* ent){
  return __atomic_add_fetch(&ent->hits, 1, __ATOMIC_RELAXED);
}

//create a new cacheblock
//buf: website data
//sizeBuf: sizeof the data
//bufTag: the uri 
cacheBlock* createBlock(char* buf, unsigned long sizeBuf, char* bufTag){
  cacheBlock* holder=(cacheBlock*)calloc(1,sizeof(cacheBlock));
  strcpy(holder->tag,bufTag);
  holder->sizeBuf=sizeBuf;
  holder->buf=(char*)calloc(sizeBuf,1);
  holder->hits=1;
  memcpy(holder->buf,buf, sizeBuf);
  return holder;
}

//free a cacheblock
//block: block to free
void freeBlock(cacheBlock* block){
  free(block->buf);
  free(block);
  
}

//swap to cacheblocks position for quicksort
//a: block 1 to swap
//b: block 2 to swap
void swap(cacheBlock** a, cacheBlock** b){
  cacheBlock* c=*b;
  *b=*a;
  *a=c;
}

//work for quicksort
//arr: array being sorted
//start: start index in array
//end: end index in array
int work(cacheBlock** arr, int start, int end){
  unsigned long pivot=arr[start+((end-start)>>1)]->hits;
  int min=start-1;
  int max=end+1;
  while(1){
    min++;
    while(arr[min]->hits<pivot){
      min++;
    }
    max--;
    while(arr[max]->hits>pivot){
      max--;
    }
    if(min>=max){
      return max;
    }
    swap(arr+min, arr+max);


  }

}

//recursive part of quicksort
//arr: array being sorted
//start: start index in array
//end: end index in array
CilkPrioCommandDefine(void, recursive, (cacheBlock** arr, int start, int end), {
    if(end>start){
      cilk_enable_diff_prio_spawn_in_this_func();
      int p=work(arr, start, end);
      cilk_pspawn_void(StatP,recursive,arr, start, p);
      cilk_run_command(recursive,arr, p+1, end);
      cilk_psync;
    }
  });


/*void recursive(cacheBlock** arr, int start, int end){
  if(end>start){
  cilk_enable_diff_prio_spawn_in_this_func();
  int p=work(arr, start, end);
  recursive(arr, start, p);
  recursive(arr, p+1, end);
  }
  }*/

//show the resulting array of sorting blocks by hits
//arr: array holding sorted cacheblocks
void showStats(cacheBlock** arr){
  int i=0;
  printf("------------------------\n");
  while(arr[i]){
    printf("%d: [%lu] -- %s\n", i,arr[i]->hits, arr[i]->tag);
    i++;
  }
  if(!i){
    printf("Empty Cache\n");
  }
  printf("------------------------\n");
}

 
//put all cacheblocks into array then sort it
//calls: amount of times collect stats has run
CilkPrioCommandDefine(cacheBlock**, collectStats, (int calls), {
    int mod=0;
    int startSize=global->TableArray[global->cur-1]->TableSize;
    cacheBlock** arr=(cacheBlock**)calloc(startSize, sizeof(cacheBlock*));
    int amt=0;
    volatile SubTable* ht=NULL;
    for(int j=global->start;j<global->cur;j++){
      ht=global->TableArray[j];
      for(int i =0;i<ht->TableSize;i++){
	if(getPtr(ht->InnerTable[i])){
	  if(!getBool(ht->InnerTable[i])){
	    arr[amt]=getPtr(ht->InnerTable[i]);
	    amt++;
	    if(amt==startSize<<mod){
	      mod++;
	      cacheBlock** narr=(cacheBlock**)realloc(arr,(startSize<<mod)*sizeof(cacheBlock*));
	      memset(((char*)narr)+((startSize<<(mod-1))*sizeof(cacheBlock*)),0, ((startSize<<(mod-1))*sizeof(cacheBlock*)));
	      arr=narr;
	    }
	  }
	}
      }
    }
    if(amt){
      cilk_run_command(recursive,arr, 0, amt-1);
    }
    statSize[calls]=amt;
    clock_gettime(CLOCK_MONOTONIC,&statEnd[calls]);
    if((calls<<1)>=iss){
      struct timespec* tempStarts = (struct timespec*)calloc(iss<<1, sizeof(struct timespec));
      struct timespec* tempEnds = (struct timespec*)calloc(iss<<1, sizeof(struct timespec));
      int* tempSize = (int*)calloc(iss<<1, sizeof(int));
      for(int i=0;i<iss;i++){
	tempStarts[i]=statStart[i];
	tempEnds[i]=statEnd[i];
	tempSize[i]=statSize[i];
      }

      iss=iss<<1;
      free(statStart);
      free(statEnd);
      free(statSize);
      statStart=tempStarts;
      statEnd=tempEnds;
      statSize=tempSize;
    }
    return arr;
  });

//background function to call collect stats on a period
//first: whether call should handle seperate case for first call (debugging)
CilkPrioCommandDefine(int, doStats, (int first), {
    int calls=0;
    int timerfd = timerfd_create(CLOCK_MONOTONIC,0);
    int old_flags=fcntl(timerfd, F_GETFL,0);
    if(fcntl(timerfd, F_SETFL, old_flags|O_NONBLOCK)<0){
      fprintf(stderr,"Error setting timer fd\n");
      fprintf(stderr,"%s\n", strerror(errno));
      return 0;
    }

    struct itimerspec timspec;
    bzero(&timspec, sizeof(timspec));
    timspec.it_interval.tv_sec = bgsec/nsMult;
    timspec.it_interval.tv_nsec = bgsec-nsMult*(bgsec/nsMult);

    timspec.it_value.tv_sec = 0;
    timspec.it_value.tv_nsec = nsMult/10;

    int res = timerfd_settime(timerfd, 0, &timspec, 0);
    if(res < 0){
      perror("timerfd_settime:");
    }

    uint64_t expirations = 0;

    while( (res = cilk_read_sync(timerfd, (char*)&expirations, sizeof(expirations)))){
      if(res < 0){ perror("read:"); continue; }
      if(end_stats){
	return 0;
      }
      if(!first){
	cacheBlock** arr=cilk_pfuture_get(s_fut);

	if(verbose>2){
	  showStats(arr);
	}
	if(arr){
	  free(arr);
	}
      }
      first=0;

      cilk::pfuture<cacheBlock**, StatP>* temp= new cilk::pfuture<cacheBlock**, StatP>();
      s_fut=temp;
      clock_gettime(CLOCK_MONOTONIC,&statStart[calls]);
      cilk_pfuture_create(s_fut, collectStats, calls);
      calls++;
    }


    return 0;
  });


//returns whether an cacheBlock is found in a given subtable/overall hashtable. notIn means not
//in the hashtable, s means in the hashtable and was found (return s so can get the value
//of the item). unk means unknown if in table.
//ht: subtable to check
//tag: tag to compare
//s: index in ht to check
int 
lookupQuery(volatile SubTable* ht, char* tag, unsigned int s){

  //if find null slot know item is not in hashtable as would have been added there otherwise
  if(getPtr(ht->InnerTable[s])==NULL){
    if(!getBool(ht->InnerTable[s])){
      return notIn;
    }
    return unk;
  }

  //values equal return index so can access later
  else if(!strcmp(tag,getPtr(ht->InnerTable[s])->tag)){
    return s;
  }

  //go another value, try next hash function
  return unk;
    
}


//api function user calls to query the table for a given cacheBlock. Returns 1 if found, 0 otherwise.
//head: head of hashtable
//tag: tag to check if is in cache
cacheBlock* checkTableQuery(volatile HashTable* head, char* tag){
  volatile SubTable* ht=NULL;

  //iterate through sub tables
  unsigned int buckets[vsize];
  for(int i =0;i<head->hashAttempts;i++){
    buckets[i]=hashStr(tag, head->seeds[i]);
  }

  for(int j=head->start;j<head->cur;j++){
    ht=head->TableArray[j];

    //iterate through hash functions
    //        for(int i =0;i<(j<<1)+1;i++){
    
    for(int i =0; i<head->hashAttempts; i++) {

      //get results of lookup
      int res=lookupQuery(ht, tag, buckets[i]%ht->TableSize);
      if(res==unk){ //unkown if in our not
	continue;
      }
      if(res==notIn){
	return NULL;/* indicate not found */
      }
      // otherwise, it is found
      return getPtr(ht->InnerTable[res]);
    }
  }
  // we never found it
  return NULL;
}

//prints all elements in cache (debugging)
//head: head of hashtable
CilkPrioCommandDefine(double, printTable, (volatile HashTable* head), {
    volatile SubTable* ht=NULL;
    double count=0;
    double totalSize=0;
    int * items=NULL;
    if(verbose){
      items=(int*)calloc(sizeof(int), head->cur);
      printf("Tables %lu-%lu:\n", head->start, head->cur);
    }
    for(int i = 0;i<head->cur; i++){
      ht=head->TableArray[i];
      totalSize+=ht->TableSize;
      for(int j =0;j<ht->TableSize;j++){
	if(getPtr(ht->InnerTable[j])!=NULL){
	  if(!getBool(ht->InnerTable[j])){
	    if(verbose){
	      printf("[%lu] - > %s\n", getPtr(ht->InnerTable[j])->hits,getPtr(ht->InnerTable[j])->tag);
	    }
	    count++;
	    if(verbose){
	      items[i]++;
	    }
	  }
	}
      }
      if(verbose){
	int sumB=0;
	for(int n =0;n<ht->TableSize;n++){
	  sumB+=getBool(ht->InnerTable[n]);
	}
	printf("%d: %d/%d - %d\n", 
	       i, items[i], ht->TableSize,  sumB);
      }
    }
    if(verbose){
      free(items);
      printf("Total: %d\n", (int)count);
    }    
    return count/totalSize;  
  });

//frees a given table that was created for adddrop (that failed)
//ht: subtable to free
void 
freeTable(volatile SubTable* ht){
  free((void*)ht->InnerTable);
  //  free(ht->copyBools);
  free((void*)ht);
}


//check if cacheBlock for a given hashing vector is in a table. Returns in if cacheBlock is already
//in the table, s if the value is not in the table, and unk to try the next hash function
//head: head of hashtable
//ht: subtable to check
//ent: entry to test for
//s: index into subtable
int lookup(volatile HashTable* head,volatile  SubTable* ht, cacheBlock* ent, unsigned int s){


  //if found null slot return index so insert can try and put the cacheBlock in the index 
  if(getPtr(ht->InnerTable[s])==NULL){ 
    if(!getBool(ht->InnerTable[s])){ 
      return s; 
    } 
    return unk; 
  } 
  //found value, return in 
  else if(!strcmp(getPtr(ht->InnerTable[s])->tag,ent->tag)){ 
    return in; 
  } 
  //neither know if value is in or not, first check if this is smallest subtable and  
  //resizing is take place. If so move current item at subtable to next one. 
  //return unk 
  return unk; 
}


//moves items from ht to larger subtables in head
//head: head of hashtable
//ht: subtable to have its elements moved from
//h: future for previous resize
CilkPrioCommandDefine(int, resize, (volatile HashTable* head,volatile SubTable* ht, cilk::pfuture<int, ResizeP>* h), { 
    
    if(h){ 
      int r_ret=cilk_pfuture_get(h); 
      if(!r_ret){ 
	printf("Error Resizing\n"); 
      } 
    } 
    for(int i =0;i<ht->TableSize;i++){ 
      while(!getBool(ht->InnerTable[i])){ 

 	setPtr(&ht->InnerTable[i]); 
  
      } 
      if(getPtr(ht->InnerTable[i])){ 
 	cilk_run_command(insertTable,head, head->start+1, getPtr(ht->InnerTable[i])); 
      } 
    } 
    __atomic_add_fetch(&head->start, 1, __ATOMIC_RELAXED);
    head->copying=0; 
    return 1; 
  });


//function to add new subtable to hashtable if dont find open slot
//head: head of hashtable
//toadd: new subtable to add
//AddSlot: index in subtable array to add new subtable to
//ent: entry to try inserting again after subtable added
//start: start index in subtable array
CilkPrioCommandDefine(int, addDrop,  
 		      (volatile HashTable* head,volatile  SubTable* toadd, unsigned long AddSlot, cacheBlock* ent,int start), { 
			//try and add new preallocated table (CAS so only one added) 
			volatile SubTable* expected=NULL; 
			int res = __atomic_compare_exchange(&head->TableArray[AddSlot] ,&expected, &toadd, 1, __ATOMIC_RELAXED, __ATOMIC_RELAXED); 
			if(res){ 
			  //if succeeded try and update new max then insert item 
			  volatile unsigned long newSize=AddSlot+1; 
			  __atomic_store(&head->cur, &newSize, __ATOMIC_SEQ_CST);
			  return cilk_run_command(insertTable,head, start, ent); 
			} 
			else{ 
			  //if failed free subtable then try and update new max then insert item 
			  freeTable(toadd); 
			  volatile unsigned long newSize=AddSlot+1; 
			  __atomic_store(&head->cur, &newSize, __ATOMIC_SEQ_CST);
			  return cilk_run_command(insertTable,head, start, ent); 
			} 
 		      });

//insert a new cacheBlock into the table. Returns 0 if cacheBlock is already present, 1 otherwise.
//head: head of hashtable
//start: start index into subtable array in head
//ent: entry to add to hashtable
CilkPrioCommandDefine(int, insertTable, (volatile HashTable* head,  int start, cacheBlock* ent), { 

    volatile SubTable* ht=NULL; 
    unsigned long LocalCur=head->cur; 
    unsigned int buckets[vsize]; 
    for(int i =0;i<head->hashAttempts;i++){ 
      buckets[i]=hashStr(ent->tag, head->seeds[i]); 
    } 
    //iterate through subtables 
    for(int j=start;j<head->cur;j++){ 
      ht=head->TableArray[j]; 
      //do copy if there is a new bigger subtable and currently in smallest subtable 
      int doCopy=(j==head->start)&&(head->cur-head->start>1)&&(!head->copying); 
      if(doCopy){ 
 	unsigned long old_copy=0; 
 	unsigned long new_copy=1; 
 	int me = __atomic_compare_exchange(&head->copying,&old_copy, &new_copy, 1, __ATOMIC_RELAXED, __ATOMIC_RELAXED); 
 	if(me){ 

	  cilk::pfuture<int, ResizeP>* temp= new cilk::pfuture<int, ResizeP>();
	  cilk_pfuture_create(temp, resize, head, ht, head->r_fut);
	  head->r_fut=temp;

	}
      }
      //iterate through hash functions
      for(int i =0; i<head->hashAttempts; i++) {

	//lookup value in sub table
	int res=lookup(head, ht, ent, buckets[i]%ht->TableSize);
	if(res==unk){ //unkown if in our not
	  continue;
	}
	if(res==in){ //is in
	  return 0;
	}


	//if return was null (is available slot in sub table) try and add with CAS.
	//if succeed return 1, else if value it lost to is item itself return. If neither
	//continue trying to add
	volatile cacheBlock* expected=NULL;
	int cmp= __atomic_compare_exchange((ht->InnerTable+res),
					   &expected,
					   (volatile cacheBlock**)&ent,
					   1, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
	if(cmp){
	  return 1;
	}
	else{
	  if(getPtr(ht->InnerTable[res])){
	    if(!strcmp(getPtr(ht->InnerTable[res])->tag,ent->tag)){
	      return 0;
	    }
	  }
	}
      }
      LocalCur=head->cur;
    }

    //if found no available slot in hashtable create new subtable and add it to hashtable
    //then try insertion again
    volatile SubTable* new_table=createTable(head, head->TableArray[LocalCur-1]->TableSize<<1);
    return cilk_run_command(addDrop,head, new_table, LocalCur, ent, start+1);

  });


//initial hashtable. First table head will be null, after that will just reinitialize first table
//returns a pointer to the hashtable
//head: ptr to intialize as hashtable
//initiSize: initialze size of 0th subtable
//hashAttempt: amount of times to retry hashing an entry
volatile HashTable* initTable(volatile HashTable* head, int InitSize, int HashAttempts){

  head=(volatile HashTable*)calloc(1,sizeof(HashTable));
  if(HashAttempts>10){
    printf("Changing value for hashattempts from %d to 10\n", HashAttempts);
    HashAttempts=10;
  }
  head->hashAttempts=HashAttempts;
  head->seeds=(unsigned int**)calloc(HashAttempts, sizeof(unsigned int*));
  for(int i =0;i<HashAttempts;i++){
    head->seeds[i]=initVec();

  }
  head->TableArray=(volatile SubTable**)calloc(max_tables,sizeof(SubTable*));
  head->TableArray[0]=createTable(head, InitSize);
  head->cur=1;
  head->start=0;
  head->copying=0;
  head->r_fut=NULL;
  return head;
}

//creates a subtable
//head: head of hashtable
//tsize: size subtable should be 
volatile SubTable* 
createTable(volatile HashTable* head, int tsize){
  SubTable* ht=(SubTable*)calloc(1,sizeof(SubTable));
  ht->TableSize=tsize;
  ht->InnerTable=(volatile cacheBlock**)calloc((ht->TableSize),sizeof(cacheBlock*));
  return ht;
}
