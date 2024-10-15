/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:43:10 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/15 19:52:21 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// INCLUDES //

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

# include "libft.h"

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

#endif
