/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microphone_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:18:18 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/28 14:22:47 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_takes_the_microphone(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_microphone);
}

void	philo_puts_back_the_microphone(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->table_microphone);
}
