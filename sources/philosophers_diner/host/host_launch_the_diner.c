/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_launch_the_diner.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:25:05 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/02 15:30:10 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_diner_status	host_places_guests_around_table(t_table *diner_table,
							t_philo philos[])
{
	size_t	i;

	i = 0;
	while (i < diner_table->diner_informations.philos_number)
	{
		if (pthread_create(&philos[i].thread_id, NULL, philo_routine,
			&philos[i]) != 0)
			return (DINER_IS_CANCELED);
		++i;
	}
	return (GUESTS_ARE_PLACED);
}

static t_diner_status	host_gives_informations_to_guests(t_table *diner_table,
							t_philo philos[])
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
		++i;
	}
	return (GUESTS_ARE_INFORMED);
}

t_diner_status	host_launch_the_diner(t_table *diner_table, t_philo philos[])
{
	if (host_gives_informations_to_guests(diner_table, philos)
			== DINER_IS_CANCELED)
	{
		return (DINER_IS_CANCELED);
	}
	if (host_places_guests_around_table(diner_table, philos)
			== DINER_IS_CANCELED)
	{
		return (DINER_IS_CANCELED);
	}
	// while (1)
	// {
	// }
	return (DINER_IS_RUNNING);
}
