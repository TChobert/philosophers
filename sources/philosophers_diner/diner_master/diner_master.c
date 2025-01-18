/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:03:03 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 18:17:49 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_diner_status	listen_to_what_is_happening(t_table *diner_table,
					t_philo philos[])
{
	if (diner_master_checks_time_to_death(diner_table, philos) == DINER_IS_OVER)
		return (DINER_IS_OVER);
	if (diner_table->diner_informations.meals_number != NO_MEALS_REQUIERED)
	{
		if (diner_master_checks_number_of_meals(diner_table, philos)
			== DINER_IS_OVER)
			return (DINER_IS_OVER);
	}
	return (DINER_IS_RUNNING);
}
