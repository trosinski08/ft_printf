/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_h_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:01:21 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 02:27:47 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	min_conv(long nbr, t_format *f, int len, int i)
{
	int		c;

	f -> type = 0;
	while (i < f->width)
		i += write(1, " ", 1);
	return (i);
}
	// if (nbr == -ULONG_MAX)
	// 	c = 11; l33/34

unsigned long	print_hb(unsigned long nbr, unsigned int base, t_format *f)
{
	int		i;
	char	*low_base;

	i = 0;
	low_base = "0123456789ABCDEF";
	if (nbr < base)
		i += ft_putchar(low_base[nbr]);
	else
	{
		i += print_hb(nbr / base, base, f);
		if (i == -1)
			return (-1);
		i += print_hb(nbr % base, base, f);
	}
	return (i);
}

unsigned long	print_h_up(unsigned long nbr, unsigned int base, t_format *f)
{
	int		i;
	int		len;

	i = 0;
	len = ft_digit_len(nbr, base, f);
	f->type = 'X';
	i += non_minus_conv(nbr, f, len, base);
	if (f->prec >= 0)
		i += print_hb(nbr, base, f);
	if (f->minus == 1)
		i = (min_conv(nbr, f, len, i));
	return (i);
}
