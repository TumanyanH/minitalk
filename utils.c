#include "minitalk.h"

void ft_putstr(const char* str)
{
    int i = 0;

    while (str[i])
    {
        write(1, &str[i], 1);
        ++i;
    }
}

int	ft_atoi(const char *str)
{
	int neg;
	int i;
	int num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

static int	nbrlen(int nbr)
{
	int i;

	i = (nbr <= 0) ? 1 : 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		nbr /= 10;
		++i;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;

	nbr = n;
	len = nbrlen(nbr);
	if (!(str = malloc(sizeof(unsigned char) * (len + 1))))
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nbr)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
		--len;
	}
	return (str);
}

int power(int num, int power)
{
	while (power--)
		num *= num;
	return (num);
}