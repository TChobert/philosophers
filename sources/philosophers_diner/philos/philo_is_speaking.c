/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_speaking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:42:08 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/31 14:50:44 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_takes_a_fork_msg(t_philo *philo)
{
	printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
}

static void	philo_is_eating_msg(t_philo *philo)
{
	printf("%ld %d is eating\n", get_current_time(), philo->id);
}

static void	philo_is_sleeping_msg(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_current_time(), philo->id);
}

static void	philo_is_thinking_msg(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_current_time(), philo->id);
}

static void	philo_died_msg(t_philo *philo)
{
	printf("%ld %d died\n", get_current_time(), philo->id);
}

void	philo_is_speaking(t_philo *philo, t_philo_msg message)
{
	static t_speaking_functions	philo_speaking_functions[] = {
		philo_takes_a_fork_msg,
		philo_is_eating_msg,
		philo_is_sleeping_msg,
		philo_is_thinking_msg,
		philo_died_msg
	};

	philo_speaking_functions[message](philo);
}
