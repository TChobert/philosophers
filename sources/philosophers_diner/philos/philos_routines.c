/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:18:21 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/31 15:33:07 by tchobert         ###   ########.fr       */
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

// static void	philo_routine_odd(t_philo *philo)
// {
// 		pthread_mutex_lock(&philo->table->table_microphone);
// 		printf("I'm %d and i'm odd !\n", philo->id);
// 		pthread_mutex_unlock(&philo->table->table_microphone);
// }

void	*philo_routine(void *current_philo_ptr)
{
	t_philo	*current_philo = (t_philo *)current_philo_ptr;

	if (current_philo->id % 2 != 0)
		ft_usleep(current_philo->time_to_eat);
	while (true)
	{
		if (current_philo->id % 2 == 0)
		{
			even_philo_routine(current_philo);
		}
		else if (current_philo-> id % 2 != 0)
		{
			odd_philo_routine(current_philo);
		}
	}
	return (NULL);
}

//usleep(100);

// if (check_diner_status(current_philo) == DINER_IS_OVER)
		// 	return (NULL);
