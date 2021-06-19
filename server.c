# include "minitalk.h"

static void handler(int signum)
{
    static unsigned char a = 0;
    static int counter = 7;

    if (counter > 0)
        a = a << 1;
    if (signum == SIGUSR1)
    {
        a = a | 1;
        printf("1\n");

    }
    else 
        printf("0\n");

    counter--;
    printf("%c\n", a);
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
    while (1);
    return 1;
}

// 0000_0000
// 0000_0001
// _________
// 0000_0010
// << 