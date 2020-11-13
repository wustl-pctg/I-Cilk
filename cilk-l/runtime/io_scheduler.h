#ifndef INCLUDE_IO_SCHEDULER_H
#define INCLUDE_IO_SCHEDULER_H

#include <internal/abi.h>

#ifdef __cplusplus
extern "C" {
#endif

void* scheduler_thread_proc_for_io_worker(void* arg);
void make_worker_io(__cilkrts_worker *w);

#ifdef __cplusplus
}
#endif

#endif
