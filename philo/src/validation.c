/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:35:20 by vgribkov          #+#    #+#             */
/*   Updated: 2023/08/10 18:54:16 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	number_check(char **argv)
{
	int	i;
	int	j;

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

int	zero_positive_empty_check(char **argv)
{
	int	i;

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

int	ft_atoi_checker(const char *str)
{
	int		mcount;
	int		i;
	long	result;

	i = 0;
	result = 0;
	mcount = 1;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-')
	{
		mcount = mcount * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= 9 + '0' && str[i] >= 0 + '0')
	{
		result = 10 * result + str[i] - '0';
		i++;
		if (!(result * mcount >= -2147483648 && result * mcount <= 2147483647))
			return (1);
	}
	return (0);
}

int	int_max_checker(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoi_checker(argv[i]))
			return (1);
	}
	return (0);
}

int	validation(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (number_check(argv) + zero_positive_empty_check(argv) \
		+ int_max_checker(argv))
		return (1);
	return (0);
}
