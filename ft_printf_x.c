/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:34:40 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/27 04:04:16 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexlen(unsigned int nb)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int		ft_puthex_width_prec(unsigned int nb, struct s_flags flags, int maj)
{
	int		ret;
	int		count;
	int		pad;

	ret = 0;
	count = flags.precision - ft_hexlen(nb);
	count += (nb < 0) ? 1 : 0;
	count = (count > 0) ? count : 0;
	pad = flags.width - ft_hexlen(nb) - count;
	pad = (pad > 0) ? pad : 0;
	ret += pad + count + ft_hexlen(nb);
	while (flags.minus == 0 && pad-- > 0)
		write(1, " ", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (count-- > 0)
		write(1, "0", 1);
	ft_puthex(nb, maj);
	while (flags.minus == 1 && pad-- > 0)
		write(1, " ", 1);
	return (ret);
}

int		ft_puthex_width(unsigned int nb, struct s_flags flags, int maj)
{
	int ret;
	int pad;

	ret = 0;
	pad = (flags.width - ft_hexlen(nb));
	while (flags.minus == 0 && pad-- > 0)
	{
		write(1, " ", 1);
		ret++;
	}
	ret += ft_puthex(nb, maj);
	while (flags.minus == 1 && pad-- > 0)
	{
		write(1, " ", 1);
		ret++;
	}
	return (ret);
}

int		ft_puthex_prec(unsigned int nb, struct s_flags flags, int maj)
{
	int ret;
	int pad;

	ret = 0;
	pad = (flags.dot == 1) ? flags.precision : flags.width;
	pad -= (flags.minus == 0) ? ft_hexlen(nb) : ft_hexlen(nb);
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
	ret += ft_puthex(nb, maj);
	return (ret);
}

int		ft_puthex(unsigned int nb, int maj)
{
	int		ret;
	int		c;
	char	*set;

	c = 0;
	ret = 0;
	if (maj == 1)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	if (nb / 16 > 0)
	{
		ret += ft_puthex(nb / 16, maj);
	}
	c = nb % 16;
	write(1, &set[c], 1);
	ret++;
	return (ret);
}
