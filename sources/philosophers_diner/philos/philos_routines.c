/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:18:21 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/03 15:57:19 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_diner_status	check_diner_status(t_philo *philo)
{
	t_diner_status	diner_status;

	pthread_mutex_lock(&philo->table->diner_status_mutex);
	diner_status = philo->table->diner_status;
	pthread_mutex_unlock(&philo->table->diner_status_mutex);
	return (diner_status);
}

void	*philo_routine(void *current_philo_ptr)
{
	t_philo	*current_philo;

	current_philo = (t_philo *)current_philo_ptr;
	update_last_meal_time(current_philo);
	if (current_philo->id % 2 != 0)
		ft_usleep(current_philo->time_to_eat);
	while (check_diner_status(current_philo_ptr) != DINER_IS_OVER)
	{
		if (current_philo->id % 2 == 0)
		{
			if (even_philo_routine(current_philo) == PHILO_MUST_STOP)
				break ;
		}
		if (current_philo-> id % 2 != 0)
		{
			if (odd_philo_routine(current_philo) == PHILO_MUST_STOP)
				break ;
		}
	}
	return (NULL);
}

// if (check_diner_status(current_philo) == DINER_IS_OVER)
		// 	return (NULL);

// usleep 50
