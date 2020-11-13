#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define IDLE_STATS__IDLE_STATE      (0)
#define IDLE_STATS__ACTIVE_STATE    (1)

typedef struct idle_stats_t {
  int scheduling_level;
  int state;
  int64_t idle_time;
  int64_t active_time; // TODO: May only need the idle time
  int64_t state_entered_time;
//  int64_t level_start_time;
} idle_stats_t;

#ifdef __cplusplus
}
#endif
