/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:40:55 by amartel           #+#    #+#             */
/*   Updated: 2026/03/09 03:51:16 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "action.h"

void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(1500);
	while (1)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left]);
		philo->time = get_time_ms() - philo->table->time;
		printf("[%ld] %zu %s\n", philo->time, philo->id, FORK);
		pthread_mutex_lock(&philo->table->forks[philo->right]);
		philo->time = get_time_ms() - philo->table->time;
		printf("[%ld] %zu %s\n", philo->time, philo->id, FORK);
		philo->time = get_time_ms() - philo->table->time;
		printf("[%ld] %zu %s\n", philo->time, philo->id, EAT);
		usleep(philo->table->data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->table->forks[philo->left]);
		pthread_mutex_unlock(&philo->table->forks[philo->right]);
		philo->time = get_time_ms() - philo->table->time;
		printf("[%ld] %zu %s\n", philo->time, philo->id, SLEEP);
		usleep(philo->table->data->time_to_sleep * 1000);
		philo->time = get_time_ms() - philo->table->time;
		printf("[%ld] %zu %s\n", philo->time, philo->id, THINK);
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
