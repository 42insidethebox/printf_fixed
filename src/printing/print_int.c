/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:01 by procha-r          #+#    #+#             */
/*   Updated: 2024/11/17 14:39:30 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_prefix(int n)
{
	if (n < 0)
		return ("-");
	return ("");
}

static char	*create_zeros(int prec_zeros)
{
	char	*zeros;
	int		i;

	zeros = malloc(prec_zeros + 1);
	if (!zeros)
		return (NULL);
	i = 0;
	while (i < prec_zeros)
	{
		zeros[i] = '0';
		i++;
	}
	zeros[prec_zeros] = '\0';
	return (zeros);
}

static char	*apply_precision(int n, char *num_str, int precision)
{
	int		num_len;
	int		prec_zeros;
	char	*zeros;
	char	*temp;
	char	*new_num_str;

	num_len = ft_strlen(num_str);
	prec_zeros = precision - num_len;
	if (prec_zeros <= 0)
		return (num_str);
	zeros = create_zeros(prec_zeros);
	if (!zeros)
		return (NULL);
	temp = ft_strjoin(get_prefix(n), zeros);
	free(zeros);
	if (!temp)
		return (NULL);
	new_num_str = ft_strjoin(temp, num_str + (n < 0));
	free(temp);
	free(num_str);
	return (new_num_str);
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
		num_str = apply_precision(n, num_str, fmt->precision);
	if (!num_str)
		return (0);
	apply_flags(&num_str, fmt);
	len = ft_strlen(num_str);
	write(1, num_str, len);
	free(num_str);
	total = len;
	return (total);
}
