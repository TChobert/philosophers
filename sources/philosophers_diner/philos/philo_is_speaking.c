/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_speaking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:42:08 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/28 18:15:27 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_takes_a_fork(t_philo *philo)
{
	printf("%ld, %d has taken a fork.", get_current_time(), philo->id);
}

static void	philo_puts_back_a_fork(t_philo *philo)
{
	printf("%ld, %d puts back a fork.", get_current_time(), philo->id);
}

static void	philo_is_eating(t_philo *philo)
{
	printf("%ld, %d is eating.\n", get_current_time(), philo->id);
}

static void	philo_is_sleeping(t_philo *philo)
{
	printf("%ld, %d is sleeping.\n", get_current_time(), philo->id);
}

static void	philo_is_thinking(t_philo *philo)
{
	printf("%ld, %d is thinking.\n", get_current_time(), philo->id);
}

static void	philo_died(t_philo *philo)
{
	printf("%ld, %d died.\n", get_current_time(), philo->id);
}

void	philo_is_speaking(t_philo *philo, t_philo_msg message)
{
	static t_speaking_functions	philo_speaking_functions[] = {
		philo_takes_a_fork,
		philo_puts_back_a_fork,
		philo_is_eating,
		philo_is_sleeping,
		philo_is_thinking,
		philo_died
	};

	philo_speaking_functions[message](philo);
}
