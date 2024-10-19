/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_check_and_get_meals_number.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:12:16 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/19 18:31:31 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_input_data	testing_meals_input_data;

void	test_check_and_get_number_of_meals_valid(void)
{
	testing_meals_input_data.meals_number = 0;

	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("42",
										&testing_meals_input_data));
	TEST_ASSERT_EQUAL(42, testing_meals_input_data.meals_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("+42",
										&testing_meals_input_data));
	TEST_ASSERT_EQUAL(42, testing_meals_input_data.meals_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("778895",
										&testing_meals_input_data));
	TEST_ASSERT_EQUAL(778895, testing_meals_input_data.meals_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("789",
										&testing_meals_input_data));
	TEST_ASSERT_EQUAL(789, testing_meals_input_data.meals_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("0",
										&testing_meals_input_data));
	TEST_ASSERT_EQUAL(0, testing_meals_input_data.meals_number);
}

void	test_check_and_get_number_of_meals_invalid(void)
{
	testing_meals_input_data.meals_number = 0;

	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals("abc",
											&testing_meals_input_data));
	TEST_ASSERT_EQUAL(0, testing_meals_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals("",
											&testing_meals_input_data));
	TEST_ASSERT_EQUAL(0, testing_meals_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals(NULL,
											&testing_meals_input_data));
	TEST_ASSERT_EQUAL(0, testing_meals_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals("-12",
											&testing_meals_input_data));
	TEST_ASSERT_EQUAL(0, testing_meals_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals(
											"12385686589589689523272242527",
											&testing_meals_input_data));
	TEST_ASSERT_EQUAL(0, testing_meals_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals("I",
											&testing_meals_input_data));
	TEST_ASSERT_EQUAL(0, testing_meals_input_data.meals_number);
}
