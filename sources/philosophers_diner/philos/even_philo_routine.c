/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_philo_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:05:50 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/31 14:59:28 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	even_philo_is_eating(t_philo *philo)
{
	philo_takes_left_fork(philo);
	philo_takes_right_fork(philo);
	philo_is_eating(philo);
	philo_puts_left_fork(philo);
	philo_puts_right_fork(philo);
}

void	even_philo_routine(t_philo *philo)
{
	even_philo_is_eating(philo);
	philo_is_sleeping(philo);
	philo_is_thinking(philo);
}
