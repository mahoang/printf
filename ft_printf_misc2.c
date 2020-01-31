/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:51:20 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/31 18:57:01 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbr_0(struct s_flags flags)
{
	int c;

	c = 0;
	c = (flags.precision > flags.width) ? flags.precision : flags.width;
	if (flags.zero == 0 && flags.minus == 0 && c == flags.precision)
		ft_nbr_1(flags, c);
	else if (flags.zero == 0 && flags.minus == 0 && c == flags.width)
		ft_nbr_2(flags, c);
	else if (flags.minus == 1 && flags.dot == 1 && flags.width == 0)
	{
		while (c-- > 0)
			write(1, "0", 1);
		if (flags.width > flags.precision)
			return (flags.width);
		return (flags.precision);
	}
	else if (flags.zero == 1 && c == flags.precision)
		ft_nbr_2(flags, c);
	else if (flags.zero == 1 && c == flags.width)
		ft_nbr_3(flags, c);
	else if (flags.minus == 1)
		ft_nbr_4(flags, c);
	if (flags.width > flags.precision)
		return (flags.width);
	return (flags.precision);
}

void	ft_nbr_1(struct s_flags flags, int c)
{
	while (c-- > flags.width)
		write(1, "0", 1);
	if (flags.precision > flags.width)
		while (c-- >= 0)
			write(1, "0", 1);
	while (flags.width == flags.precision && c-- >= 0)
		write(1, "0", 1);
	while (c-- >= 0)
		write(1, " ", 1);
}

void	ft_nbr_3(struct s_flags flags, int c)
{
	if (flags.minus == 1 && flags.precision > flags.width)
	{
		while (c-- > flags.precision)
			write(1, "0", 1);
		while (c-- >= 0)
			write(1, " ", 1);
	}
	else if (flags.minus == 1 && flags.precision < flags.width)
	{
		while (c-- > (flags.width - flags.precision))
			write(1, "0", 1);
		while (c-- >= 0)
			write(1, " ", 1);
	}
	else
	{
		while (c-- > flags.precision)
			write(1, " ", 1);
		while (c-- >= 0)
			write(1, "0", 1);
	}
}

void	ft_nbr_2(struct s_flags flags, int c)
{
	while (c-- > flags.precision)
		write(1, " ", 1);
	while (c-- >= 0)
		write(1, "0", 1);
}

void	ft_nbr_4(struct s_flags flags, int c)
{
	int lesser;

	lesser = 0;
	while (lesser++ != flags.precision)
		write(1, "0", 1);
	while (lesser++ <= c)
		write(1, " ", 1);
}
