/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:40:55 by amartel           #+#    #+#             */
/*   Updated: 2026/03/10 04:32:30 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "action.h"

void	thread_printf(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->table->printf_lock);
	printf("[%ld] %zu %s\n", philo->time, philo->id, state);
	pthread_mutex_unlock(&philo->table->printf_lock);
}

int	is_finished(t_philo *philo)
{
	int	is_end;

	pthread_mutex_lock(&philo->table->stop);
	is_end = philo->table->is_dead;
	if (is_digit)
		thread_printf(philo, DEAD);
	pthread_mutex_unlock(&philo->table->stop);
	return (is_end);
}

void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(1500);
	while (!is_finished(philo))
	{
		pthread_mutex_lock(&philo->table->forks[philo->left]);
		philo->time = get_time_ms() - philo->table->time;
		thread_printf(philo, FORK);
		pthread_mutex_lock(&philo->table->forks[philo->right]);
		philo->time = get_time_ms() - philo->table->time;
		thread_printf(philo, FORK);
		philo->time = get_time_ms() - philo->table->time;
		thread_printf(philo, EAT);
		usleep(philo->table->data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->table->forks[philo->left]);
		pthread_mutex_unlock(&philo->table->forks[philo->right]);
		philo->time = get_time_ms() - philo->table->time;
		thread_printf(philo, SLEEP);
		usleep(philo->table->data->time_to_sleep * 1000);
		philo->time = get_time_ms() - philo->table->time;
		thread_printf(philo, THINK);
	}
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

int	ft_table(t_table *table)
{
	size_t	i;

	i = 0;
	table->t_philo = malloc(sizeof(t_philo) * table->data->nb_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->data->nb_philo);
	if (!table->t_philo || !table->forks)
		return (0);
	while (i < (size_t) table->data->nb_philo)
	{
		table->t_philo[i].id = i + 1;
		table->t_philo[i].left = i;
		table->t_philo[i].right = (i + 1) % table->data->nb_philo;
		table->t_philo[i].table = table;
		pthread_mutex_init(&table->forks[i], NULL);
		pthread_mutex_init(&table->printf_lock, NULL);
		pthread_mutex_init(&table->stop, NULL);
		++i;
	}
	table->time = get_time_ms();
	if (!create_philo(table))
		return (0);
	i = 0;
	while (i < (size_t) table->data->nb_philo)
		pthread_join(table->t_philo[i++].thread_philo, NULL);
	return (1);
}
