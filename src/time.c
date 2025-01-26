#include "time.h"
#include <time.h>
#include <unistd.h>

double get_time(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1000000000.0;
}

void sleep_until_next_frame(double last_frame_time) {
    double current_time = get_time();
    double next_frame = last_frame_time + FRAME_TIME;
    double sleep_time = next_frame - current_time;
    
    if (sleep_time > 0) {
        struct timespec ts = {
            .tv_sec = (time_t)sleep_time,
            .tv_nsec = (long)((sleep_time - (time_t)sleep_time) * 1000000000.0)
        };
        nanosleep(&ts, NULL);
    }
}
