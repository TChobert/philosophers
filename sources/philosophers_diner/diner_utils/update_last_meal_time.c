/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_last_meal_time.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:48:20 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/25 17:52:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_time_update_status	update_last_meal_time(t_philo *philo)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == 0)
	{
		philo->last_meal_time
			= current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
		return (TIME_UPDATE_SUCCESS);
	}
	return (TIME_UPDATE_ERROR);
}
