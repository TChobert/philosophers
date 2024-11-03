/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:43:10 by tchobert          #+#    #+#             */
/*   Updated: 2024/11/03 17:49:37 by tchobert         ###   ########.fr       */
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
# define NO_MEALS_REQUIERED 0UL

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
	GUESTS_ARE_INFORMED,
	GUESTS_ARE_PLACED,
	DINER_IS_RUNNING,
	DINER_IS_OVER
}			t_diner_status;

typedef enum e_philo_initialization
{
	INVALID_PHILO_INITIALIZATION = -1,
	VALID_PHILO_INITIALIZATION
}			t_philo_initialization;

typedef enum e_dining_philo_status
{
	PHILO_MUST_STOP,
	PHILO_CAN_CONTINUE
}			t_dining_philo_status;

typedef enum e_time_update_status
{
	TIME_UPDATE_ERROR = -1,
	TIME_UPDATE_SUCCESS
}			t_time_update_status;

typedef enum e_philo_msg
{
	PHILO_TAKES_A_FORK,
	PHILO_IS_EATING,
	PHILO_IS_SLEEPING,
	PHILO_IS_THINKING
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
	//bool					dead_alarm;
	unsigned int			all_meals_eaten_list;
	pthread_mutex_t			diner_status_mutex;
	//pthread_mutex_t			dead_alarm_mutex;
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
	bool				is_full;
	unsigned long		last_meal_time;
	unsigned long		number_of_meals_eaten;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		meals_number;
	pthread_mutex_t		last_meal_time_mutex;
	pthread_mutex_t		is_full_mutex;
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
t_dining_philo_status	even_philo_routine(t_philo *philo);
t_dining_philo_status	odd_philo_routine(t_philo *philo);

void					philo_is_eating(t_philo *philo);
void					philo_is_speaking(t_philo *philo, t_philo_msg message);
void					philo_is_sleeping(t_philo *philo);
void					philo_is_thinking(t_philo *philo);

void					philo_takes_left_fork(t_philo *philo);
void					philo_takes_right_fork(t_philo *philo);
void					philo_puts_right_fork(t_philo *philo);
void					philo_puts_left_fork(t_philo *philo);
void					philo_takes_the_microphone(t_philo *philo);
void					philo_puts_back_the_microphone(t_philo *philo);
t_dining_philo_status	philo_checks_if_he_can_continue(t_philo *philo);

void					even_philo_puts_forks(t_philo *philo);
void					odd_philo_puts_forks(t_philo *philo);
void					philo_says_he_tooks_two_forks(t_philo *philo);
void					odd_philo_takes_forks(t_philo *philo);
void					even_philo_takes_forks(t_philo *philo);

void					philo_takes_a_fork_msg(t_philo *philo);
void					philo_is_eating_msg(t_philo *philo);
void					philo_is_sleeping_msg(t_philo *philo);
void					philo_is_thinking_msg(t_philo *philo);

t_diner_status			listen_to_what_is_happening(t_table *diner_table,
							t_philo philos[]);

int						ft_usleep(unsigned long milliseconds);
unsigned long			get_current_time(void);

// DINER MASTER

void					diner_master_tells_a_philo_has_died(t_philo *philo);
void					diner_master_takes_the_microphone(t_table *diner_table);
void					diner_master_puts_back_the_microphone(
							t_table *diner_table);

#endif

// 5 800 200 200
// 1 800 200 200 die
// 5 800 200 200 7
// 4 410 200 200
// 4 310 200 100 DIE

// 2 200 100 100
