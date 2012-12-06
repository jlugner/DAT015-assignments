
#include "clock.h"

extern void init_irq(void (*f)(void));

volatile time_type counter;

void init_clock (void)
{
	counter = 0;
	init_irq(clock_inter);
}

void clock_inter(void)
{	
	counter++;			
}

time_type get_time (void)
{
	return counter * 10;
}

void hold (time_type delay)
{
	time_type init = get_time();
	
	while(get_time() <= (init + delay))
		;
		
	return;
}


