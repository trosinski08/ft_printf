/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:00:45 by trosinsk          #+#    #+#             */
/*   Updated: 2023/11/11 17:15:52 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	minus_nbr(long nbr, int base, t_format *f)
{
	int	i;

	i = 0;
	i += write (1, "-", 1);
	if (i == -1)
		return (-1);
	f -> plus = 0;
	f -> space = 0;
	return (print_digit(-nbr, base, f) + 1);
}

int	plus_conv(long nbr, int base, t_format *f)
{
	int	i;

	i = 0;
	i += write(1, "+", 1);
	if (i == -1)
		return (-1);
	f ->plus = 0;
	return (i + print_digit(nbr, base, f));
}

int	space_conv(long nbr, int base, t_format *f)
{
	int	i;

	i = 0;
	i += write(1, " ", 1);
	if (i == -1)
		return (-1);
	f ->space = 0;
	return (i + print_digit(nbr, base, f));
}

int	print_digit(long nbr, int base, t_format *f)
{
	int		i;
	char	*low_base;

	i = 0;
	low_base = "0123456789abcdef";
	if (nbr < 0)
		return (minus_nbr(nbr, base, f));
	else if (f ->plus == 1 && nbr >= 0)
		return (plus_conv(nbr, base, f));
	else if (f ->space == 1 && nbr >= 0)
		return (space_conv(nbr, base, f));
	else if (nbr < base)
		return (print_char(low_base[nbr]));
	else
	{
		i += print_digit(nbr / base, base, f);
		if (i == -1)
			return (-1);
		return (i + print_digit(nbr % base, base, f));
	}
	return (i);
}
