/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:10:48 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/04 17:40:11 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	odd_philo_puts_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	usleep(10);
	pthread_mutex_unlock(philo->left_fork);
}

void	even_philo_puts_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	//usleep(10);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_says_he_tooks_two_forks(t_philo *philo)
{
	philo_takes_the_microphone(philo);
	philo_is_speaking(philo, PHILO_TAKES_A_FORK);
	philo_is_speaking(philo, PHILO_TAKES_A_FORK);
	philo_puts_back_the_microphone(philo);
}

void	odd_philo_takes_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	usleep(10);
	pthread_mutex_lock(philo->left_fork);
	philo_says_he_tooks_two_forks(philo);
}

void	even_philo_takes_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	//usleep(10);
	pthread_mutex_lock(philo->right_fork);
	philo_says_he_tooks_two_forks(philo);
}
