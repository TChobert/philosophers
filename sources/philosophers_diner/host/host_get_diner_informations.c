/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_get_diner_informations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:31:30 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/25 15:34:32 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_diner_status	host_get_diner_informations(t_input_data *input_data,
					t_diner_informations *diner_informations)
{
	if (input_data == NULL || diner_informations == NULL)
	{
		ft_putstr_fd("Error: An error occurs while getting"
			" diner informations.\n",
			STDERR_FILENO);
		return (DINER_IS_CANCELED);
	}
	diner_informations->philos_number = input_data->philos_number;
	diner_informations->forks_number = input_data->forks_number;
	diner_informations->time_to_die = input_data->time_to_die;
	diner_informations->time_to_eat = input_data->time_to_eat;
	diner_informations->time_to_sleep = input_data->time_to_sleep;
	diner_informations->meals_number = input_data->meals_number;
	return (DINER_INFORMATIONS_REGISTERED);
}
