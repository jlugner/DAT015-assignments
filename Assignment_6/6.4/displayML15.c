
#include "ports.h"
#include "displayML15.h"

void display_digits (unsigned char values [6])
{
	int i = 0;
	//Init the display, make sure it's ready for new data
	ML15DSP_MODE = 1;
	ML15DSP_DATA = 0x90;
	ML15DSP_MODE = 0;
	
	
	for (i = 0; i < 8; i++)
	{
		ML15DSP_DATA = i >= 6 ? 0 : values[i];
	}
	
	
}

void display_dec(unsigned int decimal)
{
   unsigned char to_display[6];
   int i;
   
   for (i = 5; i >= 0; i--)
   {
      to_display[i] = decimal % 10;
      decimal/=10;
   }
   
   display_digits(to_display);
}


