/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:57:29 by adiouane          #+#    #+#             */
/*   Updated: 2022/06/14 17:06:25 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	lock_print3(t_philo *philo, int time, char *str)
{
	pthread_mutex_lock(&philo->info->mutex_msg);
	printf("\033[0;32m%d ms \033[0;34mPhilo \033[1;33m%d \033[1;37mhas %s\n",
		time, philo->philo_id, str);
}

void	lock_print2(t_philo *philo, int time, char *str, int number)
{
	pthread_mutex_lock(&philo->info->mutex_msg);
	printf("\033[0;32m%d ms \033[0;34mPhilo \033[1;33m%d \033[1;37mhas %s   #%d\n",
		time, philo->philo_id, str, number);
	pthread_mutex_unlock(&philo->info->mutex_msg);
}

void	lock_print(t_philo *philo, int time, char *str)
{
	pthread_mutex_lock(&philo->info->mutex_msg);
	printf("\033[0;32m%d ms \033[0;34mPhilo \033[1;33m%d \033[1;37mhas %s\n",
		time, philo->philo_id, str);
	pthread_mutex_unlock(&philo->info->mutex_msg);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	lock_print(philo, current_time(philo->start_time), "taken fork");
	pthread_mutex_lock(philo->fork_right);
	lock_print(philo, current_time(philo->start_time), "taken fork");
	pthread_mutex_lock(philo->protect_mutex);
	philo->times_eaten++;
	lock_print2(philo, current_time(philo->start_time), "is eating",
		philo->times_eaten);
	philo->last_meal_time = current_time(philo->start_time);
	pthread_mutex_unlock(philo->protect_mutex);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	sleeping(t_philo *philo)
{
	lock_print(philo, current_time(philo->start_time), "sleeping");
	ft_usleep(philo->info->time_to_sleep);
	lock_print(philo, current_time(philo->start_time), "thinking");
}
