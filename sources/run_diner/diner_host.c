/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_host.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:29 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/23 15:59:43 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_diner_status	host_set_the_table_for_diner(t_input_data *input_data,
					t_table *diner_table)
{
	if (input_data == NULL || diner_table == NULL)
	{
		ft_putstr_fd("Error: A problem occurs while setting the diner table.\n",
			STDERR_FILENO);
		return (DINER_IS_CANCELLED);
	}
	diner_table->dead_flag = false;
	diner_table->philos_number = input_data->philos_number;
	diner_table->forks_number = input_data->forks_number;
	diner_table->time_to_die = input_data->time_to_die;
	diner_table->time_to_eat = input_data->time_to_eat;
	diner_table->time_to_sleep = input_data->time_to_sleep;
	diner_table->meals_number = input_data->meals_number;
	return (DINER_TABLE_IS_READY);
}

int	diner_story(t_input_data *input_data)
{
	t_table					diner_table;
	//pthread_t				diner_master;
	//pthread_t				philos[200];
	//pthread_mutex_t			forks[200];

	if (host_set_the_table_for_diner(input_data, &diner_table)
		== DINER_IS_CANCELLED)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}


