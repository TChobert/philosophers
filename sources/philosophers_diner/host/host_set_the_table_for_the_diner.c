/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_set_the_table_for_the_diner.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:28:23 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 15:38:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_diner_status	put_forks_on_the_table(t_table *diner_table)
{
	size_t	i;

	i = 0;
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

static t_diner_status	init_table_mutexes(t_table *diner_table)
{
	if (pthread_mutex_init(&diner_table->diner_status_mutex, NULL) != 0
		|| pthread_mutex_init(&diner_table->table_microphone, NULL) != 0)
	{
		ft_putstr_fd("An error occurs while intialising the table mutexes.\n",
			STDERR_FILENO);
	}
	return (put_forks_on_the_table(diner_table));
}

t_diner_status	host_set_the_table_for_the_diner(t_table *diner_table)
{
	if (diner_table == NULL)
	{
		ft_putstr_fd("An error occurs while setting the table for the diner.\n",
			STDERR_FILENO);
		return (DINER_IS_CANCELED);
	}
	diner_table->diner_status = DINER_IS_RUNNING;
	//diner_table->all_meals_eaten_list = 0;
	return (init_table_mutexes(diner_table));
}

//|| pthread_mutex_init(&diner_table->all_meals_eaten_list_mutex,
		//NULL) != 0
