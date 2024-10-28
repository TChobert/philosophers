/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_thinking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:19:57 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/28 18:27:25 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_is_thinking(t_philo *philo)
{
	philo_takes_the_microphone(philo);
	philo_is_speaking(philo, PHILO_IS_THINKING);
	philo_puts_back_the_microphone(philo);
}
