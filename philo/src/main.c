/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:11 by amartel           #+#    #+#             */
/*   Updated: 2026/03/11 19:15:25 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

static void	info_prog(void)
{
	(void) write(2, "./philo <number_of_philosophers> ", 34);
	(void) write(2, "<time_to_die> <time_to_eat> <time_to_sleep> ", 45);
	(void) write(2, "[number_of_times_each_philo_must_eat]\n", 39);
}

static void	free_destroy(t_table *table)
{
	size_t	i;

	i = 0;
	pthread_mutex_destroy(&table->printf_lock);
	pthread_mutex_destroy(&table->stop);
	while (&table->forks[i] && &table->t_philo[i] && i
		< (size_t) table->data->nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->t_philo[i].meal);
		++i;
	}
}

static void	free_table(t_table *table, int i)
{
	if (!i)
		free_destroy(table);
	if (table->t_philo)
		free(table->t_philo);
	if (table->forks)
		free(table->forks);
	if (table->data)
		free(table->data);
	if (table)
		free(table);
}

static int	parser(char **av, t_data *data)
{
	data->eat_before_end = -1;
	data->nb_philo = ft_atoi(av[1]);
	if (data->nb_philo == ERROR || data->nb_philo > 200 || data->nb_philo < 1)
		return (ERROR);
	data->td = ft_atoi(av[2]);
	if (data->td == ERROR || data->td < 1)
		return (ERROR);
	data->time_to_eat = ft_atoi(av[3]);
	if (data->time_to_eat == ERROR || data->time_to_eat < 1)
		return (ERROR);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->time_to_sleep == ERROR || data->time_to_sleep < 1)
		return (ERROR);
	if (av[5])
	{
		data->eat_before_end = ft_atoi(av[5]);
		if (data->eat_before_end == ERROR || data->eat_before_end < 1)
			return (ERROR);
	}
	return (0);
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
	if (!table)
		return (1);
	table->data = malloc(sizeof(t_data));
	table->forks = NULL;
	table->t_philo = NULL;
	if (!table->data || parser(av, table->data) == ERROR)
	{
		free_table(table, 1);
		return (1);
	}
	table->t_philo = malloc(sizeof(t_philo) * table->data->nb_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->data->nb_philo);
	table->is_dead = 0;
	if (table->t_philo && table->forks && table)
		ft_table(table, 0);
	free_table(table, 0);
	return (0);
}
