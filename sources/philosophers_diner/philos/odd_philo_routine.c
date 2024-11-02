/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odd_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:42:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/02 20:01:06 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	odd_philo_is_eating(t_philo *philo)
{
	philo_takes_right_fork(philo);
	ft_usleep(10);
	philo_takes_left_fork(philo);
	philo_is_eating(philo);
	philo_puts_right_fork(philo);
	philo_puts_left_fork(philo);
}

t_dining_philo_status	odd_philo_routine(t_philo *philo)
{
	if (philo_checks_if_he_can_continue(philo) == PHILO_MUST_STOP)
		return (PHILO_MUST_STOP);
	odd_philo_is_eating(philo);
	if (philo_checks_if_he_can_continue(philo) == PHILO_MUST_STOP)
		return (PHILO_MUST_STOP);
	philo_is_sleeping(philo);
	if (philo_checks_if_he_can_continue(philo) == PHILO_MUST_STOP)
		return (PHILO_MUST_STOP);
	philo_is_thinking(philo);
	return (philo_checks_if_he_can_continue(philo));
}
