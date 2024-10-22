/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:43:10 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/21 16:24:17 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// INCLUDES //

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>

// DEFINES //

# define MAX_PHILOSOPHERS 200

// TYPEDEFS //

// ENUMS //

typedef enum e_parsing_error_status
{
	INVALID_PHILOS_NUMBER,
	INVALID_TIME_TO_DIE,
	INVALID_TIME_TO_EAT,
	INVALID_TIME_TO_SLEEP,
	INVALID_MEALS_NUMBER
}			t_parsing_error_status;

typedef enum e_input_status
{
	VALID_INPUT = -1,
	INVALID_INPUT
}			t_input_status;

typedef enum e_argument_status
{
	INVALID_ARGUMENT = -1,
	VALID_ARGUMENT
}			t_argument_status;

// STRUCTS //

typedef struct s_input_data
{
	unsigned int		philos_number;
	unsigned int		forks_number;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		meals_number;
}				t_input_data;

typedef struct s_philosopher
{
	unsigned int	id;
	unsigned long	last_meal_time;
	pthread_t		*right_fork;
	pthread_t		*left_fork;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
}				t_philosopher;

// PROTOTYPES //

// PARSING :

int					philo(char **user_input);

t_input_status		arguments_parser(char **arguments,
						t_input_data *input_data);
t_argument_status	check_and_get_philos_number(
						const char *philos_input_number,
						t_input_data *input_data);
t_argument_status	check_and_get_time_to_die(
						const char *time_to_die_input,
						t_input_data *input_data);
t_argument_status	check_and_get_time_to_eat(const char *time_to_eat_input,
						t_input_data *input_data);
t_argument_status	check_and_get_time_to_sleep(
						const char *time_to_sleep_input,
						t_input_data *input_data);
t_argument_status	check_and_get_number_of_meals(
						const char *meals_input_number,
						t_input_data *input_data);
void				display_invalid_meals_number_msg(void);
void				display_invalid_time_to_sleep_msg(void);
void				display_invalid_time_to_eat_msg(void);
void				display_invalid_time_to_die_msg(void);
void				display_invalid_philos_number_msg(void);

bool				str_is_digit(const char *str);
bool				ft_is_digit(const int c);
long				ft_atol(const char *nptr, unsigned int *overflow_flag);
void				display_parsing_errors(
						t_parsing_error_status parsing_error);
size_t				ft_strlen(const char *str);
void				ft_putstr_fd(char *s, int fd);

#endif
