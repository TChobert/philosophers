/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:09:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/17 16:47:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	ft_is_digit(const int c)
{
	return (c >= '0' && c <= '9');
}

bool	str_is_digit(const char *str)
{
	size_t	i;

	i = 0;
	if (*str == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (ft_is_digit(str[i]) == false)
			return (false);
		++i;
	}
	return (true);
}
