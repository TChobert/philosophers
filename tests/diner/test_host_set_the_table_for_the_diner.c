/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_host_set_the_table_for_the_diner.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/25 15:01:19 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	set_diner_informations(t_diner_informations *diner_informations)
{
	diner_informations->philos_number = 20;
	diner_informations->forks_number = 20;
	diner_informations->time_to_die = 10000;
	diner_informations->time_to_eat = 1000;
	diner_informations->time_to_sleep = 1000;
	diner_informations->meals_number = 10;
}

void	test_host_set_the_table_for_the_diner_valid(void)
{
	t_table	table;
	size_t	i;
	int		lock_check;

	i = 0;
	set_diner_informations(&table.diner_informations);
	TEST_ASSERT_EQUAL(DINER_TABLE_IS_READY, host_set_the_table_for_the_diner(
		&table));
	TEST_ASSERT_EQUAL(0, table.dead_flag);
	TEST_ASSERT_EQUAL(0, table.all_meals_eaten);
	lock_check = pthread_mutex_lock(&table.dead_flag_mutex);
	assert(lock_check == 0);
	lock_check = pthread_mutex_lock(&table.all_meals_eaten_mutex);
	assert(lock_check == 0);
	while(i < table.diner_informations.forks_number)
	{
		lock_check = pthread_mutex_lock(&table.forks[i]);
		assert(lock_check == 0);
		pthread_mutex_unlock(&table.forks[i]);
		++i;
	}
}

void	test_host_set_the_table_for_the_diner_invalid(void)
{
	t_table	*table_null_ptr;
	//t_table	table;
	//size_t	i;

	table_null_ptr = NULL;
	TEST_ASSERT_EQUAL(DINER_IS_CANCELED, host_set_the_table_for_the_diner(table_null_ptr));
}
