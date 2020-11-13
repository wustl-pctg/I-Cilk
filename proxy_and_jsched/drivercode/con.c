#include <stdbool.h>
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <sys/un.h>
#include "utils/util.h"
#include "utils/arg.h"
#include "utils/timing.h"
#include "common/ktiming.h"

//#include "utils/dist.h"
const char* SITE_PATH = "pldi-websites";
//const char* SITE_PATH = "/project/adams/home/goldstein.n/spaa20-websites";

//keep this variable up to date based on which machine being used


#define GET_OFFSET 4
#define HTTP_PREFIX_OFFSET 4
#define HTTP_POSTFIX_OFFSET 3
#define FULL_OFFSET (GET_OFFSET+HTTP_PREFIX_OFFSET+HTTP_POSTFIX_OFFSET)
#define quit 1
#define send 2
#define READLINE 128


#define max_error 10

#define PROXY_TIMEOUT 5
#define PROXY_ERROR 4
#define PROXY_MISS 3
#define PROXY_HIT 2
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))


typedef struct resp{
  int len;
  int result;
  struct timespec lat;
}resp;

typedef struct eparser{
  int tid;
  int offset;

}eparser;
typedef struct targs {
  char** requests;
  struct timespec * timesR;
  struct timespec * timesW;
  struct timespec * recLatency;
  char* isCache;
  int*  req_lens;
  int * rsize;
  int* site_sizes;
  int tid;
} targs;

Barrier endLoopBarrier;
Barrier loopBarrier;
struct timespec startRun, endRun;
#define maxReq 256
int socks[maxReq];
FILE *sfiles[maxReq];
FILE* sout_fp=NULL;
fd_set files;
int verbose=0;
int nthreads=1;
int nreqs=0;
int sites=0;
int portNum=6005;
int prefetch=0;
int cull = 0;
int to_disk = 0;
char* trace=NULL, *sout=NULL;
int on_disk = 0;

double den=((double)RAND_MAX)+1.0;
int rseed=0;
int runNum = 0;
int in_mem =0;
int qnl_collect = 0;

//normally we do cilk_nworkers = 20
int nworkers = 20;
int next_socket = 0;

typedef unsigned long summary_t;

const unsigned long nsMult = 1000000000;
const int ret_size = sizeof(struct timespec) + 1;
double nsMultDL = 1000000000.0;

#define startSize 256
#define reqSize 256

#define Version "0.1"


static ArgOption args[] = {
  // Kind,        Method, name,         reqd, variable,  help
  { KindOption,   Integer, "-v",            0, &verbose,  "Turn on verbosity (0-2)" },
  { KindHelp,     Help,    "-h" },
  { KindOption,   String,  "--trace",       0, &trace,    "Trace file to give inputs to server" },
  { KindOption,   Integer, "--sites",       0, &sites,    "Number of sites to use"},
  { KindOption,   Integer, "--requests",    0, &nreqs,    "Number of requests per thread"},
  { KindOption,   Integer, "--rnum",        0, &runNum,   "Run num (for data collect)" },
  { KindOption,   Integer, "--port",        0, &portNum,  "Port to connect on" },
  { KindOption,   Integer, "-t",            0, &nthreads, "Number of Client threads" },
  { KindOption,   Integer, "--seed",        0, &rseed,    "Seed for srand" },
  { KindOption,   Integer, "--nworkers",    0, &nworkers, "Number of workers proxy is running with" },
  { KindOption,   Integer, "--nexts",       0, &next_socket, "Where next socket starts (if multi socket machine)" },
  { KindOption,   Set,     "--collect",     0, &qnl_collect,           "save quant data" },
  { KindOption,   Set,     "--prefetch",    0, &prefetch, "Prefetch all the data so its cached" },
  { KindOption,   Set,     "--ondisk",      0, &on_disk,  "set if site is coming from disk" },
  { KindOption,   Set,     "--cull",        0, &cull,     "Cull bad sites" },
  { KindOption,   Set,     "--disk",        0, &to_disk,     "send site data to disk (use with cull)" },
  { KindOption,   String,  "--newsites",    0, &sout,     "Set outfile for good sites (not imeout/error)" },

  { KindEnd }
};

static ArgDefs argp = { args, "Driver For Proxy Server", Version, NULL };

typedef struct sockaddr SA;
int compare_fun(const void* a, const void* b){
  return *(int*)a - *(int*)b;
}


