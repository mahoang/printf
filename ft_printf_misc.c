/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 05:06:46 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/31 17:59:48 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pnt_flags(unsigned long nb, struct s_flags flags)
{
	int ret;

	ret = 0;
	if (flags.dot == 1 && flags.precision == 0 && nb == 0)
	{
		while (flags.width > ret + 2)
		{
			write(1, " ", 1);
			ret++;
		}
		write(1, "0x", 2);
		ret++;
		while (ret + 2 < flags.width)
			write(1, "0", 1);
		return (ret + 1);
	}
	if (flags.width > 0 && flags.dot == 1)
		return (ft_putpnt_width_prec(nb, flags));
	else if (flags.width > 0 && flags.zero == 0)
		return (ft_pnt_width(nb, flags));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_pnt_prec(nb, flags));
	else
		return (ft_putpnt(nb, 1));
}

int		ft_string_flags(char *c, struct s_flags flags)
{
	if (c == NULL)
	{
		if (flags.width > 0 && flags.dot == 1)
			return (ft_putstr_width_dot("(null)", flags));
		else if (flags.width > 0)
			return (ft_putstr_width("(null)", flags));
		else if (flags.dot == 1)
			return (ft_putstr_prec("(null)", flags.precision));
		else
			return (ft_putstr1("(null)"));
	}
	else
	{
		if (flags.width > 0 && flags.dot == 1)
			return (ft_putstr_width_dot(c, flags));
		else if (flags.width > 0)
			return (ft_putstr_width(c, flags));
		else if (flags.dot == 1)
			return (ft_putstr_prec(c, flags.precision));
		else
			return (ft_putstr1(c));
	}
}

int		ft_hexa_flags(unsigned int nb, struct s_flags flags, int maj)
{
	int i;

	i = 0;
	if (flags.dot == 1 && flags.precision == 0 && nb == 0)
	{
		while (i++ < flags.width)
			write(1, " ", 1);
		return (flags.width);
	}
	if (flags.width > 0 && flags.dot == 1)
		return (ft_puthex_width_prec(nb, flags, maj));
	else if (flags.width > 0 && flags.zero == 0)
		return (ft_puthex_width(nb, flags, maj));
	else if (flags.width > 0 && flags.zero == 1 && flags.minus == 1)
		return (ft_puthex_width(nb, flags, maj));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_puthex_prec(nb, flags, maj));
	else
		return (ft_puthex(nb, maj));
}

int		ft_number_flags(long nb, struct s_flags flags)
{
	if (flags.dot == 1 && flags.precision >= 0 && nb == 0)
		return (ft_nbr_0(flags));
	if (flags.width >= 0 && flags.dot == 1)
		return (ft_putnbr_width_prec(nb, flags));
	else if (flags.width > 0 && flags.zero == 0)
		return (ft_putnbr_width(nb, flags));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_putnbr_prec(nb, flags));
	else
		return (ft_putnbr(nb));
}
