

#include "displayML15.h"
#include "keyboardML15.h"
#include "drill.h"
#include "clock.h"

const int pattern [21] = 
{0,1,1,1,1,1,1,1,2,1,5,2,2,2,2,4,4,3,8,2,0xFF};

void main (void)
{
	init_clock();
	while(1)
	{
		switch (get_key())
		{
		case 0:
			motor_start();
			break;
		case 1:
			motor_stop();
			break;
		case 2:
			drill_down();
			break;
		case 3:
			drill_up();
			break;
		case 4:
			step();
			break;
		case 5:
			drill_hole();
			break;
		case 6:
			ref_pos();
			break;
		case 7:
			do_auto(pattern);
			break;
		}
	}
}
