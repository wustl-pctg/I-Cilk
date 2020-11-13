#pragma once

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

void* worker_allocation_scheduler(void* args);

int64_t cilk_prio_get_current_time_tsc_ticks();

#ifdef __cplusplus
}
#endif
