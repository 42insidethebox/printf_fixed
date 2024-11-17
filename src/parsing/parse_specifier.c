/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:55:45 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/17 16:54:56 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_specifier(const char **format, t_format *fmt)
{
	char	spec;

	spec = **format;
	if (**format == 'l')
	{
		fmt->length_modifier = 'l';
		(*format)++;
	}
	if (spec == 'c' || spec == 's' || spec == 'd' || \
		spec == 'i' || spec == 'u' || spec == 'x' || \
		spec == 'X' || spec == 'p' || spec == '%')
	{
		fmt->specifier = spec;
		(*format)++;
	}
}
