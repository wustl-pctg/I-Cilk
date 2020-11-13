#ifndef INCLUDED_CILK_IO_H
#define INCLUDED_CILK_IO_H

#include <sys/types.h>
#include <sys/socket.h>

#ifdef __cplusplus

#include <cilk/future.h>


extern "C" {

#endif

typedef struct io_future_result {
  ssize_t ret_val;
  int     errno_val;
} io_future_result;

typedef struct io_future {
  void *f; // A pointer to the underlying future type (c++ object)
} io_future;

/** Asynchronous Functions (return a future) **/
// Simple IO functions
extern io_future cilk_read(int fildes, void *buf, size_t nbyte);
extern io_future cilk_write(int fildes, void *buf, size_t nbyte);


// Socket functions
extern io_future cilk_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

extern io_future_result cilk_iosync(io_future *fut);

/** "Synchronous" Functions **/
extern ssize_t cilk_read_sync(int fildes, void *buf, size_t nbyte); 
extern ssize_t cilk_write_sync(int fildes, void *buf, size_t nbyte);
extern int cilk_accept_sync(int sockfd, struct sockaddr *addr, socklen_t *addrlen);


#ifdef __cplusplus

}

typedef cilk::future<io_future_result> base_io_fut;

extern void cilk_read(base_io_fut *fut, int fildes, void *buf, size_t nbyte);
extern void cilk_write(base_io_fut *fut, int fildes, void *buf, size_t nbyte);
extern void cilk_accept(base_io_fut *fut, int sockfd, struct sockaddr *addr, socklen_t *addrlen);

#endif

#endif
