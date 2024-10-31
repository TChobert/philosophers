/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:10:48 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/31 14:28:52 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_puts_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_puts_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_takes_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	philo_takes_the_microphone(philo);
	philo_is_speaking(philo, PHILO_TAKES_A_FORK);
	philo_puts_back_the_microphone(philo);
}

void	philo_takes_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	philo_takes_the_microphone(philo);
	philo_is_speaking(philo, PHILO_TAKES_A_FORK);
	philo_puts_back_the_microphone(philo);
}
