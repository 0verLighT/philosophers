/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:55:17 by amartel           #+#    #+#             */
/*   Updated: 2026/03/10 20:25:21 by amartel          ###   ########.fr       */
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

void	philo_alone(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left]);
		thread_printf(philo, FORK);
		return ;
	}
}

void	anyone_dead(t_table *table)
{
	size_t	i;

	while (1)
	{
		i = 0;
		while (i < (size_t) table->data->nb_philo)
		{
			pthread_mutex_lock(&table->t_philo[i].meal);
			if (get_time_ms() - table->t_philo[i].last_meal
				> table->data->time_to_die)
			{
				thread_printf(&table->t_philo[i], DEAD);
				pthread_mutex_lock(&table->stop);
				table->is_dead = 1;
				pthread_mutex_unlock(&table->stop);
				pthread_mutex_unlock(&table->t_philo[i].meal);
				return ;
			}
			pthread_mutex_unlock(&table->t_philo[i].meal);
			++i;
		}
	}
}
