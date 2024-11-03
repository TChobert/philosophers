/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:11:29 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/03 15:47:07 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philo_initialization	init_philo_mutexes(t_philo *current_philo)
{
	if (pthread_mutex_init(&current_philo->last_meal_time_mutex, NULL) != 0)
		return (INVALID_PHILO_INITIALIZATION);
	return (VALID_PHILO_INITIALIZATION);
}

static t_philo_initialization	give_forks_to_current_philo(
									t_table *diner_table,
									t_philo *current_philo, size_t id)
{
	current_philo->left_fork = &diner_table->forks[id];
	if (current_philo->left_fork == NULL)
	{
		return (INVALID_PHILO_INITIALIZATION);
	}
	if (id == diner_table->diner_informations.philos_number - 1)
	{
		current_philo->right_fork = &diner_table->forks[0];
	}
	else
		current_philo->right_fork = &diner_table->forks[id + 1];
	if (current_philo->right_fork == NULL)
	{
		return (INVALID_PHILO_INITIALIZATION);
	}
	return (VALID_PHILO_INITIALIZATION);
}

static	t_philo_initialization	init_philo_basic_data(t_table *diner_table,
									t_philo *current_philo, size_t id)
{
	if (diner_table == NULL || current_philo == NULL)
		return (INVALID_PHILO_INITIALIZATION);
	current_philo->table = diner_table;
	current_philo->id = id + 1;
	current_philo->dead_flag = false;
	current_philo->number_of_meals_eaten = 0;
	current_philo->time_to_die = diner_table->diner_informations.time_to_die;
	current_philo->time_to_eat = diner_table->diner_informations.time_to_eat;
	current_philo->time_to_sleep
		= diner_table->diner_informations.time_to_sleep;
	current_philo->meals_number = diner_table->diner_informations.meals_number;
	return (VALID_PHILO_INITIALIZATION);
}

t_philo_initialization	init_philo_data(t_table *diner_table,
							t_philo *current_philo, size_t	id)
{
	if (diner_table == NULL || current_philo == NULL)
		return (INVALID_PHILO_INITIALIZATION);
	if (init_philo_basic_data(diner_table, current_philo, id)
		== INVALID_PHILO_INITIALIZATION)
		return (INVALID_PHILO_INITIALIZATION);
	if (init_philo_mutexes(current_philo) == INVALID_PHILO_INITIALIZATION)
		return (INVALID_PHILO_INITIALIZATION);
	if (give_forks_to_current_philo(diner_table, current_philo, id)
		== INVALID_PHILO_INITIALIZATION)
		return (INVALID_PHILO_INITIALIZATION);
	if (update_last_meal_time(current_philo) == TIME_UPDATE_ERROR)
		return (INVALID_PHILO_INITIALIZATION);
	return (VALID_PHILO_INITIALIZATION);
}
