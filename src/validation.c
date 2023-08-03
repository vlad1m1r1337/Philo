#include "../include/philo.h"

int number_check(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j = 1;
		else
			j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int zero_positive_empty_check(char **argv)
{
	int i;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) == 0)
			return (1);
		if (argv[i][0] == '\0')
			return (1);
	}
	return (0);
}

int	validation(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (1);
	if (!(number_check(argv) + zero_positive_empty_check(argv)))
		return (1);
	return (0);
}
