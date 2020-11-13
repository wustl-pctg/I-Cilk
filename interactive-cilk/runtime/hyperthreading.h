#pragma once

#ifdef __cplusplus
extern "C" {
#endif

unsigned int num_hyperthreads_per_core();

bool hyperthreading_is_enabled();

#ifdef __cplusplus
}
#endif
