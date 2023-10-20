/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:01:21 by trosinsk          #+#    #+#             */
/*   Updated: 2023/10/20 00:42:55 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	print_hexa_up(unsigned long nbr, unsigned int base)
{
	int		i;
	char	*upp_base;

	i = 0;
	upp_base = "0123456789ABCDEF";
	if (nbr < base)
		return (print_char(upp_base[nbr]));
	else
	{
		i += print_hexa_up(nbr / base, base);
		if (i == -1)
			return (-1);
		return (i + print_hexa_up(nbr % base, base));
	}
	return (i);
}
