/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:25:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/10 23:46:25 by trosinsk         ###   ########.fr       */
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

	p1 = ft_printf("%5.1s, %5.1s, %5.0s, %5.0s", "(char *)NULL", "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	ft_printf("\nbytes\t:%d\n", p1);
	p2 = printf("%5.1s, %5.1s, %5.0s, %5.0s", "(char *)NULL", "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	printf("\nbytes\t:%d\n", p2);
	p3 = ft_printf("%5.5s, %5.5s, %5.5s, %5.5s", "(char *)NULL", "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	ft_printf("\nbytes\t:%d\n", p3);
	p4 = printf("%5.5s, %5.5s, %5.5s, %5.5s", "(char *)NULL", "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	printf("\nbytes\t:%d\n", p4);
	return (0);
}
