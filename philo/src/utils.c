/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:55:17 by amartel           #+#    #+#             */
/*   Updated: 2026/03/08 20:22:30 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *nptr)
{
	long	nb;
	size_t	i;

	nb = 0;
	i = 0;
	if (!nptr)
		return (ERROR);
	while (nptr[i])
	{
		if (!is_digit(nptr[i]))
			return (ERROR);
		nb = nb * 10 + (nptr[i] - '0');
		if (nb > 2147483647)
			return (ERROR);
		++i;
	}
	return (nb);
}

long	get_time_ms(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}
