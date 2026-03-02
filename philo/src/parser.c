/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:07:00 by amartel           #+#    #+#             */
/*   Updated: 2026/03/02 03:47:34 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parser.h"

int	parser(char **av)
{
	t_data	data;

	data.nb_philo = ft_atoi(av[1]);
	if (data.nb_philo == ERROR_CODE && data.nb_philo > 200)
		return (ERROR_CODE);
	data.time_to_die = ft_atoi(av[2]);
	if (data.time_to_die == ERROR_CODE)
		return (ERROR_CODE);
	data.time_to_eat = ft_atoi(av[3]);
	if (data.time_to_eat == ERROR_CODE)
		return (ERROR_CODE);
	data.time_to_sleep = ft_atoi(av[4]);
	if (data.time_to_sleep == ERROR_CODE)
		return (ERROR_CODE);
	if (av[5])
	{
		data.eat_before_end = ft_atoi(av[5]);
		if (data.eat_before_end == ERROR_CODE)
			return (ERROR_CODE);
	}
	return (0);
}
