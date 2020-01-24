/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:19:16 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/24 03:57:39 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		contain_flag(const char c)
{
	if (c == '-' || c == '*' || c == '.' || c == ' ' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int		ft_atoi(const char *s, int *i, va_list lst_arg)
{
	int count;

	count = 0;
	if (s[*i] == '.')
		(*i)++;
	if (s[*i] == '*')
		return (count = va_arg(lst_arg, unsigned int));
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		count = count * 10 + (s[*i] - '0');
		(*i)++;
	}
	(*i)--;
	return (count);
}

void	ft_negative_flag(struct s_flags *flags)
{
	if (flags->precision < 0)
	{
		flags->dot = 0;
		flags->precision = 0;
	}
	else if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
	}
	return ;
}

void	ft_flag(const char *s, int *i, struct s_flags *flags, va_list lst_arg)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->width = 0;
	while ((is_conversion(s[*i]) == 0) && contain_flag(s[*i]) == 1)
	{
		if (s[*i] == '-')
			flags->minus = 1;
		else if (s[*i] == '0')
			flags->zero = 1;
		else if (s[*i] == '.')
		{
			flags->dot = 1;
			flags->precision = ft_atoi(s, i, lst_arg);
		}
		else if (s[*i] == '*' || (s[*i] >= '1' && s[*i] <= '9'))
			flags->width = ft_atoi(s, i, lst_arg);
		if (flags->precision < 0 || flags->width < 0)
			ft_negative_flag(flags);
		(*i)++;
	}
}
