# include "minitalk.h"

t_data data;

void init_data()
{
    data.byte = 0x00;
    data.counter = 7;
}

static void handler(int signum)
{
    if (data.counter > 0)
        data.byte = data.byte << 1;
    if (signum == SIGUSR1)
        data.byte = data.byte | 1;
    data.counter--;
    if (data.counter < 0)
    {
        write(1, &data.byte, 1);
        init_data();
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    init_data();
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