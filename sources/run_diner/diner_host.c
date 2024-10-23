/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_host.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:29 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/23 19:04:28 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_diner_status	host_set_the_table_for_the_diner(t_table *diner_table)
{

}

t_diner_status	host_get_diner_informations(t_input_data *input_data,
					t_diner_informations *diner_informations)
{
	if (input_data == NULL || diner_informations == NULL)
	{
		ft_putstr_fd("Error: A problem occurs while setting the diner table.\n",
			STDERR_FILENO);
		return (DINER_IS_CANCELLED);
	}
	diner_informations->philos_number = input_data->philos_number;
	diner_informations->forks_number = input_data->forks_number;
	diner_informations->time_to_die = input_data->time_to_die;
	diner_informations->time_to_eat = input_data->time_to_eat;
	diner_informations->time_to_sleep = input_data->time_to_sleep;
	diner_informations->meals_number = input_data->meals_number;
	return (DINER_INFORMATIONS_REGISTERED);
}

int	diner_story(t_input_data *input_data)
{
	t_table					diner_table;
	t_diner_status			diner_master;
	t_philo					philos[200];

	if (host_get_diner_informations(input_data, &diner_table.diner_informations)
		== DINER_IS_CANCELLED)
		return (EXIT_FAILURE);
	// if (host_set_the_table_for_the_diner(&diner_table) == DINER_IS_CANCELLED);
	// 	return (EXIT_FAILURE);
	// host_launch_the_diner(diner_table); //pour lancer les threads des philosophes
	// while (diner_master != DINER_IS_OVER)
	// {
	//		diner_master = listen_to_what_is_happening(diner_table);
	// }
	return (EXIT_SUCCESS);
}


