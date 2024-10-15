/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:09:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/15 20:37:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	str_is_digit(char *str)
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
