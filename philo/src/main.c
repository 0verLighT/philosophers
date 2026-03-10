/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:11 by amartel           #+#    #+#             */
/*   Updated: 2026/03/10 04:11:57 by amartel          ###   ########.fr       */
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

static void free_table(t_table *table)
{
	size_t i;

	i = 0;
	while (i < (size_t) table->data->nb_philo)
	{
		pthread_mutex_destroy(table->forks);
		
		++i;
	}
	pthread_mutex_destroy(&table->printf_lock);
	free(table->t_philo);
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
	if (!table || !table->data)
		return (1);
	if (parser(av, table->data) == ERROR)
	{
		free_table(table);
		return (1);
	}
	table->is_dead = 0;
	ft_table(table);
	free_table(table);
	return (0);
}
