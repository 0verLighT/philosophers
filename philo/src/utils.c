/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:55:17 by amartel           #+#    #+#             */
/*   Updated: 2026/03/10 22:25:22 by amartel          ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	return (0);
}
