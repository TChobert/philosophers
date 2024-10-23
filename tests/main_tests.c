/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:47:31 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/23 17:17:07 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	setUp(void)
{
	return ;
}

void	tearDown(void)
{
	return ;
}

int	main(void)
{
	UNITY_BEGIN();
	printf("\033[32m\nTESTING FUNCTION CHECK_AND_GET_MEALS_NUMBER:\n\n\033[0m");
	sleep(2);
	RUN_TEST(test_check_and_get_number_of_meals_valid);
	RUN_TEST(test_check_and_get_number_of_meals_invalid);
	printf("\033[32m\nTESTING FUNCTION CHECK_AND_GET_PHILOS_NUMBER:\n\n\033[0m");
	sleep(2);
	RUN_TEST(test_check_and_get_philos_number_valid);
	RUN_TEST(test_check_and_get_philos_number_invalid);
	printf("\033[32m\nTESTING FUNCTION_HOST_SET_THE_TABLE_FOR_DINER:\n\n\033[0m");
	sleep(2);
	RUN_TEST(test_host_get_diner_informations_valid);
	RUN_TEST(test_host_get_diner_informations_invalid);
	return (UNITY_END());
}
