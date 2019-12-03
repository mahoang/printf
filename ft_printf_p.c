/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:32:14 by mahoang           #+#    #+#             */
/*   Updated: 2019/12/03 16:02:28 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pnt_flags(unsigned long nb, struct s_flags flags)
{
	if (flags.width > 0 && flags.minus == 1)
		return (0);
	else if (flags.width > 0 && flags.zero == 1)
		return (0);
	else if (flags.width > 0)
		return (0);
	else
		return (ft_putpnt(nb, 1));
}

int		ft_putpnt(unsigned long nb, int firsttime)
{
	int		c;
	int		ret;
	char	*set;

	ret = 0;
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
