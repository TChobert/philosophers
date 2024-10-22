/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get_time_to_die.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:33:16 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/17 21:51:08 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	t_argument_status	get_time_to_die(const char *time_to_die_input,
							t_input_data *input_data)
{
	unsigned long		time_to_die;
	unsigned int		overflow_flag;

	overflow_flag = 0;
	time_to_die = ft_atol(time_to_die_input, &overflow_flag);
	if (overflow_flag == 1 || time_to_die == 0)
	{
		display_parsing_errors(INVALID_TIME_TO_DIE);
		return (INVALID_ARGUMENT);
	}
	input_data->time_to_die = time_to_die;
	return (VALID_ARGUMENT);
}

t_argument_status	check_and_get_time_to_die(
							const char *time_to_die_input,
							t_input_data *input_data)
{
	size_t	get_sign;

	if (time_to_die_input == NULL || *time_to_die_input == '\0'
		|| *time_to_die_input == '-')
	{
		display_parsing_errors(INVALID_TIME_TO_DIE);
		return (INVALID_ARGUMENT);
	}
	get_sign = (*time_to_die_input == '+');
	if (str_is_digit(time_to_die_input + get_sign) == false)
	{
		display_parsing_errors(INVALID_TIME_TO_DIE);
		return (INVALID_ARGUMENT);
	}
	return (get_time_to_die(time_to_die_input, input_data));
}
