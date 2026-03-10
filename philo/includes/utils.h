/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:55:38 by amartel           #+#    #+#             */
/*   Updated: 2026/03/10 20:24:12 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <sys/time.h>
# define ERROR -1

typedef struct s_table	t_table;

int		ft_atoi(char *str);
/**
 * @brief return time in ms
 * @details forumla : ms = (sec * 1000) + (usec / 1000)
 * @return time with long
 */
long	get_time_ms(void);

#endif
