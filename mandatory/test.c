/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:25:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/11 14:08:43 by tomek            ###   ########.fr       */
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

	p1 = ft_printf("%-.09s, %.03s, %.09s, %.09s", "(char *)NULL", "(char *)NULL", \
		"test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	ft_printf("\nbytes\t:%d\n", p1);
	p2 = printf("%-.09s, %.03s, %.09s, %.09s", "(char *)NULL", "(char *)NULL", \
		"test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	printf("\nbytes\t:%d\n", p2);
	p3 = ft_printf("%3.1s, %9.1s, %-3.1s, %-9.1s", "(char *)NULL", "(char *)NULL", "(char *)NULL", "(char *)NULL");
	ft_printf("\nbytes\t:%d\n", p3);
	p4 = printf("%3.1s, %9.1s, %-3.1s, %-9.1s", "(char *)NULL", "(char *)NULL", "(char *)NULL", "(char *)NULL");
	printf("\nbytes\t:%d\n", p4);
	return (0);
}
