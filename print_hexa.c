/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:23:17 by trosinsk          #+#    #+#             */
/*   Updated: 2023/11/10 13:07:02 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	print_hexa(unsigned long nbr, unsigned int base, t_format *f)
{
	int		i;
	char	*low_base;

	i = 0;
	if (f ->hash == 1 && nbr != 0)
	{
		write(1, "0x", 2);
		f->hash = 0;
		i = 2;
		return (i + print_hexa(nbr, base, f));
	}
	low_base = "0123456789abcdef";
	if (nbr < base)
		return (print_char(low_base[nbr]));
	else
	{
		i += print_hexa(nbr / base, base, f);
		if (i == -1)
			return (-1);
		return (i + print_hexa(nbr % base, base, f));
	}
	return (i);
}
