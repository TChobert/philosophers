/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:43:10 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/28 18:51:37 by tchobert         ###   ########.fr       */
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
# include <sys/time.h>

// DEFINES //

# define MAX_PHILOSOPHERS 200

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

typedef enum e_diner_status
{
	DINER_IS_CANCELED,
	DINER_INFORMATIONS_REGISTERED,
	DINER_TABLE_IS_READY,
	DINER_IS_RUNNING,
	DINER_IS_OVER
}			t_diner_status;

typedef enum e_philo_initialization
{
	INVALID_PHILO_INITIALIZATION = -1,
	VALID_PHILO_INITIALIZATION
}			t_philo_initialization;

typedef enum e_time_update_status
{
	TIME_UPDATE_ERROR = -1,
	TIME_UPDATE_SUCCESS
}			t_time_update_status;

typedef enum e_philo_msg
{
	PHILO_TAKES_A_FORK,
	PHILO_PUTS_BACK_A_FORK,
	PHILO_IS_EATING,
	PHILO_IS_SLEEPING,
	PHILO_IS_THINKING,
	PHILO_DIED
}			t_philo_msg;

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

typedef struct s_diner_informations
{
	unsigned int	philos_number;
	unsigned int	forks_number;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	meals_number;
}				t_diner_informations;

typedef struct s_table
{
	volatile t_diner_status	diner_status;
	bool					dead_alarm;
	unsigned int			all_meals_eaten_list;
	pthread_mutex_t			diner_status_mutex;
	pthread_mutex_t			dead_alarm_mutex;
	pthread_mutex_t			all_meals_eaten_list_mutex;
	pthread_mutex_t			table_microphone;
	t_diner_informations	diner_informations;
	pthread_mutex_t			forks[MAX_PHILOSOPHERS];
}				t_table;

typedef struct s_philo
{
	pthread_t			thread_id;
	t_table				*table;
	unsigned int		id;
	bool				dead_flag;
	unsigned long		last_meal_time;
	unsigned long		number_of_meals_eaten;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		meals_number;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
}				t_philo;

// TYPEDEFS //

typedef	void (* t_speaking_functions)(t_philo *);

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

// DINER :

int						diner_story(t_input_data *input_data);
t_diner_status			host_get_diner_informations(t_input_data *input_data,
							t_diner_informations *diner_informations);
t_diner_status			host_set_the_table_for_the_diner(t_table *diner_table);
t_diner_status			host_launch_the_diner(t_table *diner_table,
							t_philo philos[]);

t_time_update_status	update_last_meal_time(t_philo *philo);

t_philo_initialization	init_philo_data(t_table *diner_table,
							t_philo *current_philo, size_t	id);

// PHILOS_ROUTINES :

void					*philo_routine(void *current_philo_ptr);

#endif
