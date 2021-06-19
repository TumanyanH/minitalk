#ifndef MINITALK_H_
# define MINITALK_H_

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

void        ft_putstr(const char* str);
char		*ft_itoa(int n);
int	        ft_atoi(const char *str);
int         power(int num, int power);

typedef struct s_data {
    unsigned char byte;
    int counter;
} t_data;

#endif