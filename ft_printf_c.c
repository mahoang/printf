/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:32:07 by mahoang           #+#    #+#             */
/*   Updated: 2019/12/23 12:30:09 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_flags(const char c, struct s_flags flags)
{
	if (flags.width > 0 && flags.minus == 1)
		return (ft_putchar_minus_width(c, flags.width));
	else if (flags.width > 0 && flags.zero == 1)
		return (ft_putchar_zero_width(c, flags.width));
	else if (flags.width > 0)
		return (ft_putchar_width(c, flags.width));
	else
		return (ft_putchar(c));
}

int		ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putchar_minus_width(int c, int width)
{
	int i;

	i = 0;
	write(1, &c, 1);
	while (i++ < width - 1)
		write(1, " ", 1);
	return (width);
}

int		ft_putchar_zero_width(int c, int width)
{
	int i;

	i = 0;
	while (i++ < width - 1)
		write(1, "0", 1);
	write(1, &c, 1);
	return (width);
}

int		ft_putchar_width(int c, int width)
{
	int i;

	i = 0;
	while (i++ < width - 1)
		write(1, " ", 1);
	write(1, &c, 1);
	return (width);
}
