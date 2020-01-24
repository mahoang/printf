/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:50:28 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/24 06:27:54 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_access(const char *s, int *i, va_list lst_arg)
{
	struct s_flags	flags;
	int				ret;

	(*i)++;
	ft_flag(s, i, &flags, lst_arg);
	if (s[*i] == 'c')
		ret = ft_char_flags(va_arg(lst_arg, int), flags);
	else if (s[*i] == 's')
		ret = ft_string_flags(va_arg(lst_arg, char *), flags);
	else if (s[*i] == 'd' || s[*i] == 'i')
		ret = ft_number_flags(va_arg(lst_arg, int), flags);
	else if (s[*i] == 'u')
		ret = ft_number_flags(va_arg(lst_arg, unsigned long), flags);
	else if (s[*i] == 'p')
		ret = ft_pnt_flags(va_arg(lst_arg, unsigned long), flags);
	else if (s[*i] == 'x')
		ret = ft_hexa_flags(va_arg(lst_arg, unsigned int), flags, 0);
	else if (s[*i] == 'X')
		ret = ft_hexa_flags(va_arg(lst_arg, unsigned int), flags, 1);
	else
		ret = ft_print_misc(s[*i], flags);
	if (s[*i] != '\0')
		(*i)++;
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	va_list	lst_arg;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(lst_arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ret += ft_access(str, &i, lst_arg);
		else
		{
			write(1, &str[i++], 1);
			ret++;
		}
	}
	va_end(lst_arg);
	return (ret);
}

int		ft_print_misc(char c, struct s_flags flags)
{
	int pad;

	pad = flags.width - 1;
	if (c == '\0')
		return (0);
	while (flags.minus == 0 && flags.zero == 0 && pad-- > 0)
		write(1, " ", 1);
	while (flags.minus == 0 && flags.zero == 1 && pad-- > 0)
		write(1, "0", 1);
	write(1, &c, 1);
	while (flags.minus == 1 && pad-- > 0)
		write(1, " ", 1);
	if (flags.width > 0)
		return (flags.width);
	return (1);
}

int		ft_towrite(long nb, char a)
{
	write(1, &a, 1);
	nb = -nb;
	return (nb);
}
