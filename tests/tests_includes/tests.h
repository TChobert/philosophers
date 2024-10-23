/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:42:04 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/23 15:32:12 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

// INCLUDES //

# include "philosophers.h"
# include "unity.h"

// PROTOTYPES //

void	test_check_and_get_philos_number_valid(void);
void	test_check_and_get_philos_number_invalid(void);
void	test_check_and_get_number_of_meals_valid(void);
void	test_check_and_get_number_of_meals_invalid(void);

void	test_host_set_the_table_for_the_diner_valid(void);
void	test_host_set_the_table_for_the_diner_invalid(void);

#endif
