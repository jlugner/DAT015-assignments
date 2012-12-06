#ifndef DRILL_H
#define DRILL_H

void motor_start(void);
void motor_stop(void);
void drill_down(void);
void drill_up(void);
int n_step(int);
int drill_down_test(void);
void alarm(int);
void drill_hole(void);
int ref_pos(void);
void do_auto(const int *pattern);
int step(void);

#endif
