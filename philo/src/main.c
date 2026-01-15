/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:11 by amartel           #+#    #+#             */
/*   Updated: 2026/01/15 01:34:17 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parser.h"

static void	info_prog(void)
{
	write(2, "./philo <number_of_philosophers> <time_to_die time_to_eat> ", 60);
	write(2, "<time_to_sleep> [number_of_times_each_philo_must_eat]\n", 61);
}

int	main(int ac, char **av)
{
	struct timeval	tv;
	struct timeval	ta;

	gettimeofday(&tv, NULL);
	printf("permier : %ld\n", tv.tv_usec);
	if (ac < 5 || ac > 6)
	{
		info_prog();
		return (1);
	}
	if (parser(av) == ERROR_CODE)
		return (-1);
	gettimeofday(&ta, NULL);
	printf("permier : %ld", ta.tv_usec - tv.tv_usec);
	return (0);
}
