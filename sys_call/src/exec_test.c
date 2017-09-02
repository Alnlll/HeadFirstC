#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *my_env[] = {"JUICE=peach&apple", NULL};

	execle("./diner", "./diner", "4", NULL, my_env);

	return 0;
}