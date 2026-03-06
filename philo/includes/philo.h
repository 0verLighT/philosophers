/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:54:32 by amartel           #+#    #+#             */
/*   Updated: 2026/03/06 20:59:23 by amartel          ###   ########.fr       */
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
# include "parser.h"

# define ERROR_CODE -1

typedef struct s_data
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_before_end;
}	t_data;

typedef struct s_table
{
	pthread_t	thread_table;
	size_t		i;
	pthread_mutex_t	locker;
}	t_table;

typedef struct s_philo
{
	pthread_t	thread_philo;
	size_t		id;
	t_table		*table;
}	t_philo;

t_philo	*create_philo(size_t id, t_table *table);
#endif
