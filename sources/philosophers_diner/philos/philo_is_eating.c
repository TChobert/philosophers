/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:12:03 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 15:57:33 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_checks_if_he_is_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_full_mutex);
	if (philo->number_of_meals_eaten == philo->meals_number)
		philo->is_full = true;
	pthread_mutex_unlock(&philo->is_full_mutex);
}

static void	philo_updates_his_number_of_meals_eaten(t_philo *philo)
{
	if (philo->table->diner_informations.meals_number != NO_MEALS_REQUIERED)
	{
		philo->number_of_meals_eaten += 1;
		philo_checks_if_he_is_full(philo);
	}
}

static void	philo_takes_his_time_to_eat(t_philo *philo)
{
	while (get_current_time() - philo->last_meal_time < philo->time_to_eat)
	{
		usleep(500);
	}
}

static void	philo_eats(t_philo *philo)
{
	philo_takes_his_time_to_eat(philo);
}

void	philo_is_eating(t_philo *philo)
{
	update_last_meal_time(philo); // start
	philo_takes_the_microphone(philo);
	philo_is_speaking(philo, PHILO_IS_EATING);
	philo_puts_back_the_microphone(philo);
	philo_updates_his_number_of_meals_eaten(philo);
	philo_eats(philo);
}
