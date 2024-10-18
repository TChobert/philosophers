/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:12:16 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/18 19:29:34 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "philosophers.h"

t_input_data	testing_input_data;

void	setUp(void)
{
	testing_input_data.meals_number = 0;
}

void	tearDown(void)
{

}

void	test_check_and_get_number_of_meals_valid(void)
{
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("42",
										&testing_input_data));
	TEST_ASSERT_EQUAL(42, testing_input_data.meals_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("+42",
										&testing_input_data));
	TEST_ASSERT_EQUAL(42, testing_input_data.meals_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("778895",
										&testing_input_data));
	TEST_ASSERT_EQUAL(778895, testing_input_data.meals_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("789",
										&testing_input_data));
	TEST_ASSERT_EQUAL(789, testing_input_data.meals_number);
	TEST_ASSERT_EQUAL(VALID_ARGUMENT, check_and_get_number_of_meals("0",
										&testing_input_data));
	TEST_ASSERT_EQUAL(0, testing_input_data.meals_number);
}

void	test_check_and_get_number_of_meals_invalid(void)
{
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals("abc",
											&testing_input_data));
	TEST_ASSERT_EQUAL(0, testing_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals("",
											&testing_input_data));
	TEST_ASSERT_EQUAL(0, testing_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals(NULL,
											&testing_input_data));
	TEST_ASSERT_EQUAL(0, testing_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals("-12",
											&testing_input_data));
	TEST_ASSERT_EQUAL(0, testing_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals(
											"12385686589589689523272242527",
											&testing_input_data));
	TEST_ASSERT_EQUAL(0, testing_input_data.meals_number);
	TEST_ASSERT_EQUAL(INVALID_ARGUMENT, check_and_get_number_of_meals("I",
											&testing_input_data));
	TEST_ASSERT_EQUAL(0, testing_input_data.meals_number);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_check_and_get_number_of_meals_valid);
	RUN_TEST(test_check_and_get_number_of_meals_invalid);
	return UNITY_END();
}
