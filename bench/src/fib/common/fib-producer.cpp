#include <sys/types.h>
#include <unistd.h>

#include <sys/timerfd.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fib/common/fib-producer.h"

int create_producer(int usec_timeout) {
    int timer_fd = timerfd_create(CLOCK_MONOTONIC, 0);

    struct itimerspec timeout;
    timeout.it_interval = {
        .tv_sec = usec_timeout / 1000000,
        .tv_nsec = (usec_timeout % 1000000) * 1000
    }; 

    timeout.it_value = timeout.it_interval;

    timerfd_settime(timer_fd, 0, &timeout, NULL);

    return timer_fd;
}

int create_oneshot_producer(int usec_timeout) {
    int timer_fd = timerfd_create(CLOCK_MONOTONIC, 0);

    struct itimerspec timeout;
    timeout.it_value = {
        .tv_sec = usec_timeout / 1000000,
        .tv_nsec = (usec_timeout % 1000000) * 1000
    }; 

    if (timeout.it_value.tv_sec == 0 && timeout.it_value.tv_nsec == 0) {
        timeout.it_value.tv_nsec = 1;
    }

    memset(&timeout.it_interval, 0, sizeof(timeout.it_value));

    timerfd_settime(timer_fd, 0, &timeout, NULL);

    return timer_fd;
}
