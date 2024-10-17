/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_displaying.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:50:49 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/17 16:47:25 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

static void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

static void	display_invalid_philos_number_msg(void)
{
	ft_putstr_fd("Error : Invalid number of philosophers.\n"
		"Please enter a positive value lower or equal to 200!\n"
		"\nNote that your input should contain only digit characters\n",
		STDERR_FILENO);
}

void	errors_displaying(t_parsing_error_status parsing_error)
{
	if (parsing_error == INVALID_PHILOS_NUMBER)
		display_invalid_philos_number_msg();
}
