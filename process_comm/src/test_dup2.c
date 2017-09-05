#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct
{
	char *diner;
	char *env[2];
} cmd;

void error(char *message)
{
	printf("%s:%s\n", message, strerror(errno));
	exit(1);
}

int main(void)
{
	int i = 0;
	pid_t pid = 0;
	FILE *file = NULL;
	int pid_status = 0;

	file = fopen("diner.txt", "w");
	if (NULL == file)
	{
		error("Cannot open file");
	}

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
			error("Fork fail");
		}

		if (-1 == dup2(fileno(file), 1))
		{
			error("Redirect fail");
		}

		if (!pid)
		{
			sleep(10);
			printf("index:%d\n", i);
			if (-1 == execle("./diner", "./diner", test[i].diner, NULL, test[i].env))
			{
				error("Execl fail");
			}
			return 0;
		}

		if (-1 == waitpid(pid, &pid_status, 0))
		{
			printf("Wait %d process error: %s", pid, strerror(errno));
			return -1;
		}
	}

	return 0;

}