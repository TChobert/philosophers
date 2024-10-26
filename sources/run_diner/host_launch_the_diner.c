/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_launch_the_diner.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:25:05 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/26 15:51:41 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_routine_odd(t_philo *philo)
{
		pthread_mutex_lock(&philo->table->table_microphone);
		printf("I'm %d and i'm odd !\n", philo->id);
		pthread_mutex_unlock(&philo->table->table_microphone);
}

static void	philo_routine_even(t_philo *philo)
{
		pthread_mutex_lock(&philo->table->table_microphone);
		printf("I'm %d and i'm even !\n", philo->id);
		pthread_mutex_unlock(&philo->table->table_microphone);
}

static void	*philo_routine(void *current_philo_ptr)
{
	t_philo	*current_philo = (t_philo *)current_philo_ptr;

	while (true)
	{
		if (current_philo->id % 2 == 0)
		{
			philo_routine_even(current_philo);
		}
		else if (current_philo-> id % 2 != 0)
		{
			philo_routine_odd(current_philo);
		}
		usleep(100);
	}
	return (NULL);
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

static t_philo_initialization	init_philo_data(t_table *diner_table,
							t_philo *current_philo, size_t	id)
{
	if (diner_table == NULL || current_philo == NULL)
		return (INVALID_PHILO_INITIALIZATION);
	if (init_philo_basic_data(diner_table, current_philo, id)
		== INVALID_PHILO_INITIALIZATION)
		return (INVALID_PHILO_INITIALIZATION);
	if (give_forks_to_current_philo(diner_table, current_philo, id)
		== INVALID_PHILO_INITIALIZATION)
		return (INVALID_PHILO_INITIALIZATION);
	if (update_last_meal_time(current_philo) == TIME_UPDATE_ERROR)
		return (INVALID_PHILO_INITIALIZATION);
	return (VALID_PHILO_INITIALIZATION);
}

t_diner_status	host_launch_the_diner(t_table *diner_table, t_philo philos[])
{
	size_t	i;

	i = 0;
	while (i < diner_table->diner_informations.philos_number)
	{
		if (init_philo_data(diner_table, &philos[i], i)
			== INVALID_PHILO_INITIALIZATION)
		{
			ft_putstr_fd("An error occurs while intialising the philosophers"
				" data.\n", STDERR_FILENO);
			return (DINER_IS_CANCELED);
		}
		if (pthread_create(&philos[i].thread_id, NULL, philo_routine, &philos[i]) != 0)
			return (DINER_IS_CANCELED);
		++i;
	}
	i = 0;
	// while (i < diner_table->diner_informations.philos_number)
	// {

	// }
	while (1)
	{
	}
	return (DINER_IS_RUNNING);
}
