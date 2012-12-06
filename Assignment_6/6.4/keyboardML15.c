
#include "ports.h"
#include "keyboardML15.h"

char key = 0;

char get_key( void )
{
	char tmp;
	
	while(key == KEYOUT)
		;
		
	do
	{
		tmp = KEYOUT;
	} while (tmp & 0x80);
	
	key = tmp;
	
	return tmp;
}
