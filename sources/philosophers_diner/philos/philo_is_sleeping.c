/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_sleeping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:14:10 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/28 18:19:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_sleeps(t_philo *philo)
{
	ft_usleep(philo->time_to_sleep);
}

void	philo_is_sleeping(t_philo *philo)
{
	philo_takes_the_microphone(philo);
	philo_is_speaking(PHILO_IS_SLEEPING);
	philo_puts_back_the_microphone(philo);
	philo_sleeps(philo);
}
