/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:32:14 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/22 04:44:09 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pnt_flags(unsigned long nb, struct s_flags flags)
{
	if (!nb)
	{
		write(1, "(nil)", 5);
		return (5);
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
int		ft_pntlen(unsigned long nb)
{
	int ret;

	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		nb = nb / 16;
		ret++;
	}
	return (ret);
}

int		ft_putpnt_width_prec(unsigned long nb, struct s_flags flags)
{
	int		ret;
	int		count;
	int		pad;

	ret = 0;
	//printf("test3");
	count = flags.precision - ft_pntlen(nb);
	count = (count > 0) ? count : 0;
	pad = flags.width -count - ft_pntlen(nb) - 2;
	pad = (pad > 0) ? pad : 0;
	ret += pad + count + 2;
	while (flags.minus == 0 && pad-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (count-- > 0)
		write(1, "0", 1);
	ret += ft_putpnt(nb, 0);
	while (flags.minus == 1 && pad-- > 0)
		write(1, " ", 1);
	return (ret);
}
int		ft_pnt_width(unsigned long nb, struct s_flags flags)
{
	int ret;
	int pad;

	ret = 0;
	pad = (flags.dot == 0) ? flags.width - 2 : flags.precision;
	pad -= ft_pntlen(nb);
	while (flags.minus == 0 && pad-- > 0)
	{
		write(1, " ", 1);
		ret++;
	}
	ret += ft_putpnt(nb, 1);
	while (flags.minus == 1 && pad-- > 0)
	{
		write(1, " ", 1);
		ret++;
	}
	return (ret);
}

int		ft_pnt_prec(unsigned long nb, struct s_flags flags)
{
	int ret;
	int pad;
	char *set;
	int c;

	write(1, "0x", 2);
	ret = 2;
	set = "0123456789abcdef";
	pad = (flags.dot == 1) ? flags.precision : flags.width;
	pad -= ft_pntlen(nb);
	while (pad-- > 0)
	{
		write(1, "0", 1);
		ret++;
	}
	if (nb > 16)
		ret +=(ft_putpnt(nb, 0));
	c = nb % 16;
	write(1, &set[c], 1);
	ret++;
	return (ret);
}

int		ft_putpnt(unsigned long nb, int firsttime)
{
	int		c;
	int		ret;
	char	*set;

	ret = 1;
	if (firsttime == 1)
	{
		write(1, "0x", 2);
		ret += 2;
	}
	set = "0123456789abcdef";
	if (nb / 16 > 0)
		ret += ft_putpnt(nb / 16, 0);
	c = nb % 16;
	write(1, &set[c], 1);
	ret++;
	return (ret);
}
