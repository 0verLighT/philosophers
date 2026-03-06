/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:40:55 by amartel           #+#    #+#             */
/*   Updated: 2026/03/06 21:08:51 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *arg)
{
	t_philo	*philo;
	philo = (t_philo *)arg;
	printf("I'm alive ! now\n ID : %zu\n", philo->id);
	while (1)
	{
		pthread_mutex_lock(&philo->table->locker);
		++philo->table->i;
		printf("The philo %zu eat for the %s time\n", philo->id, philo->table->i);
		pthread_mutex_unlock(&philo->table->locker);
		usleep(10000);
	}
	return (NULL);
}

t_philo	*create_philo(size_t id, t_table *shared_table)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->table = shared_table;
	
	if (pthread_create(&philo->thread_philo, NULL, &routine_philo, (void *)philo) != 0)
	{
		printf("thread cannot be created\n");
		free(philo);
		return (NULL);
	}
	return (philo);
}
