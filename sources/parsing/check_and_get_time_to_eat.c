/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get_time_to_eat.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:18:32 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/17 22:24:34 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_argument_status	get_time_to_eat(const char *time_to_eat_input,
								t_input_data *input_data)
{
	unsigned long	time_to_eat;
	unsigned int	overflow_flag;

	overflow_flag = 0;
	time_to_eat = ft_atol(time_to_eat_input, &overflow_flag);
	if (overflow_flag == 1 || time_to_eat == 0)
	{
		display_parsing_errors(INVALID_TIME_TO_EAT);
		return (INVALID_ARGUMENT);
	}
	input_data->time_to_eat = time_to_eat;
	return (VALID_ARGUMENT);
}

t_argument_status	check_and_get_time_to_eat(const char *time_to_eat_input,
						t_input_data *input_data)
{
	size_t	get_sign;

	if (time_to_eat_input == NULL || *time_to_eat_input == '\0'
		|| *time_to_eat_input == '-')
	{
		display_parsing_errors(INVALID_TIME_TO_EAT);
		return (INVALID_ARGUMENT);
	}
	get_sign = (*time_to_eat_input == '+');
	if (str_is_digit(time_to_eat_input + get_sign) == false)
	{
		display_parsing_errors(INVALID_TIME_TO_EAT);
		return (INVALID_ARGUMENT);
	}
	return (get_time_to_eat(time_to_eat_input, input_data));
}
