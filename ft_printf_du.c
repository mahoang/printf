/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_du.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:35:24 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/24 01:10:56 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_number_flags(long nb, struct s_flags flags)
{
	int c;

	c = 0;
	if (flags.dot == 1 && flags.precision >= 0 && nb == 0)
	{
		//printf("test1");
		// printf("minus %i\n", flags.minus);
		// printf("width %i\n", flags.width);
		// printf("dot %i\n", flags.dot);
		// printf("prec %i\n", flags.precision);
		c = (flags.precision > flags.width) ? flags.precision : flags.width;
		if (flags.minus == 0 && c == flags.precision)
		{
			while (c-- > flags.width)
				write(1, "0", 1);
			while (c-- >= 0)
				write(1, " ", 1);
		}
		if (flags.minus == 0 && c == flags.width)
		{
			while (c-- > flags.precision)
				write(1, " ", 1);
			while (c-- >= 0)
				write(1, "0", 1);
		}
		if (flags.minus == 1)
			return (ft_putnbr_width_prec(nb, flags));
		if (flags.width > flags.precision)
			return (flags.width);
		return (flags.precision);
	}
	if (flags.width >= 0 && flags.dot == 1)
		return (ft_putnbr_width_prec(nb, flags));
	else if (flags.width > 0 && flags.zero == 0)
		return (ft_putnbr_width(nb, flags));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_putnbr_prec(nb, flags));
	else
		return (ft_putnbr(nb));
}

int		ft_nbrlen(long nb)
{
	int ret;

	ret = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		ret++;
	}
	while (nb >= 1)
	{
		nb = nb / 10;
		ret++;
	}
	return (ret);
}

int		ft_putnbr_width_prec(long nb, struct s_flags flags)
{
	int		ret;
	int		count;
	int		pad;

	ret = 0;
	//printf("test3");
	count = flags.precision - ft_nbrlen(nb);
	count += (nb < 0) ? 1 : 0;
	count = (count > 0) ? count : 0;
	pad = flags.width - ft_nbrlen(nb) - count;
	pad = (pad > 0) ? pad : 0;
	ret += pad + count + ft_nbrlen(nb);
	while (flags.minus == 0 && pad-- > 0)
		write(1, " ", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (count-- > 0)
		write(1, "0", 1);
	if (nb == 0 && flags.precision != 0)
	{
		write(1, "0", 1);
		count--;
		pad--;
	}
	if (nb != 0)
		ft_putnbr(nb);
	else
		write(1, " ", 1);
	while (flags.minus == 1 && pad-- > 0)
		write(1, " ", 1);
	return (ret);
}

int		ft_putnbr_width(long nb, struct s_flags flags)
{
	int ret;
	int pad;

	//printf("test1");
	ret = 0;
	pad = flags.width - ft_nbrlen(nb);
	while (flags.minus == 0 && pad-- > 0)
	{
		write(1, " ", 1);
		ret++;
	}
	ret += ft_putnbr(nb);
	while (flags.minus == 1 && pad-- > 0)
	{
		write(1, " ", 1);
		ret++;
	}
	return (ret);
}

int		ft_putnbr_prec(long nb, struct s_flags flags)
{
	int ret;
	int pad;

	ret = 0;
	//printf("test2");
	pad = (flags.dot == 1) ? flags.precision : flags.width;
	pad -= (flags.minus == 0) ? ft_nbrlen(nb) : ft_nbrlen(nb) - 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ret++;
	}
	while (pad-- > 0)
	{
		write(1, "0", 1);
		ret++;
	}
	ret += ft_putnbr(nb);
	return (ret);
}

int		ft_putnbr(long nb)
{
	char	c;
	int		ret;

	//printf("test3");
	ret = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		ret++;
		nb = -nb;
	}
	if (nb / 10 > 0)
		ret += ft_putnbr(nb / 10);
	c = nb % 10 + 48;
	write(1, &c, 1);
	ret++;
	return (ret);
}

