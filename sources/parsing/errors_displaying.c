/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_displaying.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:50:49 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/18 13:21:17 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	display_parsing_errors(t_parsing_error_status parsing_error)
{
	if (parsing_error == INVALID_PHILOS_NUMBER)
		display_invalid_philos_number_msg();
	else if (parsing_error == INVALID_TIME_TO_DIE)
		display_invalid_time_to_die_msg();
	else if (parsing_error == INVALID_TIME_TO_EAT)
		display_invalid_time_to_eat_msg();
	else if (parsing_error == INVALID_TIME_TO_SLEEP)
		display_invalid_time_to_sleep_msg();
	else if (parsing_error == INVALID_MEALS_NUMBER)
		display_invalid_meals_number_msg();
}
