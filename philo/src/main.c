/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:55:11 by amartel           #+#    #+#             */
/*   Updated: 2026/03/02 03:39:17 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parser.h"

static void info_prog(void)
{
	(void) write(2, "./philo <number_of_philosophers> <time_to_die time_to_eat> ", 60);
	(void) write(2, "<time_to_die time_to_eat> <time_to_sleep> ", 43);
	(void) write(2, "[number_of_times_each_philo_must_eat]\n", 39);
}

void *print_message(void *arg)
{
	((char *)arg)[1] = '1';
	printf("%s\n", (char *)arg);
	return NULL;
}

int main(int ac, char **av)
{

	char *buffer;
	if (ac < 5 || ac > 6)
	{
		info_prog();
		return (1);
	}
	if (parser(av) == ERROR_CODE)
		return (-1);
	pthread_t thread;
	pthread_t thread1;
	pthread_t thread2;
	buffer = strdup("coucou les gens");
	pthread_create(&thread, NULL, print_message, (void *)buffer);
	pthread_create(&thread1, NULL, print_message, (void *)buffer);
	pthread_create(&thread2, NULL, print_message, (void *)buffer);
	pthread_join(thread, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	free(buffer);
	return (0);
}
