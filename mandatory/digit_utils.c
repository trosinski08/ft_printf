/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:47:16 by tomek             #+#    #+#             */
/*   Updated: 2024/06/24 10:49:06 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	zero_len_clac(t_format *f, int len, int nbr)
{
	int	zero_len;

	zero_len = 0;
	if (f->prec >= len)
	{
		if (nbr < 0 || f->plus == 1 || f->space == 1)
			zero_len = f->prec - len + 1;
		else
			zero_len = f->prec - len;
	}
	return (zero_len);
}

int	hash_conv(int nbr, t_format *f)
{
	int	i;

	i = 0;
	if (f->type == 'X')
		i += write(1, "0X", 2);
	else if (f->type == 'x')
		i += write(1, "0x", 2);
	f->hash = 0;
	return (i);
}

int	space_len_clac(t_format *f, int len, int zero_len, int nbr)
{
	int	space_len;

	space_len = 0;
	if (f->width > len && f->width > f->prec && f->minus == 0)
		space_len = f->width - len - zero_len;
	if (f->zero == 1 && f->minus == 0 && f->prec <= 0 && !f->dot)
	{
		if (nbr < 0)
			space_len++;
		else if (f ->plus == 1 && nbr >= 0)
			space_len++;
		else if (f ->space == 1 && nbr >= 0 && f->minus == 0)
			space_len++;
	}
	return (space_len);
}

int	flag_checker(int nbr, int base, t_format *f)
{
	int		i;

	i = 0;
	if (f->hash == 1 && nbr != 0)
		i += hash_conv(nbr, f);
	if (nbr < 0)
		i += minus_nbr(nbr, base, f);
	else if (f ->plus == 1 && nbr >= 0)
		i += plus_conv(nbr, base, f);
	else if (f ->space == 1 && nbr >= 0)
		i += space_conv(nbr, base, f);
}

int	zero_printer(int zero_len)
{
	int	i;

	i = 0;
	while (i < zero_len)
		i += write(1, "0", 1);
	return (i);
}
