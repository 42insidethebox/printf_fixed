/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:25:10 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/17 14:03:57 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_utoa_base(unsigned long num, int base, int uppercase);

#endif