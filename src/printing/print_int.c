/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:26:19 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/13 08:44:51 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_precision_to_int(char *num_str, int precision)
{
	char	*zeros;
	char	*new_str;
	int		num_len;
	int		prec_zeros;
	int		i;

	num_len = ft_strlen(num_str);
	prec_zeros = precision - num_len;
	if (prec_zeros <= 0)
		return (num_str);
	zeros = malloc(prec_zeros + 1);
	if (!zeros)
		return (NULL);
	i = 0;
	while (i < prec_zeros)
		zeros[i++] = '0';
	zeros[prec_zeros] = '\0';
	new_str = ft_strjoin(zeros, num_str);
	free(zeros);
	free(num_str);
	return (new_str);
}

int	print_int(int n, t_format *fmt)
{
	char	*num_str;
	int		total;
	int		len;

	num_str = ft_itoa(n);
	if (!num_str)
		return (0);
	if (fmt->precision > 0)
		num_str = apply_precision_to_int(num_str, fmt->precision);
	if (!num_str)
		return (0);
	apply_flags(&num_str, fmt);
	len = ft_strlen(num_str);
	write(1, num_str, len);
	free(num_str);
	total = len;
	return (total);
}
