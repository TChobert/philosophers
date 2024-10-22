/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get_philos_number.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:07:05 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/21 10:56:25 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_argument_status	get_philos_number(const char *philos_input_number,
								t_input_data *input_data)
{
	unsigned long	philos_number;
	unsigned int	overflow_flag;

	overflow_flag = 0;
	philos_number = ft_atol(philos_input_number, &overflow_flag);
	if (overflow_flag == 1 || philos_number > 200 || philos_number == 0)
	{
		display_parsing_errors(INVALID_PHILOS_NUMBER);
		return (INVALID_ARGUMENT);
	}
	input_data->philos_number = (unsigned int)philos_number;
	input_data->forks_number = (unsigned int)philos_number;
	return (VALID_ARGUMENT);
}

t_argument_status	check_and_get_philos_number(
						const char *philos_input_number,
						t_input_data *input_data)
{
	size_t					get_sign;

	if (philos_input_number == NULL || philos_input_number[0] == '\0'
		|| *philos_input_number == '-')
	{
		display_parsing_errors(INVALID_PHILOS_NUMBER);
		return (INVALID_ARGUMENT);
	}
	get_sign = (philos_input_number[0] == '+');
	if (str_is_digit(philos_input_number + get_sign) == false)
	{
		display_parsing_errors(INVALID_PHILOS_NUMBER);
		return (INVALID_ARGUMENT);
	}
	return (get_philos_number(philos_input_number, input_data));
}
