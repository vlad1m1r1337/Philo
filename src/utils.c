#include "../include/philo.h"

int	ft_atoi(const char *str)
{
	int	mult;
	int	res;

	mult = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		mult *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	return (res * mult);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void putstr_err(char* str)
{
	if (!str)
		return ;
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

long get_time(void)
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long t_eat)
{
	long 	start;

	start = get_time();
	usleep(t_eat * 950);
	while (get_time() - start < t_eat)
		usleep(10);
}
