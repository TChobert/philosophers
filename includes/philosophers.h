/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:43:10 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/17 16:42:03 by tchobert         ###   ########.fr       */
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

// DEFINES //

# define MAX_PHILOSOPHERS 200

// TYPEDEFS //

// ENUMS //

typedef enum e_parsing_error_status
{
	INVALID_PHILOS_NUMBER,
	INVALID_
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
	unsigned long	philos_number;
}				t_input_data;

typedef struct s_philosopher
{
	unsigned int	id;
}				t_philosopher;

// PROTOTYPES //

int				philo(char **user_input);

t_input_status	arguments_parser(char **arguments, t_input_data *input_data);
bool			str_is_digit(const char *str);
bool			ft_is_digit(const int c);
long			ft_atol(const char *nptr);
void			errors_displaying(t_parsing_error_status parsing_error);

#endif
