/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_master_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:08:50 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/02 17:14:59 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	diner_master_tells_a_philo_has_died(t_philo *philo)
{
	printf("%ld %d died\n", get_current_time(), philo->id);
}

void	diner_master_takes_the_microphone(t_table *diner_table)
{
	pthread_mutex_lock(&diner_table->table_microphone);
}

void	diner_master_puts_back_the_microphone(t_table *diner_table)
{
	pthread_mutex_unlock(&diner_table->table_microphone);
}
