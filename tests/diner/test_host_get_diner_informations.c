/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_host_get_diner_informations.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:50:30 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/25 15:02:15 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	set_input_data(t_input_data	*input_data)
{
	input_data->philos_number = 185;
	input_data->forks_number = 185;
	input_data->time_to_die = 10000;
	input_data->time_to_eat = 1000;
	input_data->time_to_sleep = 1000;
	input_data->meals_number = 2;
}

void	test_host_get_diner_informations_valid(void)
{
	t_input_data			input_data;
	t_diner_informations	diner_informations;

	set_input_data(&input_data);
	TEST_ASSERT_EQUAL(DINER_INFORMATIONS_REGISTERED, host_get_diner_informations(
		&input_data, &diner_informations));
	TEST_ASSERT_EQUAL(input_data.philos_number, diner_informations.philos_number);
	TEST_ASSERT_EQUAL(input_data.forks_number, diner_informations.forks_number);
	TEST_ASSERT_EQUAL(input_data.time_to_die, diner_informations.time_to_die);
	TEST_ASSERT_EQUAL(input_data.time_to_eat,  diner_informations.time_to_eat);
	TEST_ASSERT_EQUAL(input_data.time_to_sleep, diner_informations.time_to_sleep);
	TEST_ASSERT_EQUAL(input_data.meals_number, diner_informations.meals_number);
}

void	test_host_get_diner_informations_invalid(void)
{
	t_input_data			*input_data_null_ptr;
	t_diner_informations	*infos_null_ptr;
	t_diner_informations	diner_informations;
	t_input_data			input_data;

	input_data_null_ptr = NULL;
	infos_null_ptr = NULL;
	set_input_data(&input_data);
	TEST_ASSERT_EQUAL(DINER_IS_CANCELED, host_get_diner_informations(
		input_data_null_ptr, &diner_informations));
	TEST_ASSERT_EQUAL(DINER_IS_CANCELED, host_get_diner_informations(
		&input_data, infos_null_ptr));
}
