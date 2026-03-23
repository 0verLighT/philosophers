/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:55:17 by amartel           #+#    #+#             */
/*   Updated: 2026/03/23 23:11:29 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	content_routine(t_philo *philo, int first, int second)
{
	first = philo->left;
	second = philo->right;
	if (first > second)
	{
		first = philo->right;
		second = philo->left;
	}
	pthread_mutex_lock(&philo->table->forks[first]);
	thread_printf(philo, FORK);
	pthread_mutex_lock(&philo->table->forks[second]);
	thread_printf(philo, FORK);
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->meal);
	thread_printf(philo, EAT);
	ft_usleep(philo->table->data->time_to_eat, philo);
	pthread_mutex_unlock(&philo->table->forks[second]);
	pthread_mutex_unlock(&philo->table->forks[first]);
	thread_printf(philo, SLEEP);
	ft_usleep(philo->table->data->time_to_sleep, philo);
	thread_printf(philo, THINK);
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
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
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

void	ft_usleep(long ms, t_philo *philo)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < ms)
	{
		usleep(1);
		if (is_finished(philo))
			break ;
	}
}
