/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:54:32 by amartel           #+#    #+#             */
/*   Updated: 2026/03/20 00:30:52 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "action.h"
# include <sys/time.h>

# define ERROR -1

typedef struct s_data
{
	int	nb_philo;
	int	td;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_before_end;
}	t_data;

typedef struct s_table
{
	long			time;
	t_data			*data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf_lock;
	pthread_mutex_t	stop;
	struct s_philo	*t_philo;
	int				is_dead;
}	t_table;

typedef struct s_philo
{
	pthread_t		thread_philo;
	pthread_mutex_t	meal;
	long			last_meal;
	size_t			id;
	size_t			left;
	size_t			right;
	size_t			nb_eat;
	t_table			*table;
}	t_philo;

int		create_philo(t_table *table);
int		ft_table(t_table *table, size_t i);
void	philo_alone(t_philo *philo);
void	thread_printf(t_philo *philo, char *state);
void	anyone_dead(t_table *table, size_t i);
void	content_routine(t_philo *philo, int first, int second);
void	ft_usleep(long ms);

#endif
