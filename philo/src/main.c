/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:11 by amartel           #+#    #+#             */
/*   Updated: 2026/03/06 21:08:10 by amartel          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	*data;
	t_table	*table;

	data = malloc(sizeof(t_data));
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (ac < 5 || ac > 6)
	{
		info_prog();
		return (1);
	}
	if (parser(av, data) == ERROR)
		return (2);
	t_philo *p1, *p2;
	table->i = 0;
	pthread_mutex_init(&table->locker, NULL);
	p1 = create_philo(1, table);
	p2 = create_philo(2, table);
	pthread_join(p1->thread_philo, NULL);
	pthread_join(p2->thread_philo, NULL);
	pthread_mutex_destroy(&table->locker);
	free(data);
	return (0);
}
