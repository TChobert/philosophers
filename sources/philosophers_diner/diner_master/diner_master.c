/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:03:03 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/03 18:04:47 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	diner_master_tells_who_is_dead(t_table *diner_table, t_philo *philo)
{
	diner_master_takes_the_microphone(diner_table);
	diner_master_tells_a_philo_has_died(philo);
	diner_master_puts_back_the_microphone(diner_table);
}

static void	diner_master_stops_the_diner(t_table *diner_table)
{
	pthread_mutex_lock(&diner_table->diner_status_mutex);
	diner_table->diner_status = DINER_IS_OVER;
	pthread_mutex_unlock(&diner_table->diner_status_mutex);
}

static unsigned long	diner_master_gets_philo_last_meal_time(t_philo *philo)
{
	unsigned long	philo_last_meal_time;

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo_last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	return (philo_last_meal_time);
}

static t_diner_status	diner_master_checks_time_to_death(t_table *diner_table,
					t_philo philos[])
{
	const unsigned long	current_time = get_current_time();
	unsigned long		philo_last_meal_time;
	size_t				i;

	i = 0;
	while (i < diner_table->diner_informations.philos_number)
	{
		philo_last_meal_time = diner_master_gets_philo_last_meal_time(&philos[i]);
		if (current_time - philo_last_meal_time > diner_table->
				diner_informations.time_to_die)
		{
			diner_master_stops_the_diner(diner_table);
			diner_master_tells_who_is_dead(diner_table, &philos[i]);
			return (DINER_IS_OVER);
		}
		++i;
	}
	return (DINER_IS_RUNNING);
}

static bool	diner_master_checks_if_philo_is_full(t_philo *philo)
{
	bool	philo_is_full;

	pthread_mutex_lock(&philo->is_full_mutex);
	philo_is_full = philo->is_full;
	pthread_mutex_unlock(&philo->is_full_mutex);
	return (philo_is_full);
}

static t_diner_status	diner_master_checks_number_of_meals(t_table *diner_table,
							t_philo philos[])
{
	size_t	i;

	i = 0;
	while (i < diner_table->diner_informations.philos_number)
	{
		if (diner_master_checks_if_philo_is_full(&philos[i]) == false)
			return (DINER_IS_RUNNING);
		++i;
	}
	diner_master_stops_the_diner(diner_table);
	return (DINER_IS_OVER);
}

t_diner_status	listen_to_what_is_happening(t_table *diner_table,
					t_philo philos[])
{
	if (diner_master_checks_time_to_death(diner_table, philos) == DINER_IS_OVER)
		return (DINER_IS_OVER);
	if (diner_table->diner_informations.meals_number != NO_MEALS_REQUIERED)
	{
		if (diner_master_checks_number_of_meals(diner_table, philos) == DINER_IS_OVER)
	 	return (DINER_IS_OVER);
	}
	return (DINER_IS_RUNNING);
}
