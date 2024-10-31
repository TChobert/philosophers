/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_launch_the_diner.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:25:05 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/31 19:42:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		if (pthread_create(&philos[i].thread_id, NULL, philo_routine,
			&philos[i]) != 0)
			return (DINER_IS_CANCELED);
		++i;
	}
	while (1)
	{
	}
	return (DINER_IS_RUNNING);
}


// SEPARER LES DEUX BOUCLES !!
// START TIME AVANT THREAD
