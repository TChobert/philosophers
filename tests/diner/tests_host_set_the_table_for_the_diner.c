/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_host_set_the_table_for_the_diner.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:50:30 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/23 15:58:29 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	set_input_data(t_input_data	*input_data)
{
	input_data->philos_number = 185;
	input_data->forks_number = 185;
	input_data->time_to_die = 10000;
	input_data->time_to_eat = 1000;
	input_data->time_to_sleep = 1000;
	input_data->meals_number = 2;
}

void	test_host_set_the_table_for_the_diner_valid(void)
{
	t_input_data	input_data;
	t_table			table_data;

	set_input_data(&input_data);
	TEST_ASSERT_EQUAL(DINER_TABLE_IS_READY, host_set_the_table_for_diner(
		&input_data, &table_data));
	TEST_ASSERT_EQUAL(false, table_data.dead_flag);
	TEST_ASSERT_EQUAL(input_data.philos_number, table_data.philos_number);
	TEST_ASSERT_EQUAL(input_data.forks_number, table_data.forks_number);
	TEST_ASSERT_EQUAL(input_data.time_to_die, table_data.time_to_die);
	TEST_ASSERT_EQUAL(input_data.time_to_eat, table_data.time_to_eat);
	TEST_ASSERT_EQUAL(input_data.time_to_sleep, table_data.time_to_sleep);
	TEST_ASSERT_EQUAL(input_data.meals_number, table_data.meals_number);
}

void	test_host_set_the_table_for_the_diner_invalid(void)
{
	t_input_data	*input_data_null_ptr;
	t_table			*table_null_ptr;
	t_table			table_data;
	t_input_data	input_data;

	input_data_null_ptr = NULL;
	table_null_ptr = NULL;
	set_input_data(&input_data);
	TEST_ASSERT_EQUAL(DINER_IS_CANCELLED, host_set_the_table_for_diner(
		input_data_null_ptr, &table_data));
	TEST_ASSERT_EQUAL(DINER_IS_CANCELLED, host_set_the_table_for_diner(
		&input_data, table_null_ptr));
}
