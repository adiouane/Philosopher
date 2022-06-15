/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:11:14 by adiouane          #+#    #+#             */
/*   Updated: 2022/06/14 02:14:39 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	error(char *str)
{
	write(2, str, ft_strlen(str));
}

int	check_if_philosopher_is_dead(t_philo *philo)
{
	int	i;
	int	end_eating;

	i = 0;
	if (philo->info->times_each_philosopher_must_eat)
		end_eating = 1;
	else
		end_eating = 0;
	while (i < philo->info->number_of_philosopher)
	{
		pthread_mutex_lock(philo[i].protect_mutex);
		if (philo[i].times_eaten < philo->info->times_each_philosopher_must_eat)
			end_eating = 0;
		if (current_time(philo[i].start_time)
			- philo[i].last_meal_time >= philo[i].info->time_to_die)
		{
			lock_print3(philo, current_time(philo[i].start_time), "has died");
			return (1);
		}
		pthread_mutex_unlock(philo[i].protect_mutex);
		i++;
	}
	if (end_eating)
		return (1);
	return (0);
}

void	inisalize_norm(int argc, char **argv, t_info *info)
{
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		info->times_each_philosopher_must_eat = 0;
	if (pthread_mutex_init(&info->mutex_msg, NULL) == -1)
		error ("Error: mutex_msg");
}

void	inisalize_philo(t_philo *philo, int argc, char **argv, t_info *info)
{
	int				i;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*mutex_protect;

	mutex_protect = malloc(sizeof(pthread_mutex_t)
			* info->number_of_philosopher);
	mutex = malloc(sizeof(pthread_mutex_t) * info->number_of_philosopher);
	inisalize_norm(argc, argv, info);
	i = 0;
	while (i < info->number_of_philosopher)
	{
		philo[i].philo_id = i + 1;
		philo[i].times_eaten = 0;
		if (pthread_mutex_init(&mutex[i], NULL) == -1)
			error ("pthread_mutex_init failed\n");
		if (pthread_mutex_init(&mutex_protect[i], NULL) == -1)
			error ("pthread_mutex_init failed\n");
		philo[i].protect_mutex = &mutex_protect[i];
		philo[i].fork_left = &mutex[i];
		philo[i].fork_right = &mutex[(i + 1) % info->number_of_philosopher];
		philo[i].info = info;
		philo[i].last_meal_time = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_info	info;

	if (argc == 5 || argc == 6)
	{
		if (check_argument(argv) == 1)
			return (0);
		info.number_of_philosopher = ft_atoi(argv[1]);
		philo = (t_philo *)malloc(sizeof(t_philo) * info.number_of_philosopher);
		inisalize_philo(philo, argc, argv, &info);
		creat_thread(philo);
		while (1)
		{
			if (check_if_philosopher_is_dead(philo))
				return (0);
		}
	}
	else
		error ("Error argument!\n");
}
