/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:11 by amartel           #+#    #+#             */
/*   Updated: 2026/03/02 03:48:58 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parser.h"

static void	info_prog(void)
{
	(void) write(2, "./philo <number_of_philosophers> ", 34);
	(void) write(2, "<time_to_die time_to_eat> <time_to_sleep> ", 43);
	(void) write(2, "[number_of_times_each_philo_must_eat]\n", 39);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		info_prog();
		return (1);
	}
	if (parser(av) == ERROR_CODE)
		return (1);
	return (0);
}
