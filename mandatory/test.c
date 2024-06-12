/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:25:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/12 02:57:55 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	p1;
	int	p2;
	int	p3;
	int	p4;

	ft_printf("\n-----------------TEST-----------------\n");
	p1 = ft_printf(" %.8x %.9x %.10x %.11x %.12x %.13x %.14x", \
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("\nbytes\t:%d\n", p1);
	ft_printf("\n-----------------TEST-----------------\n");
	p2 = printf(" %.8x %.9x %.10x %.11x %.12x %.13x %.14x", \
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nbytes\t:%d\n", p2);
	ft_printf("\n-----------------TEST-----------------\n");
	p3 = ft_printf(" %.8X %.9X %.10X %.11X %.12X %.13X %.14X", \
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("\nbytes\t:%d\n", p3);
	ft_printf("\n-----------------TEST-----------------\n");
	p4 = printf(" %.8X %.9X %.10X %.11X %.12X %.13X %.14X", \
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nbytes\t:%d\n", p4);
	ft_printf("\n-----------------TEST-----------------\n");
	return (0);
}
