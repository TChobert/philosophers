/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_displaying.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:50:49 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/15 20:40:48 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	display_invalid_philos_number_msg(void)
{
	ft_dprintf(STDERR_FILENO, "Error : Invalid number of philosophers.\n"
		"Please enter a positive value lower or equal to int max!");
}

void	errors_displaying(t_parsing_error_status parsing_error)
{
	if (parsing_error == INVALID_PHILOS_NUMBER)
		display_invalid_philos_number_msg();
}
