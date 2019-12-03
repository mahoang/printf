/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:32:07 by mahoang           #+#    #+#             */
/*   Updated: 2019/12/03 16:01:51 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_flags(const char c, struct s_flags flags)
{
	if (flags.width > 0 && flags.minus == 1)
		return (0);
	else if (flags.width > 0 && flags.zero == 1)
		return (0);
	else if (flags.width > 0)
		return (0);
	else
		return (ft_putchar(c));
}

int		ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}
