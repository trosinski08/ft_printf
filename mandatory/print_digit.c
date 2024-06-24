/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:00:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 02:09:40 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	prec_min(int len, t_format *f, int i)
{
	int	count;

	f->prec = -1;
	count = f->width - f->plus - f->space;
	if (f->plus == 1 && f->minus)
	{
		i += write(1, "+", 1);
		count--;
		f->plus = 0;
	}
	while (i < count)
		i += write(1, " ", 1);
	len = 0;
	return (i);
}

static int	min_conv(long nbr, t_format *f, int len, int i)
{
	int		c;

	f -> type = 0;
	while (i < f->width)
		i += write(1, " ", 1);
	return (i);
}


int	non_minus_conv(long nbr, t_format *f, int len, int base)
{
	int		i;
	int		zero_len;
	int		space_len;
	int		count;
	char	c;

	i = 0;
	count = 0;
	zero_len = 0;
	space_len = 0;
	c = ' ';
	if (f->zero == 1 && f->minus == 0 && f->prec <= 0 && !f->dot)
		c = '0';
	if (f->prec == 0 && nbr == 0 && f->dot == 1)
		i += prec_min(len, f, i);
	if (f->prec >= len)
	{
		if (nbr < 0 || f->plus == 1 || f->space == 1)
			zero_len = f->prec - len + 1;
		else
			zero_len = f->prec - len;
	}
	if (f->width > len && f->width > f->prec && f->minus == 0)
		space_len = f->width - len - zero_len;
	if (nbr < 0 && c == '0')
	{
		i += minus_nbr(nbr, base, f);
		space_len++;
	}
	else if ((f ->plus == 1 && nbr >= 0) && c == '0')
	{
		i += plus_conv(nbr, base, f);
		space_len++;
	}
	else if ((f ->space == 1 && nbr >= 0 && f->minus == 0) && c == '0')
	{
		i += space_conv(nbr, base, f);
		space_len++;
	}
	while (i < space_len)
		i += write(1, &c, 1);
	if (f->hash == 1 && nbr != 0)
	{
		if (f->type == 'X')
			i += write(1, "0X", 2);
		else if (f->type == 'x')
			i += write(1, "0x", 2);
		f->hash = 0;
	}
	if (nbr < 0 && c != '0')
		i += minus_nbr(nbr, base, f);
	else if (((f ->plus == 1 && nbr >= 0) && c != '0'))
		i += plus_conv(nbr, base, f);
	else if (f ->space == 1 && nbr >= 0  && c != '0')
		i += space_conv(nbr, base, f);
	while (count < zero_len)
	{
		i += write(1, "0", 1);
		count++;
	}
	return (i);
}

int	print_digit_prep(long nbr, int base, t_format *f)
{
	int		i;
	int		len;

	i = 0;
	len = ft_digit_len(nbr, base, f);
	i += non_minus_conv(nbr, f, len, base);
	if (f->prec >= 0)
		i += print_digit(nbr, base);
	if (f->minus == 1)
		i = min_conv(nbr, f, len, i);
	return (i);
}
