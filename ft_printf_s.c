/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:17:49 by mahoang           #+#    #+#             */
/*   Updated: 2019/12/03 18:30:55 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *c)
{
	int i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int		ft_string_flags(char *c, struct s_flags flags)
{
	if (flags.width > 0 && flags.minus == 1)
		return (0);
	else if (flags.width > 0 && flags.zero == 1)
		return (0);
	else if (flags.width > 0)
		return (0);
	else
		return (ft_putstr(c));
}

int		ft_putstr(char *c)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i++], 1);
		ret++;
	}
	return (ret);
}
