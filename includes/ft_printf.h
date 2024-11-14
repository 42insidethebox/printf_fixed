/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:41:15 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/14 09:03:28 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_format
{
	int		flag_minus;
	int		flag_zero;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

int			ft_printf(const char *format, ...);

t_format	parse_format(const char **format);
void		parse_flag(const char **format, t_format *fmt);
void		parse_width(const char **format, t_format *fmt);
void		parse_precision(const char **format, t_format *fmt);
void		parse_specifier(const char **format, t_format *fmt);

int			print_char(char c, t_format *fmt);
int			print_string(const char *str, t_format *fmt);
int			print_int(int n, t_format *fmt);
int			print_hex(unsigned int num, int uppercase, t_format *fmt);
int			print_percent(t_format *fmt);
int			print_pointer(void *ptr, t_format *fmt);
int			print_unsigned(unsigned int n, t_format *fmt);

t_format	init_format(void);
void		apply_flags(char **str, t_format *fmt);

#endif