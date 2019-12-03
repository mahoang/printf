/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:22:19 by mahoang           #+#    #+#             */
/*   Updated: 2019/12/03 14:45:06 by mahoang          ###   ########.fr       */
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

int					ft_printf(const char *str, ...);
//flag
int					is_not_flag(const char c);
void				ft_flag(const char *s, int *i, struct s_flags *flags, va_list lst_arg);
int					ft_access(const char *s, int *i, va_list lst_arg);
//char
int					ft_print_char(const char c, struct s_flags flags);
int					ft_putchar(const char c);
//string
int		ft_strlen(const char *c);
int		ft_print_string(const char *c, struct s_flags flags);
int		ft_putstr(const char *c);
//nbr
int		ft_print_number(unsigned long nb, struct s_flags flags);
int		ft_putnbr(unsigned long nb);
//pnt
int		ft_print_pnt(unsigned long nb, struct s_flags flags);
int		ft_putpnt(unsigned long nb, int firsttime);
#endif
