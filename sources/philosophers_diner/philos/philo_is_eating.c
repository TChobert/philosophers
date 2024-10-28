/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:12:03 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/28 17:40:02 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eats(t_philo *philo)
{
	ft_usleep(philo->time_to_eat);
}

void	philo_is_eating(t_philo *philo)
{
	philo_takes_the_microphone(philo);
	philo_is_speaking(PHILO_IS_EATING);
	philo_puts_back_the_microphone(philo);
	update_last_meal_time(philo);
	philo_eats(philo);
}
