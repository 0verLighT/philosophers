/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:40:55 by amartel           #+#    #+#             */
/*   Updated: 2026/03/24 00:30:13 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "action.h"

void	thread_printf(t_philo *philo, char *state)
{
	long	time;

	if ((ft_strcmp(state, EAT) == 0)
		&& philo->table->data->eat_before_end != -1)
	{
		// pthread_mutex_lock(&philo->meal);
		++philo->nb_eat;
		// pthread_mutex_unlock(&philo->meal);
	}
	// pthread_mutex_lock(&philo->table->printf_lock);
	time = get_time_ms() - philo->table->time;
	// pthread_mutex_lock(&philo->table->stop);
	if (!philo->table->is_dead)
		printf("[%ld] %zu %s\n", time, philo->id, state);
	// pthread_mutex_unlock(&philo->table->stop);
	// pthread_mutex_unlock(&philo->table->printf_lock);
}

int	is_finished(t_philo *philo)
{
	int	is_end;

	// pthread_mutex_lock(&philo->table->stop);
	is_end = philo->table->is_dead;
	// pthread_mutex_unlock(&philo->table->stop);
	return (is_end);
}

void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->data->nb_philo == 1)
		philo_alone(philo);
	if (philo->id % 2)
		ft_usleep(philo->table->data->time_to_eat, philo);
	while (!is_finished(philo) && philo->table->data->nb_philo != 1)
		content_routine(philo, 0, 0);
	return (NULL);
}

int	create_philo(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < (size_t) table->data->nb_philo)
	{
		if (pthread_create(&table->t_philo[i].thread_philo, NULL,
				&routine_philo, &table->t_philo[i]) != 0)
		{
			printf("thread cannot be created\n");
			return (0);
		}
		++i;
	}
	return (1);
}

int	ft_table(t_table *table, size_t i)
{
	while (i < (size_t) table->data->nb_philo)
	{
		table->t_philo[i].id = i + 1;
		table->t_philo[i].left = i;
		table->t_philo[i].right = (i + 1) % table->data->nb_philo;
		table->t_philo[i].table = table;
		table->t_philo[i].last_meal = get_time_ms();
		table->t_philo[i].nb_eat = 0;
	}
	table->time = get_time_ms();
	if (!create_philo(table))
		return (0);
	anyone_dead(table, 0);
	i = 0;
	while (i < (size_t) table->data->nb_philo)
		pthread_join(table->t_philo[i++].thread_philo, NULL);
	return (1);
}
