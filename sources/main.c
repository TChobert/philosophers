/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:09:26 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/15 14:20:55 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac < 5 || ac > 6)
		return (EXIT_FAILURE);
	// if (arguments_parser(av) == INVALID_INPUT)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
