/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:08:41 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/17 22:19:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_input_status	arguments_parser(char **user_input, t_input_data *input_data)
{
	if (check_and_get_philos_number(user_input[0], input_data)
		== INVALID_ARGUMENT)
		return (INVALID_INPUT);
	if (check_and_get_time_to_die(user_input[1], input_data)
		== INVALID_ARGUMENT)
		return (INVALID_INPUT);
	if (check_and_get_time_to_eat(user_input[2], input_data)
		== INVALID_ARGUMENT)
		return (INVALID_INPUT);
	return (VALID_INPUT);
}
