/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:50:28 by mahoang           #+#    #+#             */
/*   Updated: 2019/11/21 13:19:06 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//s
void	ft_printf_str(va_list *lst_var);
{
	char *src = va_arg(*lst_var, char *);

	write(1, src, strlen(src));
}
//c
void	ft_printf_char(va_list *lst_var)
{
	unsigned char c = va_arg(*lst_var, int)
	write(1, &c, 1);
}
// d | i
void	ft_printf_nbr(va_list *lst_var)
{
	int num = va_arg(*lst_var, int);
	size_t c;

	c = 0;
	if (num == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_fd(147483648);
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10);
	ft_putchar_fd((num % 10) + '0');
}

//p | u | x | X | %
// - | 0 | .| *

int ft_chrIndex(char *tab, char element)
{
	int index = 0;

	while (tab[index] != 0)
	{
		if (tab[index] == element)
			return (index);
		index++;
	}
	return (-1);
}
int		ft_printf(const char *str, ...)
{
	void (*tabfunction[]) (va_list *) = {ft_printf_char, ft_printf_str, ft_printf_nbr, ft_printf_nbr,};
	char *tabindex;
	va_list lst_var;
	int i;

	i = 0;
	va_start(lst_var, str);
	va_end(lst_var);
}

// cspdiuxX%
// conversion -c/-s

