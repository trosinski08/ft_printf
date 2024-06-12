/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:23:17 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/12 03:06:26 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static unsigned long	min_conv(unsigned long nbr, t_format *f, int base)
{
	int	c;
	int	i;
	int	h;

	i = 0;
	h = 1;
	if (f ->hash == 1 && nbr != 0)
		h = 3;
	while (nbr / base != 0)
	{
		h++;
		nbr /= base;
	}
	c = f ->width - h;
	f->width = 0;
	f -> type = 0;
	while (i < c)
		i += write(1, " ", 1);
	return (i);
}
	// if (nbr == -ULONG_MAX)
	// 	c = 11;

unsigned long	print_hs(unsigned long nbr, unsigned int base, t_format *f)
{
	int		i;
	char	*low_base;

	i = 0;
	low_base = "0123456789abcdef";
	if (nbr < base)
		i += ft_putchar(low_base[nbr]);
	else
	{
		i += print_hs(nbr / base, base, f);
		if (i == -1)
			return (-1);
		i += print_hs(nbr % base, base, f);
	}
	return (i);
}

unsigned long	print_hexa(unsigned long nbr, unsigned int base, t_format *f)
{
	int		i;
	int		len;

	i = 0;
	len = ft_digit_len(nbr, base, f);
	if (f->width > i && f->minus == 0 && f->zero == 0 && f->prec == 0)
		i += (min_conv(nbr, f, base));
	if (f ->hash == 1 && nbr != 0)
	{
		write(1, "0x", 2);
		f->hash = 0;
		i = 2;
	}
	if (f ->width > len && f->minus == 0 && f->zero == 1)
		i += zero_conv(nbr, base, f, len);
	else if (f->minus == 0 && f->zero == 0 && f->prec > 0)
		i += prec_conv(nbr, base, f, len);
	i += print_hs(nbr, base, f);
	if (f->width > i && f->minus == 1)
		i += (min_conv(nbr, f, base));
	return (i);
}
