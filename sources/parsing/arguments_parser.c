/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:08:41 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/15 19:53:00 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_argument_status	check_philos_number_validity(char *philos_number,
						t_input_data *input_data)
{
	if (philos_number[0] == '-')
	{
		ft_dprintf(STDERR_FILENO, "Invalid number of philosophers. Please"
			" enter a positive value\n");
		return (INVALID_ARGUMENT);
	}
}

t_input_status	arguments_parser(char **arguments)
{
	t_input_data	input_data;

	if (check_philos_number_validity(arguments[0], &input_data)
		== INVALID_ARGUMENT)
		return (INVALID_INPUT);
}