void* sendnwait(void* arg);
void handleRequest(char* isCache,
		   struct timespec* ltimes,
		   struct timespec* rtimes,
		   struct timespec* wtimes,
		   int* rsize,
		   int* site_sizes,
		   char* buf,
		   char* temp_buf,
		   char** requests,
		   int* req_lens,
		   int tid,
		   int i);



void displayResults(summary_t* miss_read, summary_t* miss_lat, int miss_count,
		    summary_t* hit_read, summary_t* hit_lat, int hit_count,
		    summary_t* error_read, summary_t* error_lat, int error_count,
		    summary_t* timeout_read, summary_t* timeout_lat, int timeout_count,
		    char** isCache, int** rsize);
void displayResults_csv(summary_t* miss_read, summary_t* miss_lat, int miss_count,
			summary_t* hit_read, summary_t* hit_lat, int hit_count,
			summary_t* error_read, summary_t* error_lat, int error_count,
			summary_t* timeout_read, summary_t* timeout_lat, int timeout_count,
			char** isCache, int** rsize);
void normalizeData(summary_t* miss_read, int miss_count,
		   summary_t* hit_read, int hit_count,
		   summary_t* error_read,int error_count,
		   summary_t* timeout_read,int timeout_count,
		   char** isCache, int** rsize);




suseconds_t to_usecs(struct timespec t) {
  return (t.tv_sec * nsMult + t.tv_nsec) / 1000;
}

suseconds_t to_nsecs(struct timespec t) {
  return (t.tv_sec * nsMult + t.tv_nsec);
}
suseconds_t format_ts(struct timespec t) {
  return to_nsecs(t);
}
suseconds_t difftimespecs(struct timespec t1, struct timespec t2) {
  return (format_ts(t1) - format_ts(t2));
}

float nextTime(float rateParameter){
  return -logf(1.0f-((float)random()/den))/rateParameter;
}

void startBarrier(int tid){
  if (tid == 0) {
    myBarrier(&loopBarrier, tid);
    clock_gettime(CLOCK_MONOTONIC, &startRun);
  } else {
    myBarrier(&loopBarrier, tid);
  }
}

void endBarrier(int tid){
  if (tid == 0) {
    myBarrier(&loopBarrier, tid);

  } else {
    myBarrier(&loopBarrier, tid);
  }
}

int open_listenfd(char *port);
int Open_listenfd(char *port) {
  int rc;

  if ((rc = open_listenfd(port)) < 0) {
    fprintf(stderr,"error in open\n");
  }
  return rc;
}

//real listen (from csapp)
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
  if (listen(listenfd, 1) < 0) {
    close(listenfd);
    return -1;
  }
  return listenfd;
}


int r_connect_proxy(int sock);
int r_send(char *line, int len, int sock);


//connect to server

//not we connect in order so conNum should match up with index in sock array on client
//side




