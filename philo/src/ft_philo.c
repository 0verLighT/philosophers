/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:40:55 by amartel           #+#    #+#             */
/*   Updated: 2026/03/07 04:30:50 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->frok);
		philo->time = get_time_ms() - philo->table->time;
		printf("[%ld] The philo %zu eat for the N time\n",philo->time, philo->id);
		pthread_mutex_unlock(&philo->frok);
		usleep(100);
	}
	return (NULL);
}

t_philo	*create_philo(size_t id, t_table *shared_table)
{
	t_philo			*philo;

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

// t_table *ft_table(t_data *data)
// {
// 	t_table	*table;
// 	size_t	i;

// 	table = malloc(sizeof(t_table));
// 	if (!table)
// 		return (NULL);
// 	i = 1;
// 	table->time = get_time_ms();
// 	while (i <= data->nb_philo)
// 	{
// 		pthread_join()
// 	}
// 	return (table);
// }
