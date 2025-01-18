/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_master_is_speaking.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:02:39 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 18:07:12 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	diner_master_tells_a_philo_has_died(t_philo *philo)
{
	printf("%ld %d died\n", get_current_time() - philo->table->diner_start_time,
		philo->id);
}

void	diner_master_takes_the_microphone(t_table *diner_table)
{
	pthread_mutex_lock(&diner_table->table_microphone);
}

void	diner_master_puts_back_the_microphone(t_table *diner_table)
{
	pthread_mutex_unlock(&diner_table->table_microphone);
}

void	diner_master_tells_who_is_dead(t_table *diner_table, t_philo *philo)
{
	diner_master_takes_the_microphone(diner_table);
	diner_master_tells_a_philo_has_died(philo);
	diner_master_puts_back_the_microphone(diner_table);
}
