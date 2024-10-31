/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:12:03 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/31 19:30:04 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eats(t_philo *philo)
{
	ft_usleep(philo->time_to_eat);
}

void	philo_is_eating(t_philo *philo)
{
	update_last_meal_time(philo); // start
	philo_takes_the_microphone(philo);
	philo_is_speaking(philo, PHILO_IS_EATING);
	philo_puts_back_the_microphone(philo);
	philo_eats(philo);
}

//sleep tant que current - last_meal_time < time_to_eat
