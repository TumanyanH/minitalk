# include "minitalk.h"

static void handler(int signum)
{
    printf("%d -- \n", signum);
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    printf("server pid - %d\n", getpid());
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}