/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odd_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:42:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/03 15:52:10 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void odd_philo_is_eating(t_philo *philo)
{
	// philo_takes_right_fork(philo);
	// usleep(10);
	// philo_takes_left_fork(philo);
	odd_philo_takes_forks(philo);
	philo_is_eating(philo);
	// philo_puts_right_fork(philo);
	// philo_puts_left_fork(philo);
	odd_philo_puts_forks(philo);
}

t_dining_philo_status	odd_philo_routine(t_philo *philo)
{
	odd_philo_is_eating(philo);
	philo_is_sleeping(philo);
	philo_is_thinking(philo);
	return (philo_checks_if_he_can_continue(philo));
}
