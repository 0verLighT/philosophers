/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:55:17 by amartel           #+#    #+#             */
/*   Updated: 2026/01/15 01:34:36 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (ERRORCODE);
	while (nptr[i])
	{
		if (!is_digit(nptr[i]))
			return (ERRORCODE);
		nb = nb * 10 + (nptr[i] - '0');
		if (nb > 2147483647)
			return (ERRORCODE);
		++i;
	}
	return (nb);
}
