/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:00:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 10:50:41 by tomek            ###   ########.fr       */
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

int	non_minus_conv(long nbr, t_format *f, int len, int base)
{
	int		i;
	int		zero_len;
	int		space_len;
	char	c;

	i = 0;
	c = ' ';
	if (f->zero == 1 && f->minus == 0 && f->prec <= 0 && !f->dot)
		c = '0';
	if (f->prec == 0 && nbr == 0 && f->dot == 1)
		i += prec_min(len, f, i);
	zero_len = zero_len_clac(f, len, nbr);
	space_len = space_len_clac(f, len, zero_len, nbr);
	if (c == '0')
		i += flag_checker(nbr, base, f);
	while (i < space_len)
		i += write(1, &c, 1);
	if (f->hash == 1 && nbr != 0)
		i += hash_conv(nbr, f);
	if (c != '0')
		i += flag_checker(nbr, base, f);
	if (zero_len > 0)
		i += zero_printer(zero_len);
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
		while (i < f->width)
			i += write(1, " ", 1);
	return (i);
}
