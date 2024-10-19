/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_check_and_get_philos_number.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:35:11 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/19 18:30:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_input_data	testing_philos_input_data;

void	test_check_and_get_philos_number_valid(void)
{
	testing_philos_input_data.philos_number = 0;
	
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_philos_number("42",
										&testing_philos_input_data));
	TEST_ASSERT_EQUAL(42, testing_philos_input_data.philos_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_philos_number("+42",
										&testing_philos_input_data));
	TEST_ASSERT_EQUAL(42, testing_philos_input_data.philos_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_philos_number("77",
										&testing_philos_input_data));
	TEST_ASSERT_EQUAL(77, testing_philos_input_data.philos_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_philos_number("200",
										&testing_philos_input_data));
	TEST_ASSERT_EQUAL(200, testing_philos_input_data.philos_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_philos_number("1",
										&testing_philos_input_data));
	TEST_ASSERT_EQUAL(1, testing_philos_input_data.philos_number);
}

void	test_check_and_get_philos_number_invalid(void)
{
	testing_philos_input_data.philos_number = 0;

	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_philos_number("abc",
											&testing_philos_input_data));
	TEST_ASSERT_EQUAL(0, testing_philos_input_data.philos_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_philos_number("",
											&testing_philos_input_data));
	TEST_ASSERT_EQUAL(0, testing_philos_input_data.philos_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_philos_number(NULL,
											&testing_philos_input_data));
	TEST_ASSERT_EQUAL(0, testing_philos_input_data.philos_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_philos_number("-12",
											&testing_philos_input_data));
	TEST_ASSERT_EQUAL(0, testing_philos_input_data.philos_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_philos_number(
											"12385686589589689523272242527",
											&testing_philos_input_data));
	TEST_ASSERT_EQUAL(0, testing_philos_input_data.philos_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_philos_number("I",
											&testing_philos_input_data));
	TEST_ASSERT_EQUAL(0, testing_philos_input_data.philos_number);
}
