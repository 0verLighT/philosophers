/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:07:00 by amartel           #+#    #+#             */
/*   Updated: 2026/03/24 00:30:37 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	philo_alone(t_philo *philo)
{
	while (1)
	{
		thread_printf(philo, FORK);
		return ;
	}
}

static int	require_eat(t_table *table, size_t philo_complete)
{
	if (table->data->eat_before_end != -1 && (size_t) table->data->nb_philo
		<= philo_complete)
	{
		// pthread_mutex_lock(&table->stop);
		table->is_dead = 1;
		// pthread_mutex_unlock(&table->stop);
		return (1);
	}
	return (0);
}

static void	anyone_finish_eat(t_table *table, size_t *philo_complete, size_t i)
{
	if ((size_t) table->data->eat_before_end != 1 && table->t_philo[i].nb_eat
		>= (size_t) table->data->eat_before_end)
		++*philo_complete;
}

void	anyone_dead(t_table *table, size_t i)
{
	size_t	philo_complete;

	while (1)
	{
		i = 0;
		philo_complete = 0;
		while (i < (size_t) table->data->nb_philo)
		{
			// pthread_mutex_lock(&table->t_philo[i].meal);
			if (get_time_ms() - table->t_philo[i].last_meal > table->data->td)
			{
				thread_printf(&table->t_philo[i], DEAD);
				// pthread_mutex_lock(&table->stop);
				table->is_dead = 1;
				// pthread_mutex_unlock(&table->stop);
				// pthread_mutex_unlock(&table->t_philo[i].meal);
				return ;
			}
			anyone_finish_eat(table, &philo_complete, i);
			// pthread_mutex_unlock(&table->t_philo[i++].meal);
		}
		if (require_eat(table, philo_complete))
			return ;
		usleep(1);
	}
}
