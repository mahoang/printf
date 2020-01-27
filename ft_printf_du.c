/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_du.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:35:24 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/27 05:17:10 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	count = flags.precision - ft_nbrlen(nb);
	count += (nb < 0) ? 1 : 0;
	count = (count > 0) ? count : 0;
	pad = flags.width - ft_nbrlen(nb) - count;
	pad = (pad > 0) ? pad : 0;
	ret = pad + count + ft_nbrlen(nb);
	while (flags.minus == 0 && pad-- > 0)
		write(1, " ", 1);
	if (nb < 0)
		nb = ft_towrite(nb);
	while (count-- > 0)
		write(1, "0", 1);
	if (nb == 0 && flags.precision != 0 && count-- && pad--)
		write(1, "0", 1);
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
	pad = (flags.dot == 1) ? flags.precision : flags.width;
	pad -= (flags.minus == 0) ? ft_nbrlen(nb) : ft_nbrlen(nb) - 1;
	if (nb < 0)
	{
		nb = ft_towrite(nb);
		ret++;
	}
	if (flags.minus == 1)
	{
		ret += ft_putnbr(nb);
		while (pad-- > 1 && ret++)
			write(1, " ", 1);
		return (ret);
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
