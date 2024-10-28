/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:26:18 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/28 18:07:27 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	get_current_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
	{
		ft_putstr_fd("An error occurs while getting current time",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
