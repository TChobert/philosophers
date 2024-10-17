/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:09:26 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/17 16:43:03 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo(char **user_input)
{
	t_input_data	input_data;

	if (arguments_parser(user_input, &input_data) == INVALID_INPUT)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (EXIT_FAILURE);
	return (philo(av + 1));
}
