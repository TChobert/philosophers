/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks_if_he_can_continue.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:58:14 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 17:00:11 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_dining_philo_status	philo_checks_if_he_can_continue(t_philo *philo)
{
	t_dining_philo_status	check_status;

	check_status = PHILO_CAN_CONTINUE;
	pthread_mutex_lock(&philo->table->diner_status_mutex);
	if (philo->table->diner_status == DINER_IS_OVER)
	{
		check_status = PHILO_MUST_STOP;
	}
	pthread_mutex_unlock(&philo->table->diner_status_mutex);
	// pthread_mutex_lock(&philo->is_full_mutex);
	// if (philo->is_full == true)
	// 	check_status = PHILO_MUST_STOP;
	// pthread_mutex_unlock(&philo->is_full_mutex);
	return (check_status);
}
