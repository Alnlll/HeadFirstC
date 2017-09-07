#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void diediedie(int sig)
{
    puts("Goodbye cruel world.");
    exit(1);
}

int signal_register(int sig, void (*handler)(int))
{
    struct sigaction action;        /* create new action */
    action.sa_handler = handler;    /* set signal handler */
    sigemptyset(&action.sa_mask);   /* set filter mask */
    action.sa_flags = 0;

    return sigaction(sig, &action, NULL); /* register action */
}

int main(void)
{
    char name[30] = {0};

    if (-1 == signal_register(SIGINT, diediedie))
    {
        fprintf(stderr, "Cannot map the handler.\n");
        exit(2);
    }

    printf("Enter your name:\n");
    fgets(name, 30, stdin);
    printf("Hello: %s\n", name);

    return 0;
}
