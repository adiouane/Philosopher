/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:16:07 by adiouane          #+#    #+#             */
/*   Updated: 2022/06/14 16:32:13 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_info
{
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				times_each_philosopher_must_eat;
	int				time_to_sleep;
	pthread_mutex_t	mutex_msg;
}		t_info;

typedef struct s_philo
{
	int				philo_id;
	long long		start_time;
	int				last_meal_time;
	int				times_eaten;
	pthread_mutex_t	*protect_mutex;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_t		thread_philo;
	t_info			*info;
}		t_philo;

/*********************MANDATORY*********************/

void		creat_thread(t_philo *philo);
long long	ft_atoi(const char *str);
int			ft_strlen(char *str);
void		error(char *str);
int			ft_isdigit(int c);
int			check_argument(char **argv);
long long	current_time(long long start_time);
long long	get_current_time(void);
void		ft_usleep(long long time);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		lock_print(t_philo *philo, int time, char *str);
void		lock_print3(t_philo *philo, int time, char *str);
#endif
