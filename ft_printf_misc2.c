/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:51:20 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/27 05:52:01 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbr_0(long nb, struct s_flags flags)
{
	int c;

	c = 0;
	c = (flags.precision > flags.width) ? flags.precision : flags.width;
	if (flags.minus == 0 && c == flags.precision)
		ft_nbr_1(flags, c);
	if (flags.minus == 0 && c == flags.width)
		ft_nbr_1(flags, c);
	if (flags.minus == 1 && flags.dot == 1 && flags.width == 0)
	{
		while (c-- > 0)
			write(1, "0", 1);
		if (flags.width > flags.precision)
			return (flags.width);
		return (flags.precision);
	}
	if (flags.minus == 1)
		return (ft_putnbr_width_prec(nb, flags));
	if (flags.width > flags.precision)
		return (flags.width);
	return (flags.precision);
}

void	ft_nbr_1(struct s_flags flags, int c)
{
	if (flags.minus == 0 && c == flags.precision)
	{
		while (c-- > flags.width)
			write(1, "0", 1);
		while (c-- >= 0)
			write(1, " ", 1);
	}
}

void	ft_nbr_2(struct s_flags flags, int c)
{
	if (flags.minus == 0 && c == flags.precision)
	{
		while (c-- > flags.precision)
			write(1, "0", 1);
		while (c-- >= 0)
			write(1, " ", 1);
	}
}
