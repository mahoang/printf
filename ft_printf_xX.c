/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:34:40 by mahoang           #+#    #+#             */
/*   Updated: 2019/12/03 16:16:31 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexa_flags(unsigned int nb, struct s_flags flags, int maj)
{
	if (flags.width > 0 && flags.minus == 1)
		return (0);
	else if (flags.width > 0 && flags.zero == 1)
		return (0);
	else if (flags.width > 0)
		return (0);
	else
		return (ft_puthex(nb, maj));
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
