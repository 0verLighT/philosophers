/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 05:07:00 by amartel           #+#    #+#             */
/*   Updated: 2026/01/14 05:58:42 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parser.h"

int	parser(char **av)
{
	t_data data;

	printf("%d\n", data.nb_philo);
	data.nb_philo = ft_atoi(av[1]);
	if (data.nb_philo == ERROR_CODE)
		return (ERROR_CODE);
	printf("%d\n", data.nb_philo);
	if (data.nb_philo > 200)
	{
		printf("trop de philo");
	}
}
