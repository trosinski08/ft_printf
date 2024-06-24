/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:23:17 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 22:21:32 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @file print_hexa.c
 * @brief Contains functions for printing hexadecimal numbers.
 */

/**
 * @brief Helper function for handling non-minus conversions.
 * @param f The format structure.
 * @param i The current count of characters written.
 * @return The updated count of characters written.
 */
// static int min_conv(t_format *f, int i);

/**
 * @brief Prints a hexadecimal number in lowercase.
 * @param nbr The number to be printed.
 * @param base The base of the number system.
 * @param f The format structure.
 * @return The count of characters written.
 */
// unsigned long print_hs(unsigned long nbr, unsigned int base, t_format *f);

/**
 * @brief Prints a hexadecimal number.
 * @param nbr The number to be printed.
 * @param base The base of the number system.
 * @param f The format structure.
 * @return The count of characters written.
 */
// unsigned long print_hexa(unsigned long nbr, unsigned int base, t_format *f);

static int	min_conv(t_format *f, int i)
{
	f -> type = 0;
	while (i < f->width)
		i += write(1, " ", 1);
	return (i);
}

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
	f->type = 'x';
	i += non_minus_conv(nbr, f, len);
	if (f->prec >= 0)
		i += print_hs(nbr, base, f);
	if (f->minus == 1)
		i = (min_conv(f, i));
	return (i);
}
