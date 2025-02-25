/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:18:21 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 15:55:10 by tchobert         ###   ########.fr       */
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
		if (philo_checks_if_he_can_continue(current_philo) == PHILO_MUST_STOP)
			return (NULL);
		if (current_philo->id % 2 == 0)
		{
			even_philo_routine(current_philo);
		}
		if (current_philo-> id % 2 != 0)
		{
			odd_philo_routine(current_philo);
		}
	}
	return (NULL);
}
