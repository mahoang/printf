/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_du.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:35:24 by mahoang           #+#    #+#             */
/*   Updated: 2019/12/03 14:44:01 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_number(unsigned long nb, struct s_flags flags)
{
	if (flags.width > 0 && flags.minus == 1)
		return (0);
	else if (flags.width > 0 && flags.zero == 1)
		return (0);
	else if (flags.width > 0)
		return (0);
	else
		return (ft_putnbr(nb));
}

int		ft_putnbr(unsigned long nb)
{
	char	c;
	int		ret;

	ret = 0;
	if (nb < 0)
	{
		write(1, "-", 2);
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

