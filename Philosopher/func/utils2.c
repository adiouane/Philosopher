/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:55:35 by adiouane          #+#    #+#             */
/*   Updated: 2022/06/14 17:00:36 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

void	creat_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->number_of_philosopher)
	{
		philo[i].start_time = current_time(0);
		if (pthread_create(&philo[i].thread_philo, NULL, &action,
				(void *)&philo[i]) == -1)
		{
			error("Error: pthread_create\n");
			return ;
		}
		usleep(100);
		i++;
	}
}

void	ft_usleep(long long time)
{
	long long	num;

	num = get_current_time();
	while (get_current_time() - num < time)
		usleep(500);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
