/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:07:00 by amartel           #+#    #+#             */
/*   Updated: 2026/03/07 04:38:30 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parser.h"

int	parser(char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	if (data->nb_philo == ERROR || data->nb_philo > 200 || data->nb_philo < 1)
		return (ERROR);
	data->time_to_die = ft_atoi(av[2]);
	if (data->time_to_die == ERROR)
		return (ERROR);
	data->time_to_eat = ft_atoi(av[3]);
	if (data->time_to_eat == ERROR)
		return (ERROR);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->time_to_sleep == ERROR)
		return (ERROR);
	if (av[5])
	{
		data->eat_before_end = ft_atoi(av[5]);
		if (data->eat_before_end == ERROR)
			return (ERROR);
	}
	return (0);
}
