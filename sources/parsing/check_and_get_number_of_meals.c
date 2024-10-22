/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get_number_of_meals.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:46:54 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/18 13:16:10 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_argument_status	get_meals_number(const char *meals_input_number,
								t_input_data *input_data)
{
	unsigned long	meals_number;
	unsigned int	overflow_flag;

	overflow_flag = 0;
	meals_number = ft_atol(meals_input_number, &overflow_flag);
	if (overflow_flag == 1)
	{
		display_parsing_errors(INVALID_MEALS_NUMBER);
		return (INVALID_ARGUMENT);
	}
	input_data->meals_number = meals_number;
	return (VALID_ARGUMENT);
}

t_argument_status	check_and_get_number_of_meals(
						const char *meals_input_number,
						t_input_data *input_data)
{
	size_t					get_sign;

	if (meals_input_number == NULL || *meals_input_number == '\0'
		|| *meals_input_number == '-')
	{
		display_parsing_errors(INVALID_MEALS_NUMBER);
		return (INVALID_ARGUMENT);
	}
	get_sign = (*meals_input_number == '+');
	if (str_is_digit(meals_input_number + get_sign) == false)
	{
		display_parsing_errors(INVALID_MEALS_NUMBER);
		return (INVALID_ARGUMENT);
	}
	return (get_meals_number(meals_input_number, input_data));
}
