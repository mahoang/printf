/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:17:49 by mahoang           #+#    #+#             */
/*   Updated: 2020/01/24 05:07:47 by mahoang          ###   ########.fr       */
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

int		ft_putstr_width_dot(char *c, struct s_flags flags)
{
	char	i;
	int		pad;
	int		a;
	int		ret;

	i = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		i = '0';
	ret = (ft_strlen(c) < flags.precision) ? ft_strlen(c) : flags.precision;
	pad = (flags.width > ret) ? flags.width - ret : 0;
	a = 0;
	while (flags.minus == 1 && a < flags.precision && c[a] != '\0')
		write(1, &c[a++], 1);
	a = 0;
	while (a++ < pad)
		write(1, &i, 1);
	a = 0;
	while (flags.minus == 0 && a < flags.precision && c[a] != '\0')
		write(1, &c[a++], 1);
	return (ret > flags.width ? ret : flags.width);
}

int		ft_putstr_width(char *c, struct s_flags flags)
{
	char	i;
	int		a;
	int		pad;

	i = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		i = '0';
	pad = (flags.width > ft_strlen(c) ? flags.width - ft_strlen(c) : 0);
	a = 0;
	while (flags.minus == 1 && c[a] != '\0')
		write(1, &c[a++], 1);
	a = 0;
	while (a++ < pad)
		write(1, &i, 1);
	a = 0;
	while (flags.minus == 0 && c[a] != '\0')
		write(1, &c[a++], 1);
	return (ft_strlen(c) > flags.width) ? ft_strlen(c) : flags.width;
}

int		ft_putstr_prec(char *c, int prec)
{
	int i;
	int ret;

	ret = (ft_strlen(c) < prec) ? ft_strlen(c) : prec;
	i = 0;
	while (i < ret && c[i] != '\0')
		write(1, &c[i++], 1);
	return (ret);
}
