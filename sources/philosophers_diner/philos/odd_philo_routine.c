/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odd_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:42:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/28 18:46:41 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	odd_philo_is_eating(t_philo *philo)
{
	philo_taks_right_fork(philo);
	philo_takes_left_fork(philo);
	philo_is_eating(philo);
	philo_puts_right_fork(philo);
	philo_puts_left_fork(philo);
}

void	odd_philo_routine(t_philo *philo)
{
	ft_usleep(philo->time_to_eat);
	odd_philo_is_eating(philo);
	philo_is_sleeping(philo);
	philo_is_thinking(philo);
}