int r_connect_proxy(int sock) {
  //  int sock=0;

  //char hostname[1024];
  //gethostname(hostname, 1024);
  const char *hostname = "localhost";
  //  if (sscanf(line, "connect %d %d", &portNum, &sock) != 2) return 0;

  socks[sock] = socket(AF_INET, SOCK_STREAM, 0);
  if (socks[sock] < 0)
    printf("Warning: can't open socket %d\n", sock);
  struct hostent *server;
  struct sockaddr_in serv_addr;
  server = gethostbyname(hostname);
  if (server == NULL)
    printf("Warning: can't find host for socket %d: %s\n", sock, strerror(errno));
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
	(char *)&serv_addr.sin_addr.s_addr,
	server->h_length);
  serv_addr.sin_port = htons(portNum);
  if (connect(socks[sock],(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
    {
      printf("Warning: can't connect socket %d: %s\n", sock, strerror(errno));
      shutdown(socks[sock], SHUT_RDWR);
      socks[sock] = -1;
    } else {
    sfiles[sock] = fdopen(socks[sock], "r");
    //pthread_mutex_init(&smutex[sock], NULL);
    FD_SET(socks[sock], &files);
  }


  return 1;
}


//send data
int r_send(char *line, int len, int sock) {
  if (socks[sock] == -1) return 0;
  int i=len;
  if(verbose){
    printf("Getting[%d][%d", sock, len);
    if(verbose>1){
      printf("==%zd", strlen(line));
    }
    printf("]: %s", line);
  }
  if(write(socks[sock], line,i )<0){
    return 0;
  }

  return 1;
}


void handleRequest(char* isCache,
		   struct timespec* ltimes,
		   struct timespec* rtimes,
		   struct timespec* wtimes,
		   int* rsize,
		   int* site_sizes,
		   char* buf,
		   char* temp_buf,
		   char** requests,
		   int* req_lens,
		   int tid,
		   int i){
  int re=0;
  int index=random()%sites;

  if((i*nthreads)+tid<sites){
    index=(i*nthreads)+tid;
  }
  int norm_size = site_sizes[index];
  clock_gettime(CLOCK_MONOTONIC, &wtimes[i]);
  if(!r_send(requests[index], req_lens[index], tid)){
    fprintf(stderr,"Failed to send to proxy server\n");
  }

  int tread=0;
  int to_read = sizeof(resp);
  resp server_resp;
  int set_struct =0;
  while(tread<to_read){
    if(verbose>2){
      printf("Progress on %s -> %d/%d\n", requests[index], tread, to_read);
    }
    re=read(socks[tid], buf, READLINE);
    if(verbose>2){
      printf("Read: %d -> %d/%d\n", re, tread+re, to_read);
    }
    if(re<1){
      fprintf(stderr,"Error reading\n");
      fprintf(stderr,"%s\n", strerror(errno));
      break;
    }
    if(tread<sizeof(resp)){
      if(verbose>0){
      fprintf(stderr,"Incomplete[%d][(%d, %ld) = %ld -> %s\n", tid, re, sizeof(resp)-tread, min(re, sizeof(resp)-tread), requests[index]);
      }
      memcpy(temp_buf+tread, buf, min(re, sizeof(resp)-tread));
    }
    tread+=re;
    if(!set_struct && tread>=sizeof(resp)){
      set_struct = 1;
      server_resp=*((resp*)(temp_buf));
      to_read = server_resp.len;

      if(verbose){
	fprintf(stderr,"Recieved[%d]: %s -> { %u , %u , %lu }\n",
		tid,
		requests[index],
		server_resp.len,
		server_resp.result,
		format_ts(server_resp.lat));
      }
      if(server_resp.result==PROXY_MISS ||
	 server_resp.result==PROXY_HIT ||
	 server_resp.result==PROXY_ERROR ||
	 server_resp.result==PROXY_TIMEOUT){
	if(verbose){
	  if(server_resp.result==PROXY_MISS){
	    printf("Got Miss: %s\n", requests[index]);
	  }
	  else if(server_resp.result==PROXY_HIT){
	    printf("Got Hit: %s\n", requests[index]);
	  }
	  else if(server_resp.result==PROXY_ERROR){
	    printf("Got Error: %s\n", requests[index]);
	  }
	  else{
	    printf("Got Timeout: %s\n", requests[index]);
	  }
	}
	clock_gettime(CLOCK_MONOTONIC, &rtimes[i]);
	isCache[i]=server_resp.result;
	memcpy(&ltimes[i], &server_resp.lat, sizeof(struct timespec));
	rsize[i]=server_resp.len;
	if(server_resp.result==PROXY_MISS &&  on_disk){
	  rsize[i]=norm_size;
	}
      }
      else{
	fprintf(stderr,"Unknown Result for %s\n", requests[index]);
	exit(0);
      }
    }
  }
  
  if(!(tread == to_read)){
    fprintf(stderr,"Error[%d][%d] -> %d/%d -> %s\n", tid, i, tread, to_read, requests[index]);
    sleep(5);
    assert(0);
  }
}

void* sendnwait(void* arg){
  targs* args=(targs*)arg;
  int tid=args->tid;
  char** requests=(char**)args->requests;
  char* isCache=args->isCache;
  struct timespec* ltimes=args->recLatency;
  struct timespec* rtimes=args->timesR;
  struct timespec* wtimes=args->timesW;
  int* rsize=args->rsize;
  int* req_lens = args->req_lens;
  int* site_sizes=args->site_sizes;
  free(args);

  char* buf=calloc(READLINE<<1, sizeof(char));
  char* temp_buf =calloc(READLINE<<1, sizeof(char));
  startBarrier(tid);
  int progress = nreqs/100;

  for(int i =0;i<nreqs;i++){
    if(verbose>1){
      if(i>progress){
	fprintf(stderr,"%d -> %d/100\n", tid, progress/(nreqs/100));
	progress+=nreqs/100;
      }
    }
    handleRequest(isCache,
		  ltimes, rtimes, wtimes,
		  rsize, site_sizes,
		  buf, temp_buf,
		  requests, req_lens,
		  tid, i);
  }

  endBarrier(tid);
  return NULL;
}




int main(int argc, char *argv[]) {
  trace=calloc(1, 64);
  sout=calloc(1, 64);
  progname = argv[0];
  ArgParser* ap = createArgumentParser(&argp);
  int ok = parseArguments(ap, argc, argv);
  if (ok) die("Error parsing arguments");

  for (int a=0;a<argc;a++){
    printf("%s ",argv[a]);
  }
  printf("\n");
  fflush(stdout);

  char disk_path[128] = "";
  if(cull){
    sout_fp = fopen(sout, "w");
    if(!sout_fp){
      fprintf(stderr,"Couldn't open newsite file: %s\n", sout);
      return -1;
    }
  }
  if(rseed){
    srand(rseed);
  }
  else{
    srand(time(NULL));
  }
  
  int i;
  for (i = 0; i < maxReq; i++) {
    socks[i] = -1;
  }
  FD_ZERO(&files);

  FILE* in=fopen(trace, "r");
  if(!in){
    fprintf(stderr, "Error opening site file at: %s\n", trace);
  }
  char input[reqSize+GET_OFFSET]="GET ";

  for(i=0;i<nthreads;i++){
    if(!r_connect_proxy(i)){
      fprintf(stderr,"Error connecting to proxy server on port %d\n", portNum);
    }
  }
  char** requests=calloc(sites, sizeof(char*));
  int* req_lens=calloc(sites, sizeof(int));
  int* site_sizes=calloc(sites, sizeof(int));
  int re=0;
  char* buf=calloc((1<<20)+16,sizeof(char));
  int total_iter = 0;
  for(i=0;i<sites;i++){
    requests[i]=calloc(reqSize, sizeof(char));
    if(fgets(input+GET_OFFSET, reqSize, in)){
      strcpy(requests[i], input);
      req_lens[i] = strlen(requests[i]);
      if(on_disk){
	int old_len = strlen(requests[i]);
	assert(requests[i][old_len-2] == '/');
	requests[i][old_len-2] = '\0';
	int is_https = requests[i][GET_OFFSET+HTTP_PREFIX_OFFSET] == 's';
	if(is_https){
	  sprintf(disk_path, "%s/%s/https.txt",
		  SITE_PATH,
		  requests[i]+FULL_OFFSET+1
		  );
	}
	else{
	  sprintf(disk_path, "%s/%s/http.txt",
		  SITE_PATH,
		  requests[i]+FULL_OFFSET
		  );
	}


	FILE* site_fp = fopen(disk_path, "r");
	if(!site_fp){
	  fprintf(stderr, "Error opening disk_path!\n\t%s", strerror(errno));
	  return -1;
		  
	}
	requests[i][old_len-2] = '/';
	fseek(site_fp, 0, SEEK_END); // seek to end of file
	site_sizes[i] = ftell(site_fp);
	fclose(site_fp);
      }
      if(prefetch){
	if(verbose){
	  printf("Prefetch[%d] -> %s", i, requests[i]);
	}
	if(!r_send(requests[i], req_lens[i], 0)){
	  fprintf(stderr,"Error sending request to server!\n");
	  fprintf(stderr,"%s\n", strerror(errno));
	  exit(0);
	}
	int tread=0;
	int to_read = sizeof(resp);
	resp server_resp;
	char temp_buf[sizeof(resp)] = "";
	int set_struct = 0;
	while(tread<to_read){
	  if(verbose>2){
	    printf("Progress on %s -> %d/%d\n", requests[i], tread, to_read);
	  }
	  re=read(socks[0], buf+tread, READLINE);
	  if(verbose>2){
	    printf("Read: %d -> %d/%d\n", re, tread+re, to_read);
	  }
	  if(re<1){
	    fprintf(stderr,"Error reading\n");
	    fprintf(stderr,"%s\n", strerror(errno));
	    break;
	  }
	  if(tread<sizeof(resp)){
	    memcpy(temp_buf+tread, buf, min(re, sizeof(resp)-tread));
	  }
	  tread+=re;
	  if(!set_struct && tread>=sizeof(resp)){
	    set_struct = 1;
	    server_resp=*((resp*)(&temp_buf));

	    to_read = server_resp.len;
	    if(server_resp.result==PROXY_ERROR ||
	       server_resp.result==PROXY_TIMEOUT){
	      to_read = tread;
	    }
	    if(verbose){
	      fprintf(stderr,"Recieved: %s -> { %u , %u==%u , %lu }\n\n",
		      requests[i],
		      server_resp.len,
		      server_resp.result,
		      PROXY_MISS,
		      format_ts(server_resp.lat));
	    }
	  }
	}
	    
	    if(server_resp.result==PROXY_ERROR){
	      //dont move forward with requests that dont bode well
	      i--;
	    }else if(cull){
	      fprintf(stderr, "writing[%d/%d]: %s", i, total_iter, requests[i]+GET_OFFSET);
	      fprintf(sout_fp, "%s", requests[i]+GET_OFFSET);
	      fflush(sout_fp);
	      if(to_disk){
		int old_len = strlen(requests[i]);
		assert(requests[i][old_len-2] == '/');
		requests[i][old_len-2] = '\0';
		int is_https = requests[i][GET_OFFSET+HTTP_PREFIX_OFFSET] == 's';
		sprintf(disk_path, "%s/%s", SITE_PATH, requests[i]+FULL_OFFSET+is_https);
		if(mkdir(disk_path,  S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)==-1){
		  if(errno != EEXIST){
		    fprintf(stderr, "real error making directory:\n%s\n%s\n",
			    disk_path,
			    strerror(errno));
		    return -1;
		  }
		}
		if(is_https){
		  sprintf(disk_path, "%s/%s/https.txt",
			  SITE_PATH,
			  requests[i]+FULL_OFFSET+1
			  );
		}
		else{
		  sprintf(disk_path, "%s/%s/http.txt",
			  SITE_PATH,
			  requests[i]+FULL_OFFSET
			  );
		}

		fprintf(stderr, "Full path: %s\n", disk_path);
		FILE* site_fp = fopen(disk_path, "w+");
		if(!site_fp){
		  fprintf(stderr, "Error opening disk_path!\n\t%s", strerror(errno));
		  return -1;
		  
		}
		fprintf(site_fp, "%s", buf+sizeof(resp));
		fflush(site_fp);
		fclose(site_fp);
		requests[i][old_len-2] = '/';
	      }
	    }
	    total_iter++;
      }
    }
    else{
      fprintf(stderr,"Error getting site from file!\n");
      fprintf(stderr,"%s\n", strerror(errno));
      exit(0);
    }
  }
  if(verbose > 0 && prefetch){
    fprintf(stderr,"Done prefetching\n");
  }
  free(buf);


  struct timespec** writerTimes=calloc(nthreads, sizeof(struct timespec*));
  struct timespec** readerTimes=calloc(nthreads, sizeof(struct timespec*));
  struct timespec** latencyTimes=calloc(nthreads, sizeof(struct timespec*));
  char** isCache=calloc(nthreads, sizeof(char*));
  int** rsize=calloc(nthreads, sizeof(int*));
  for(i=0;i<nthreads;i++){
    latencyTimes[i]=calloc(nreqs, sizeof(struct timespec));
    rsize[i]=calloc(nreqs, sizeof(int));
    isCache[i]=calloc(nreqs, sizeof(char));
    writerTimes[i]=calloc(nreqs, sizeof(struct timespec));
    readerTimes[i]=calloc(nreqs, sizeof(struct timespec));
  }

  initBarrier(&loopBarrier);
  initBarrier(&endLoopBarrier);

  int offset=nworkers>>1;
  int num_cores=sysconf(_SC_NPROCESSORS_ONLN);
  num_cores -= (offset<<1);
  num_cores = num_cores >> 1;
    

  
  pthread_t* threadids_w = (pthread_t*)calloc(nthreads, sizeof(pthread_t));
  for(i =0; i<nthreads; i++) {
    if(i==(nthreads)>>1){
      offset+=next_socket;
    }
    pthread_attr_t attr;
    int result = pthread_attr_init(&attr);
    if (result) errdie("Can't do attr_init");

    // allocate each thread on its own core
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    int set_core = offset+(i%(num_cores));
    if(set_core >= sysconf(_SC_NPROCESSORS_ONLN)){
      fprintf(stderr,"Error setting cores. Ensure next_socket is properly configured: %d->%d/%lu\n",
	      i, set_core, sysconf(_SC_NPROCESSORS_ONLN));
      exit(0);
    }
    if(verbose > 0){
      fprintf(stderr,"Setting [thread, core] [%d -> %d]\n", i, set_core);
    }
    CPU_SET(set_core, &cpuset);
    result = pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpuset);
    if (result) die("setaffinitity fails: %d", result);
    
    targs* temp_args=(targs*)malloc(sizeof(targs));
    temp_args->requests=requests;
    temp_args->tid=i;
    temp_args->timesR=readerTimes[i];
    temp_args->timesW=writerTimes[i];
    temp_args->recLatency = latencyTimes[i];
    temp_args->isCache=isCache[i];
    temp_args->rsize=rsize[i];
    temp_args->req_lens = req_lens;
    temp_args->site_sizes = site_sizes;
    result = pthread_create(&threadids_w[i], &attr, sendnwait, (void*)temp_args);
    if (result) errdie("Can't create threads");
    pthread_attr_destroy(&attr);
  }
  // threads are all launched, now wait til they are all done

  // clean them up
  for(i=0;i<nthreads;i++){
    pthread_join(threadids_w[i], NULL);
  }
  
  clock_gettime(CLOCK_MONOTONIC, &endRun);
  double secs=((double)difftimespecs(endRun, startRun))/nsMultDL;
  double mod=1.0;
  if(secs!=0){
    mod=1.0/secs;
  }
  double sItems=((double)nreqs*(nthreads))*mod;

  
  //  printf("Requests/Sec: %lf\n", sItems);
  char q[8]="quit\n";
  int q_len = strlen(q);
  for(i =0;i<nthreads;i++){
    if(verbose){
      printf("Quit[%d]\n", i);
    }
    if(!r_send(q, q_len, i)){
      fprintf(stderr,"Error sending quit\n");
    }
  }

  

  summary_t* hit_read_data = calloc(nthreads*nreqs, sizeof(summary_t));
  summary_t* hit_lat_data = calloc(nthreads*nreqs, sizeof(summary_t));
  summary_t* miss_read_data = calloc(nthreads*nreqs, sizeof(summary_t));
  summary_t* miss_lat_data = calloc(nthreads*nreqs, sizeof(summary_t));
  int max_errors= (nthreads*nreqs)>>2;
  if(max_error<max_error){
    max_errors=max_error;
  }
  int max_timeouts = max_errors;
  summary_t* error_read_data = calloc(max_errors, sizeof(summary_t));
  summary_t* error_lat_data = calloc(max_errors, sizeof(summary_t));
  summary_t* timeout_read_data = calloc(max_timeouts, sizeof(summary_t));
  summary_t* timeout_lat_data = calloc(max_timeouts, sizeof(summary_t));
  int hit_index=0;
  int miss_index=0;
  int error_index=0;
  int timeout_index=0;
  FILE* qnl_fp=NULL;
  if(qnl_collect){
    qnl_fp = fopen("graph_runs/lat_times.txt", "w+");
    if(!qnl_fp){
      fprintf(stderr,"Error opening graph file!\n");
      return -1;
    }
  }
  for(int j=0;j<nthreads;j++){
    unsigned long* ulr=(unsigned long*)readerTimes[j], *ulw=(unsigned long*)writerTimes[j];
    unsigned long* ull=(unsigned long*)latencyTimes[j];
    for(i=1;i<nreqs;i++){
      if(ulr[(i<<1)]&&ulr[(i<<1)+1]&&ulw[(i<<1)]&&ulw[(i<<1)+1]&&ull[(i<<1)]&&ull[(i<<1)+1]){
	char op;
	
	//hit data
	if(isCache[j][i]==PROXY_HIT){
	  hit_read_data[hit_index] = difftimespecs(readerTimes[j][i],writerTimes[j][i]);
	  hit_lat_data[hit_index] = difftimespecs(latencyTimes[j][i],writerTimes[j][i]);
    assert(hit_lat_data[hit_index] > 0);
	  if(hit_lat_data[hit_index] > ((1UL)<<32)){

	  }
	  if(qnl_collect){
	    fprintf(qnl_fp, "%d %lu %lu H\n",
		    j,
		    format_ts(writerTimes[j][i]),
		    format_ts(latencyTimes[j][i]));
	  }
	  hit_index++;
	}

	//miss data
	else if(isCache[j][i]==PROXY_MISS){
	  miss_read_data[miss_index] = difftimespecs(readerTimes[j][i],writerTimes[j][i]);
	  miss_lat_data[miss_index] = difftimespecs(latencyTimes[j][i],writerTimes[j][i]);
    assert(miss_lat_data[miss_index] > 0);
	  if(qnl_collect){
	    fprintf(qnl_fp, "%d %lu %lu M\n",
		    j,
		    format_ts(writerTimes[j][i]),
		    format_ts(latencyTimes[j][i]));
	  }
	  miss_index++;

	}
	else if(isCache[j][i]==PROXY_TIMEOUT){
	  timeout_read_data[timeout_index] = difftimespecs(readerTimes[j][i],writerTimes[j][i]);
	  timeout_lat_data[timeout_index] = difftimespecs(latencyTimes[j][i],writerTimes[j][i]);

	  if(qnl_collect){
	    fprintf(qnl_fp, "%d %lu %lu T\n",
		    j,
		    format_ts(writerTimes[j][i]),
		    format_ts(latencyTimes[j][i]));
	  }
	  timeout_index++;
	}
	//error data
	else{
	  assert(isCache[j][i]==PROXY_ERROR);
	  error_read_data[error_index] = difftimespecs(readerTimes[j][i],writerTimes[j][i]);
	  error_lat_data[error_index] = difftimespecs(latencyTimes[j][i],writerTimes[j][i]);
    assert(error_lat_data[error_index] > 0);
	  if(qnl_collect){
	    fprintf(qnl_fp, "%d %lu %lu E\n",
		    j,
		    format_ts(writerTimes[j][i]),
		    format_ts(latencyTimes[j][i]));
	  }
	  //if saving raw
	  error_index++;
	  if(error_index>max_errors){
	    fprintf(stderr,"No way this data is good\n");
	    exit(0);
	  }
	}

      }
      else{
	fprintf(stderr,"Was error in data collection!\n");
      }
    }
      
  }

  if(qnl_collect){
    fflush(qnl_fp);
  }
  displayResults_csv(miss_read_data, miss_lat_data, miss_index,
		     hit_read_data, hit_lat_data, hit_index,
		     error_read_data, error_lat_data, error_index,
		     timeout_read_data, timeout_lat_data, timeout_index,
		     isCache, rsize);
  return 0; 

}




void displayResults(summary_t* miss_read, summary_t* miss_lat, int miss_count,
		    summary_t* hit_read, summary_t* hit_lat, int hit_count,
		    summary_t* error_read, summary_t* error_lat, int error_count,
		    summary_t* timeout_read, summary_t* timeout_lat, int timeout_count,
		    char** isCache, int** rsize){
  
  printf("--Miss Timing (avg of %d)--\n", miss_count);
  printf("*Total Time*\n");
  print_runtime_summary(miss_read, miss_count);
  printf("*Lat Time*\n");
  print_runtime_summary(miss_lat, miss_count);
  printf("--Hit Timing (avg of %d)--\n", hit_count);
  printf("*Total Time*\n");
  print_runtime_summary(hit_read, hit_count);
  printf("*Lat Time*\n");
  print_runtime_summary(hit_lat, hit_count);
  if(error_count){
    printf("--Error Timing (avg of %d)--\n", error_count);
    printf("*Total Time*\n");
    print_runtime_summary(error_read, error_count);
    printf("*Lat Time*\n");
    print_runtime_summary(error_lat, error_count);
  }
  if(timeout_count){
    printf("--Timeout Timing (avg of %d)--\n", timeout_count);
    printf("*Total Time*\n");
    print_runtime_summary(timeout_read, timeout_count);
    printf("*Lat Time*\n");
    print_runtime_summary(timeout_lat, timeout_count);
  }
  
  normalizeData(miss_read, miss_count,
		hit_read, hit_count,
		error_read, error_count,
		timeout_read, timeout_count,
		isCache, rsize);
  double* miss_read_dbl = (double*)miss_read;
  double* hit_read_dbl = (double*)hit_read;
  double* error_read_dbl = (double*)error_read;
  double* timeout_read_dbl = (double*)timeout_read;
  printf("--Miss Timing (avg of %d)-- [NORMALIZED]\n", miss_count);
  printf("*Total Time*\n");
  print_runtime_summaryDbl(miss_read_dbl, miss_count);
  printf("--Hit Timing (avg of %d)-- [NORMALIZED]\n", hit_count);
  printf("*Total Time*\n");
  print_runtime_summaryDbl(hit_read_dbl, hit_count);
  if(error_count){
    printf("--Error Timing (avg of %d)-- [NORMALIZED]\n", error_count);
    printf("*Total Time*\n");
    print_runtime_summaryDbl(error_read_dbl, error_count);

  }
  if(timeout_count){
    printf("--Timeout Timing (avg of %d)-- [NORMALIZED]\n", timeout_count);
    printf("*Total Time*\n");
    print_runtime_summaryDbl(timeout_read_dbl, timeout_count);

  }
  fflush(stdout);
}




void normalizeData(summary_t* miss_read,int miss_count,
		   summary_t* hit_read,int hit_count,
		   summary_t* error_read,int error_count,
		   summary_t* timeout_read,int timeout_count,
		   char** isCache, int** rsize){
  double* miss_read_dbl = (double*)miss_read;
  double* hit_read_dbl = (double*)hit_read;
  double* error_read_dbl = (double*)error_read;
  double* timeout_read_dbl = (double*)timeout_read;
  int miss_index=0, hit_index=0, error_index=0, timeout_index=0;
  for(int i=0;i<nthreads;i++){
    for(int j=0;j<nreqs;j++){
      if(isCache[i][j]==PROXY_MISS){
	double temp = ((double)miss_read[miss_index])/rsize[i][j];
	miss_read_dbl[miss_index] = temp;
	miss_index++;
      }
      else if(isCache[i][j]==PROXY_HIT){
	double temp = ((double)hit_read[hit_index])/rsize[i][j];
	hit_read_dbl[hit_index] = temp;
	hit_index++;
      }
      else if(isCache[i][j]==PROXY_TIMEOUT){
	double temp = ((double)timeout_read[timeout_index])/rsize[i][j];
	timeout_read_dbl[timeout_index] = temp;
	timeout_index++;
      }
      else{
	double temp = ((double)error_read[error_index])/rsize[i][j];
	error_read_dbl[error_index] = temp;
	error_index++;
      }
    }
  }
  // assert(hit_count == hit_index);
  //  assert(miss_count == miss_index);
  //  assert(error_count == error_index);
  //  assert(timeout_count == timeout_index);
}




void displayResults_csv(summary_t* miss_read, summary_t* miss_lat, int miss_count,
			summary_t* hit_read, summary_t* hit_lat, int hit_count,
			summary_t* error_read, summary_t* error_lat, int error_count,
			summary_t* timeout_read, summary_t* timeout_lat, int timeout_count,
			char** isCache, int** rsize){

  printf("Event, Avg(us), Max(us), Min(us), Stdev(us), Stdev(%%), 50%%(us), 90%%(us), 95%%(us), 99%%(us)\n");
  summary_t* all_resp = (summary_t *)calloc(hit_count + miss_count, sizeof(summary_t));
  int i;
  for(i = 0; i<miss_count; i++){
    all_resp[i] = miss_lat[i];
    assert(all_resp[i] > 0);
  }
  for(;i<(miss_count + hit_count); i++){
    all_resp[i] = hit_lat[i-miss_count];
    assert(all_resp[i] > 0);
  }
  char buf[256] = "";
  sprintf(buf, "Response Time (avg of %d)", miss_count + hit_count);
  print_csv(all_resp, hit_count + miss_count, buf);
  sprintf(buf, "Hit Timing (avg of %d)", hit_count);
  print_csv(hit_read, hit_count, buf);
  sprintf(buf, "Miss Timing (avg of %d)", miss_count);
  print_csv(miss_read, miss_count, buf);
  
  normalizeData(miss_read, miss_count,
		hit_read, hit_count,
		error_read, error_count,
		timeout_read, timeout_count,
		isCache, rsize);
  double* miss_read_dbl = (double*)miss_read;
  double* hit_read_dbl = (double*)hit_read;
  double* error_read_dbl = (double*)error_read;
  double* timeout_read_dbl = (double*)timeout_read;


  sprintf(buf, "Hit Timing (avg of %d) [NORMALIZED]", hit_count);
  print_csvDbl(hit_read_dbl, hit_count, buf);
  sprintf(buf, "Miss Timing (avg of %d) [NORMALIZED]", miss_count);
  print_csvDbl(miss_read_dbl, miss_count, buf);

  fflush(stdout);
}
