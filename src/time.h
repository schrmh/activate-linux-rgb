#ifndef INCLUDE_TIME_H
#define INCLUDE_TIME_H

#include <time.h>

double get_time(void);
void sleep_until_next_frame(double last_frame_time);

#define FRAME_TIME (1.0 / 60.0)

#endif
