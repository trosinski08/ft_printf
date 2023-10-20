/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 06:16:22 by trosinsk          #+#    #+#             */
/*   Updated: 2023/10/20 00:43:06 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	print_pointer(unsigned long nbr, unsigned int base)
{
	int		i;
	char	*low_base;

	i = 0;
	i += print_char('0');
	if (i == -1)
	{
		return (-1);
	}
	i += print_char('x');
	low_base = "0123456789abcdef";
	if (nbr < base)
	{
		return (i + print_char(low_base[nbr]));
	}
	else
	{
		i += print_hexa(nbr / base, base);
		if (i == -1)
			return (-1);
		return (i + print_hexa(nbr % base, base));
	}
	return (i);
}
