/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_set_the_table_for_the_diner.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:28:23 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/25 17:16:00 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_diner_status	init_table_mutexes(t_table *diner_table)
{
	size_t	i;

	i = 0;
	if (pthread_mutex_init(&diner_table->dead_flag_mutex, NULL) != 0
		|| pthread_mutex_init(&diner_table->all_meals_eaten_mutex, NULL) != 0)
	{
		ft_putstr_fd("An error occurs while intialising the table mutexes.\n",
			STDERR_FILENO);
	}
	while (i < diner_table->diner_informations.forks_number)
	{
		if (pthread_mutex_init(&diner_table->forks[i], NULL) != 0)
		{
			ft_putstr_fd("An error occurs while intitialising"
				" the forks mutexes.\n",
				STDERR_FILENO);
			return (DINER_IS_CANCELED);
		}
		++i;
	}
	return (DINER_TABLE_IS_READY);
}

t_diner_status	host_set_the_table_for_the_diner(t_table *diner_table)
{
	if (diner_table == NULL)
	{
		ft_putstr_fd("An error occurs while setting the table for the diner.\n",
			STDERR_FILENO);
		return (DINER_IS_CANCELED);
	}
	diner_table->dead_flag = 0;
	diner_table->all_meals_eaten = 0;
	return (init_table_mutexes(diner_table));
}
