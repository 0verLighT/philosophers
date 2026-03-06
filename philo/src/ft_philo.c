/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:40:55 by amartel           #+#    #+#             */
/*   Updated: 2026/03/06 03:26:24 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	create_philo(void)
{
	t_philo philo;

	pthread_create(&philo, NULL, routine_philo, NULL);
	printf("The philo has been create");
	return (philo);
}


void routine_philo(void)
{
	printf("routine");
}
