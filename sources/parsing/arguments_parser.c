/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:08:41 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/15 20:33:27 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_argument_status	get_philos_number(char *philos_input_number,
								t_input_data *input_data)
{
	unsigned long	philos_number;

	philos_number = ft_atol(philos_input_number);
	if (philos_number > INT_MAX)
	{
		errors_displaying(INVALID_PHILOS_NUMBER);
		return (INVALID_ARGUMENT);
	}
	input_data->philos_number = philos_number;
	return (VALID_ARGUMENT);
}

static t_argument_status	check_philos_number_validity(
							char *philos_input_number, t_input_data *input_data)
{
	size_t					get_sign;
	unsigned long			philos_number;

	if (philos_input_number == NULL || philos_input_number[0] == '\0'
		|| philos_input_number == '-')
	{
		errors_displaying(INVALID_PHILOS_NUMBER);
		return (INVALID_ARGUMENT);
	}
	get_sign = (philos_input_number[0] == '+');
	if (str_is_digit(philos_input_number + get_sign) == false)
	{
		errors_displaying(INVALID_PHILOS_NUMBER);
		return (INVALID_ARGUMENT);
	}
	return (get_philos_number(philos_number, input_data));
}

t_input_status	arguments_parser(char **arguments, t_input_data *input_data)
{
	if (check_philos_number_validity(arguments[0], input_data)
		== INVALID_ARGUMENT)
		return (INVALID_INPUT);
	return (VALID_INPUT);
}
