/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_host_set_the_table_for_the_diner.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/23 18:54:52 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	set_diner_informations(t_diner_informations *diner_informations)
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

	set_diner_informations(&table.diner_informations);
	TEST_ASSERT_EQUAL(DINER_TABLE_IS_READY, host_set_the_table_for_the_diner(
		&table));
	
}
