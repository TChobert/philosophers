/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_host.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:29 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/31 17:14:47 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	host_close_the_diner(t_table *diner_table, t_philo philos[])
{
	size_t	i;

	i = 0;
	while (i < diner_table->diner_informations.philos_number)
	{
		if (pthread_join(philos[i].thread_id, NULL) != 0)
		{
			ft_putstr_fd("An error occurs while joining the philosophers"
				" threads.\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	host_clean_the_diner_table(t_table *diner_table)
{
	size_t	i;

	i = 0;
	while (i < diner_table->diner_informations.forks_number)
	{
		if (pthread_mutex_destroy(&diner_table->forks[i]) != 0)
		{
			ft_putstr_fd("An error occurs while cleaning the table.\n",
				STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
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
	while (diner_master != DINER_IS_OVER)
	{
		diner_master = listen_to_what_is_happening(&diner_table, philos);
	}
	if (host_close_the_diner(&diner_table, philos) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (host_clean_the_diner_table(&diner_table));
}
