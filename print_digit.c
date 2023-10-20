/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:00:45 by trosinsk          #+#    #+#             */
/*   Updated: 2023/10/20 00:42:34 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long nbr, int base)
{
	int		i;
	char	*low_base;

	i = 0;
	if (i == -1)
		return (-1);
	low_base = "0123456789abcdef";
	if (nbr < 0)
	{
		i += write (1, "-", 1);
		if (i == -1)
			return (-1);
		return (print_digit(-nbr, base) + 1);
	}
	else if (nbr < base)
		return (print_char(low_base[nbr]));
	else
	{
		i += print_digit(nbr / base, base);
		if (i == -1)
			return (-1);
		return (i + print_digit(nbr % base, base));
	}
	return (i);
}
