/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:07:31 by mahoang           #+#    #+#             */
/*   Updated: 2019/12/04 11:38:43 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(int ac, char **av)
{
	char *c = "      Hello, World!G";
	char *d = "Hello, World!G";
	int integer = -342;
	long ptr = 123456789;
	char *e = "tests";
	unsigned int hexa = 45;

	// int ftret = ft_printf("%s\n", d);
	// ft_printf("%s\n%d\n", d, ftret);
	// int ret = ft_printf("%s\n", d);
	// printf("%s\n%d", d, ret);
	//printf("%*20s\n", d);
	//printf("%.*0s\n", d);
	//printf("%.5s\n", d);
	//printf("%-15s\n", d);
	printf("%-15d\n", integer);
	printf("%.15d\n", integer);
	printf("%.15d\n", integer);
	printf("%15d\n", integer);
	return 0;
}
//https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019#flags
//https://www.academia.edu/10297206/Secrets_of_printf_
