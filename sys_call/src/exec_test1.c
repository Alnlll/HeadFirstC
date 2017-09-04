#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	if (-1 == execl("/sbin/ifconfig", "/sbin/ifconfig", NULL))
	{
		if (-1 == execlp("ifconfig", "ifconfig", NULL))
		{
			fprintf(stderr, "Cannot run ipconfig: %s\n", strerror(errno));
			return -1;
		}
	}

	return 0;
}