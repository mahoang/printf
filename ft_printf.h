/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:22:19 by mahoang           #+#    #+#             */
/*   Updated: 2019/12/04 11:23:15 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct		s_flags
{
int			minus;
int			zero;
int			dot;
int			precision;
int			width;
}					t_list;

int		ft_printf(const char *str, ...);
//flag
int		is_not_flag(const char c);
int		contain_flag(const char c);
int		ft_atoi(const char *s, int *i, va_list lst_arg);
void	ft_flag(const char *s, int *i, struct s_flags *flags, va_list lst_arg);
int		ft_access(const char *s, int *i, va_list lst_arg);
//char
int		ft_char_flags(char c, struct s_flags flags);
int		ft_putchar(char c);
//string
int		ft_strlen(char *c);
int		ft_string_flags(char *c, struct s_flags flags);
int		ft_putstr(char *c);
//nbr
int		ft_number_flags(long nb, struct s_flags flags);
int		ft_putnbr(long nb);
//pnt
int		ft_pnt_flags(unsigned long nb, struct s_flags flags);
int		ft_putpnt(unsigned long nb, int firsttime);
//hexa
int		ft_hexa_flags(unsigned int nb, struct s_flags flags, int maj);
int		ft_puthex(unsigned int nb, int maj);
#endif
