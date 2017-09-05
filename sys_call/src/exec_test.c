#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

typedef struct
{
	char *diner;
	char *env[2];
} cmd;

int main(void)
{
	int i = 0;
	pid_t pid = 0;

	cmd test[3] = 
	{
		{"apple", {"JUICE=peach", NULL}},
		{"banana", {"JUICE=apple", NULL}},
		{"pinapple", {"JUICE=strawberry", NULL}},
	};

	char *my_env[] = {"JUICE=peach&apple", NULL};

	for (i = 0; i < sizeof(test) / sizeof(test[0]); i++)
	{
		pid = fork();
		if (-1 == pid)
		{
			fprintf(stderr, "Fork fail: %s\n", strerror(errno));
			return -1;
		}

		if (!pid)
		{
			printf("index:%d\n", i);
			if (-1 == execle("./diner", "./diner", test[i].diner, NULL, test[i].env))
			{
				fprintf(stderr, "Execl fail: %s\n", strerror(errno));
				return -1;
			}
			return 0;
		}
	}

	return 0;

}