/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:08:59 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/15 22:09:33 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	is_space(const char *c)
{
	return ((*c >= 9 && *c <= 13) || (*c == 32));
}

static bool	is_sign(const char *c)
{
	return (*c == '-' || *c == '+');
}

static void	get_sign(const char *c, int *sign)
{
	if (*c == '-')
	{
		*sign *= -1;
	}
}

long	ft_atol(const char *nptr)
{
	long			converted_nb;
	int				i;
	int				sign_flag;

	i = 0;
	converted_nb = 0;
	sign_flag = 1;
	while (is_space(nptr))
	{
		++nptr;
	}
	if (is_sign(nptr))
	{
		get_sign(nptr, &sign_flag);
		++nptr;
	}
	while (ft_isdigit(nptr[i]))
	{
		converted_nb = converted_nb * 10 + (nptr[i] - 48);
		++i;
	}
	return (converted_nb * sign_flag);
}
