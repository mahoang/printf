/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:22:19 by mahoang           #+#    #+#             */
/*   Updated: 2019/11/21 11:45:46 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_A
#define LIBFTPRINTF_A

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define va_arg(ap, param)

int					ft_printf(const char *str, ...);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
typedef struct		tabindex
{
char		s;
char		c;
char		p;
char		d;
char		i;
char		u;
char		x;
char		X;
char		0;
}					t_list;

#endif
