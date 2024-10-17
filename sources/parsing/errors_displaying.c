/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_displaying.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:50:49 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/17 22:39:17 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	display_invalid_time_to_sleep_msg(void)
{
	ft_putstr_fd("Error : invalid time_to_sleep duration!\n"
		"Please enter a time in milliseconds beetween 1 and"
		" 2147483647.\n"
		"\nNote that your input must contain only digit characters\n",
		STDERR_FILENO);
}

static void	display_invalid_time_to_eat_msg(void)
{
	ft_putstr_fd("Error : invalid time_to_eat duration!\n"
		"Please enter a time in milliseconds beetween 1 and"
		" 2147483647.\n"
		"\nNote that your input must contain only digit characters\n",
		STDERR_FILENO);
}

static void	display_invalid_time_to_die_msg(void)
{
	ft_putstr_fd("Error : invalid time_to_die duration!\n"
		"Please enter a time in milliseconds beetween 1 and"
		" 2147483647.\n"
		"\nNote that your input must contain only digit characters\n",
		STDERR_FILENO);
}

static void	display_invalid_philos_number_msg(void)
{
	ft_putstr_fd("Error : Invalid number of philosophers.\n"
		"Please enter a value beetween 1 and 200!\n"
		"\nNote that your input must contain only digit characters\n",
		STDERR_FILENO);
}

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
}
