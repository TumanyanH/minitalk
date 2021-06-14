# include "minitalk.h"

int send_message(pid_t pid, const char *message)
{
    int counter;
    
    counter = 8;
    while (*message != '\0')
    {
        while (counter--)
        {
            printf("%d\n", (*message / 10));
        }
        ++message;
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
    {
        ft_putstr("USAGE - ./client [pid] [message]\n");
    }
    return (0);
}