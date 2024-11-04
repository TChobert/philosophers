/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_launch_the_diner.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:25:05 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 17:38:23 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*one_guest_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	printf("%lu 1 has taken a fork\n", get_current_time() - philo->table->diner_start_time);
	ft_usleep(philo->time_to_die);
	printf("%lu 1 died\n", get_current_time() - philo->table->diner_start_time);
	return (NULL);
}

static t_diner_status	host_invites_only_one_guest(t_table *diner_table, t_philo philos[])
{
	diner_table->diner_start_time = get_current_time();
	if (pthread_create(&philos[0].thread_id, NULL, one_guest_routine,
			&philos[0]) != 0)
		return (DINER_IS_CANCELED);
	//pthread_join(philos[0].thread_id, NULL);
	return (DINER_IS_OVER);
}

static t_diner_status	host_places_guests_around_table(t_table *diner_table,
							t_philo philos[])
{
	size_t	i;

	i = 0;
	diner_table->diner_start_time = get_current_time();
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
	if (diner_table->diner_informations.philos_number == 1)
		return (host_invites_only_one_guest(diner_table, philos));
	if (host_places_guests_around_table(diner_table, philos)
			== DINER_IS_CANCELED)
	{
		return (DINER_IS_CANCELED);
	}
	return (DINER_IS_RUNNING);
}
