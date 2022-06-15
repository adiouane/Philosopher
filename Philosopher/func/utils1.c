/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:14:57 by adiouane          #+#    #+#             */
/*   Updated: 2022/06/14 17:03:53 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	current_time(long long start_time)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	return (te.tv_sec * 1000 + te.tv_usec / 1000 - start_time);
}

long long	get_current_time(void)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	return (te.tv_sec * 1000 + te.tv_usec / 1000);
}

int	norm_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0)
		{
			error("Error: invalide argument\n");
			return (1);
		}
		if (argv[i][0] == '\0')
		{
			error("Error number\n");
			return (1);
		}
		if ((argv[i][0] == '-') && argv[i][1])
		{
			error("Error: invalide argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_argument(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		if (norm_check(argv) == 1)
			return (1);
		while (argv[i][k])
		{
			if (!ft_isdigit(argv[i][k]))
			{
				error("Error: invalide argument\n");
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	number;

	i = 0;
	sign = 1;
	number = 0;
	while (((str[i] >= 7 && str[i] <= 13) || (str[i] == ' ')))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - '0');
		if (number > 2147483647)
			return (0);
		i++;
	}
	return (number * sign);
}
