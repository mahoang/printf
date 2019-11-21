/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:06:28 by mahoang           #+#    #+#             */
/*   Updated: 2019/11/12 18:18:01 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		ft_len(int n)
{
	int count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static	char	*ft_transform(int n, int count, int minus, char *nb)
{
	nb[count] = '\0';
	count--;
	while (count >= 0 && n > 0)
	{
		nb[count] = (n % 10) + '0';
		n /= 10;
		if (count > 0)
			count--;
	}
	if (minus == 1)
		nb[0] = '-';
	if (minus == 2)
		nb[0] = '0';
	return (nb);
}

char			*ft_itoa(int n)
{
	char	*nb;
	int		count;
	int		minus;

	minus = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	if (n == 0)
		minus = 2;
	count = ft_len(n);
	if (minus == 1)
		count++;
	if (!(nb = malloc(sizeof(char) * count + 1)))
		return (NULL);
	nb = ft_transform(n, count, minus, nb);
	return (nb);
}
