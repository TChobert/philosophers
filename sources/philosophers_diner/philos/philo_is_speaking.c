/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_speaking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:42:08 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/03 14:47:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_is_speaking(t_philo *philo, t_philo_msg message)
{
	static t_speaking_functions	philo_speaking_functions[] = {
		philo_takes_a_fork_msg,
		philo_is_eating_msg,
		philo_is_sleeping_msg,
		philo_is_thinking_msg
	};

	if (philo_checks_if_he_can_continue(philo) != PHILO_MUST_STOP)
		philo_speaking_functions[message](philo);
}
