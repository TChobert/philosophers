/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_philo_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:05:50 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 18:09:04 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	even_philo_is_eating(t_philo *philo)
{
	even_philo_takes_forks(philo);
	philo_is_eating(philo);
	even_philo_puts_forks(philo);
}

t_dining_philo_status	even_philo_routine(t_philo *philo)
{
	even_philo_is_eating(philo);
	philo_is_sleeping(philo);
	philo_is_thinking(philo);
	return (philo_checks_if_he_can_continue(philo));
}
