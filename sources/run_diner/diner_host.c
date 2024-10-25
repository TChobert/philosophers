/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_host.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:29 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/25 18:30:09 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	diner_story(t_input_data *input_data)
{
	t_table					diner_table;
	t_philo					philos[MAX_PHILOSOPHERS];
	//t_diner_status			diner_master;

	if (host_get_diner_informations(input_data, &diner_table.diner_informations)
		== DINER_IS_CANCELED)
		return (EXIT_FAILURE);
	if (host_set_the_table_for_the_diner(&diner_table) == DINER_IS_CANCELED)
		return (EXIT_FAILURE);
	if (host_launch_the_diner(&diner_table, philos) == DINER_IS_CANCELED)
		return (EXIT_FAILURE);
	// while (diner_master != DINER_IS_OVER)
	// {
	//		diner_master = listen_to_what_is_happening(diner_table);
	// }
	// host_close_the_diner(&diner_table); // joindre_thread_philos
	// host_clean_up_the_table(&diner_table); // detruire les mutex
	return (EXIT_SUCCESS);
}
