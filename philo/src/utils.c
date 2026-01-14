/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:55:17 by amartel           #+#    #+#             */
/*   Updated: 2026/01/14 05:49:02 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(char *nptr)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (!is_digit(nptr[i]))
			return (-1);
		nb = nb * 10 + (nptr[i] - '0');
		++i;
	}
	return (nb);
}
