/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:11 by amartel           #+#    #+#             */
/*   Updated: 2026/03/10 20:27:00 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parser.h"

static void	info_prog(void)
{
	(void) write(2, "./philo <number_of_philosophers> ", 34);
	(void) write(2, "<time_to_die> <time_to_eat> <time_to_sleep> ", 45);
	(void) write(2, "[number_of_times_each_philo_must_eat]\n", 39);
}

static void	free_table(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < (size_t) table->data->nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->t_philo[i].meal);
		++i;
	}
	pthread_mutex_destroy(&table->printf_lock);
	pthread_mutex_destroy(&table->stop);
	if (table->t_philo)
		free(table->t_philo);
	if (table->forks)
		free(table->forks);
	free(table->data);
	free(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
	{
		info_prog();
		return (1);
	}
	table = malloc(sizeof(t_table));
	table->data = malloc(sizeof(t_data));
	table->forks = NULL;
	table->t_philo = NULL;
	if (!table || !table->data)
		return (1);
	if (parser(av, table->data) == ERROR)
	{
		free_table(table);
		return (1);
	}
	table->t_philo = malloc(sizeof(t_philo) * table->data->nb_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->data->nb_philo);
	table->is_dead = 0;
	if (table->t_philo && table->forks)
		ft_table(table);
	free_table(table);
	return (0);
}
