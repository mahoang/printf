/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:22:19 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/31 18:01:08 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			dot;
	int			precision;
	int			width;
}				t_list;

int				ft_printf(const char *str, ...);
int				ft_print_misc(char c, struct s_flags flags);
/*
**	flag
*/
int				is_conversion(const char c);
int				contain_flag(const char c);
int				ft_atoi(const char *s, int *i, va_list lst_arg);
void			ft_negative_flag(struct s_flags *flags);
void			ft_flag
(const char *s, int *i, struct s_flags *flags, va_list lst_arg);
int				ft_access(const char *s, int *i, va_list lst_arg);
/*
**	char
*/
int				ft_char_flags(char c, struct s_flags flags);
int				ft_putchar_minus_width(int c, int width);
int				ft_putchar_zero_width(int c, int width);
int				ft_putchar_width(int c, int width);
int				ft_putchar(char c);
/*
**	string
*/
int				ft_strlen(char *c);
int				ft_string_flags(char *c, struct s_flags flags);
int				ft_putstr1(char *c);
int				ft_putstr_width_dot(char *c, struct s_flags flags);
int				ft_putstr_width(char *c, struct s_flags flags);
int				ft_putstr_prec(char *c, int prec);
/*
**	nbr
*/
int				ft_number_flags(long nb, struct s_flags flags);
int				ft_putnbr(long nb);
int				ft_nbrlen(long nb);
long			ft_towrite(long nb);
int				ft_putnbr_width(long nb, struct s_flags flags);
int				ft_putnbr_prec(long nb, struct s_flags flags);
int				ft_putnbr_width_prec(long nb, struct s_flags flags);
int				ft_nbr_0(struct s_flags flags);
void			ft_nbr_1(struct s_flags flags, int c);
void			ft_nbr_2(struct s_flags flags, int c);
void			ft_nbr_3(struct s_flags flags, int c);
void			ft_nbr_4(struct s_flags flags, int c);
/*
**	pnt
*/
int				ft_pnt_flags(unsigned long nb, struct s_flags flags);
int				ft_putpnt(unsigned long nb, int firsttime);
int				ft_pntlen(unsigned long nb);
int				ft_pnt_width(unsigned long nb, struct s_flags flags);
int				ft_pnt_prec(unsigned long nb, struct s_flags flags);
int				ft_putpnt_width_prec(unsigned long nb, struct s_flags flags);
/*
**	hexa
*/
int				ft_hexa_flags(unsigned int nb, struct s_flags flags, int maj);
int				ft_puthex(unsigned int nb, int maj);
int				ft_hexlen(unsigned int nb);
int				ft_puthex_width(unsigned int nb, struct s_flags flags, int maj);
int				ft_puthex_width_prec
(unsigned int nb, struct s_flags flags, int maj);
int				ft_puthex_prec(unsigned int nb, struct s_flags flags, int maj);
#endif
