/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:03:03 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/31 17:18:43 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_diner_status	diner_master_checks_time_to_death(t_philo philos[])
{
	
}

t_diner_status	listen_to_what_is_happenig(t_table *diner_table, t_philo philos[])
{
	t_diner_status	diner_status;

	diner_status = DINER_IS_RUNNING;
	diner_status = diner_master_checks_time_to_death(philos);
	diner_status = diner_master_checks_number_of_meals(philos);
	return (diner_status);
}
