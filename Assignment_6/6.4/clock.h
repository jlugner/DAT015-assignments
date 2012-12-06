

#ifndef CLOCK_H
#define CLOCK_H

typedef unsigned long int time_type;

void init_clock (void);
void clock_inter(void);
time_type get_time (void);
void hold (time_type); 

#endif
