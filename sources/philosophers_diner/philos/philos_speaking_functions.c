/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_speaking_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:51:58 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/31 16:53:06 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_takes_a_fork_msg(t_philo *philo)
{
	printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
}

void	philo_is_eating_msg(t_philo *philo)
{
	printf("%ld %d is eating\n", get_current_time(), philo->id);
}

void	philo_is_sleeping_msg(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_current_time(), philo->id);
}

void	philo_is_thinking_msg(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_current_time(), philo->id);
}

void	philo_died_msg(t_philo *philo)
{
	printf("%ld %d died\n", get_current_time(), philo->id);
}
