/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_host.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:29 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/25 17:15:10 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philo_initialization	give_forks_to_current_philo(
									t_table *diner_table,
									t_philo *current_philo, size_t id)
{
	current_philo->left_fork = &diner_table->forks[id];
	if (current_philo->left_fork == NULL)
		return (INVALID_PHILO_INITIALIZATION);
	if (id == diner_table->diner_informations.philos_number - 1)
	{
		current_philo->right_fork = &diner_table->forks[0];
	}
	else
		current_philo->right_fork = &diner_table->forks[id + 1];
	if (current_philo->right_fork == NULL)
		return (INVALID_PHILO_INITIALIZATION);
	return (VALID_PHILO_INITIALIZATION);
}

static t_philo_initialization	init_philo_data(t_table *diner_table,
							t_philo *current_philo, size_t	id)
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
	return (give_forks_to_current_philo(diner_table, current_philo, id));
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
		}
		++i;
	}
	return (DINER_IS_RUNNING);
}

int	diner_story(t_input_data *input_data)
{
	t_table					diner_table;
	t_philo					philos[MAX_PHILOSOPHERS];
	t_diner_status			diner_master;

	if (host_get_diner_informations(input_data, &diner_table.diner_informations)
		== DINER_IS_CANCELED)
		return (EXIT_FAILURE);
	if (host_set_the_table_for_the_diner(&diner_table) == DINER_IS_CANCELED)
		return (EXIT_FAILURE);
	if (host_launch_the_diner(&diner_table, philos) == DINER_IS_CANCELED)
		return (EXIT_FAILURE);
	//pour lancer les threads des philosophes
	// while (diner_master != DINER_IS_OVER)
	// {
	//		diner_master = listen_to_what_is_happening(diner_table);
	// }
	return (EXIT_SUCCESS);
}
