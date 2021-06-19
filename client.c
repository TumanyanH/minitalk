# include "minitalk.h"

int send_message(pid_t pid, const char *message)
{
    int counter;
    int i = 0;

    counter = 7 ;
    while (message[i])
    {
        while (counter-- >= 0)
        {
            usleep(100);
            if ((message[i] >> counter) & 0x01)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
        }
        i++;
        counter = 7;
    }
    return (0);
}

int main(int argc, char **argv)
{
    char *message;
    pid_t pid;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        message = argv[2];
        send_message(pid, message);
    } 
    else 
        ft_putstr("USAGE - ./client [pid] [message]\n");
    return (0);
}