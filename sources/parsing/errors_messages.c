/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:20:42 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/18 13:21:42 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	display_invalid_meals_number_msg(void)
{
	ft_putstr_fd("Error : invalid number_of_times_each_philosopher_must_eat!\n"
		"If you wish to indicate a number of times each philo must eat,"
		" please enter a number of meals beetween 1 and"
		" 2147483647.\n"
		"\nNote that your input must contain only digit characters\n",
		STDERR_FILENO);
}

void	display_invalid_time_to_sleep_msg(void)
{
	ft_putstr_fd("Error : invalid time_to_sleep duration!\n"
		"Please enter a time in milliseconds beetween 1 and"
		" 2147483647.\n"
		"\nNote that your input must contain only digit characters\n",
		STDERR_FILENO);
}

void	display_invalid_time_to_eat_msg(void)
{
	ft_putstr_fd("Error : invalid time_to_eat duration!\n"
		"Please enter a time in milliseconds beetween 1 and"
		" 2147483647.\n"
		"\nNote that your input must contain only digit characters\n",
		STDERR_FILENO);
}

void	display_invalid_time_to_die_msg(void)
{
	ft_putstr_fd("Error : invalid time_to_die duration!\n"
		"Please enter a time in milliseconds beetween 1 and"
		" 2147483647.\n"
		"\nNote that your input must contain only digit characters\n",
		STDERR_FILENO);
}

void	display_invalid_philos_number_msg(void)
{
	ft_putstr_fd("Error : Invalid number of philosophers.\n"
		"Please enter a value beetween 1 and 200!\n"
		"\nNote that your input must contain only digit characters\n",
		STDERR_FILENO);
}
