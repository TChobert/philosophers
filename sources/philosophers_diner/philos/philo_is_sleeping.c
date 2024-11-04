/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_sleeping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:14:10 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 18:09:21 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static unsigned long	get_philo_nap_start(void)
{
	unsigned long	nap_start;

	nap_start = get_current_time();
	return (nap_start);
}

static void	philo_takes_his_time_to_sleep(t_philo *philo,
				unsigned long nap_start)
{
	while (get_current_time() - nap_start < philo->time_to_sleep)
	{
		usleep(500);
	}
}

static void	philo_sleeps(t_philo *philo, unsigned long nap_start)
{
	philo_takes_his_time_to_sleep(philo, nap_start);
}

void	philo_is_sleeping(t_philo *philo)
{
	const unsigned long	nap_start = get_philo_nap_start();

	philo_takes_the_microphone(philo);
	philo_is_speaking(philo, PHILO_IS_SLEEPING);
	philo_puts_back_the_microphone(philo);
	philo_sleeps(philo, nap_start);
}
