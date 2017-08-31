#include <stdio.h>
#include "../include/checksum.h"

int checksum(char *message)
{
	int csum = 0;

	while (*message)
	{
		csum += csum ^ (int)*message;
		message++;
	}

	return csum;
}
