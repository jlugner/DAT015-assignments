
#include "ports.h"
#include "Helpers.h"
#include "drill.h"
#include "clock.h"

port8 dcShadow = 0;

void motor_start(void)
{
	set(dcShadow,0x04);
	DrillControl = dcShadow;
	hold(1000UL);
}

void motor_stop(void)
{
	clear(dcShadow,0x04);
	DrillControl = dcShadow;
}

void drill_down(void)
{
   set(dcShadow,0x08);
   DrillControl = dcShadow;
}

void drill_up(void)
{
	clear(dcShadow,0x08);
	DrillControl = dcShadow;
	hold(500UL);
}

void alarm(int counter)
{
	while (counter)
	{
		set(dcShadow,0x10);
		DrillControl = dcShadow;
		
		hold(1000UL);
		
		clear(dcShadow,0x10);
		DrillControl = dcShadow;
		hold(500UL);
		counter--;
	}
}

int step(void)
{
   if (dcShadow & 0x08)
   {
      alarm(3);
      return 0;
   }
   
   set(dcShadow,0x3);
   DrillControl= dcShadow;
   
   hold(500UL);
   
   clear(dcShadow,0x1);
   DrillControl = dcShadow;
   
   return 1;
}

int drill_down_test(void)
{
	int i = 0;
	for (; i <= 20; i++ )
	{
		if (DrillStatus & 0x04)
			return 1;
			
		hold(250UL);
	}
	alarm(2);
	return 0;
}

int n_step(int nSteps)
{
	while (nSteps)
	{
		if (!step())
			return 0;
		nSteps--;
	}
	return 1;
}

void drill_hole(void)
{
	drill_down();
	drill_down_test();
	drill_up();
}

int ref_pos(void)
{
	while (!(DrillStatus & 0x01))
		if(!step())
			return 0;
	return 1;
}

void do_auto(const int *pattern)
{
	int *iterator = pattern;
	
	if (!ref_pos())
		return;
	
	motor_start();
	
	for (; *iterator != 0xFF; iterator++)
	{
		n_step(*iterator);
		drill_hole();
	}
	
	motor_stop();
}

