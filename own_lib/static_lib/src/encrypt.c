#include <stdio.h>
#include "../include/encrypt.h"

char *encrypt(char *message)
{
	while (*message)
	{
		*message ^= 31;
		message++;
	}
}
