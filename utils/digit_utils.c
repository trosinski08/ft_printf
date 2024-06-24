/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:47:16 by tomek             #+#    #+#             */
/*   Updated: 2024/06/24 20:22:04 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	zero_len_calc(t_format *f, int len, long nbr)
{
	int	zero_len;

	zero_len = 0;
	if (f->prec >= len)
	{
		if ((nbr < 0) || f->plus == 1 || f->space == 1)
			zero_len = f->prec - len + 1;
		else
			zero_len = f->prec - len;
	}
	return (zero_len);
}

int	hash_conv(long nbr, t_format *f)
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

int	space_len_calc(t_format *f, int len, long nbr, char c)
{
	int	space_len;
	int	zero_len;

	space_len = 0;
	zero_len = zero_len_calc(f, len, nbr);
	if (f->width > len && f->width > f->prec && f->minus == 0)
		space_len = f->width - len - zero_len;
	if (f->hash == 1 && nbr != 0 && c != '0')
		space_len -= 2;
	if (c == '0' && (nbr < 0 || (f->plus && nbr >= 0) \
		|| (f->space && nbr >= 0)))
		space_len++;
	return (space_len);
}

int	flag_checker(long nbr, int base, t_format *f, char c)
{
	int		i;

	i = 0;
	if (f->hash == 1 && nbr != 0)
		i += hash_conv(nbr, f);
	else if (nbr < 0)
		i += minus_nbr(nbr, base, f);
	else if (f ->plus == 1 && nbr >= 0)
		i += plus_conv(nbr, base, f);
	else if (f ->space == 1 && nbr >= 0)
		i += space_conv(nbr, base, f);
	return (i);
}

int	zero_printer(int zero_len)
{
	int	i;

	i = 0;
	while (i < zero_len)
		i += write(1, "0", 1);
	return (i);
}
