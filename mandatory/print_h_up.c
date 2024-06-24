/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_h_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:01:21 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 22:20:40 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @file print_h_up.c
 * @brief Contains functions for printing unsigned long numbers in 
 * uppercase hexadecimal format.
 */

/**
 * @brief Helper function for printing non-minus conversions.
 * 
 * This function is used to print the non-minus conversions of 
 * unsigned long numbers in uppercase hexadecimal format.
 * 
 * @param nbr The number to be printed.
 * @param f The format specifier.
 * @param len The length of the number.
 * @return The number of characters printed.
 */
// static int min_conv(t_format *f, int i);

/**
 * @brief Prints the hexadecimal representation of an unsigned long number 
 * in uppercase.
 * This function recursively prints the hexadecimal representation 
 * of an unsigned long number in uppercase.
 * 
 * @param nbr The number to be printed.
 * @param base The base of the number system (usually 16 for hexadecimal).
 * @param f The format specifier.
 * @return The number of characters printed.
 */
// unsigned long print_hb(unsigned long nbr, unsigned int base, t_format *f);

/**
 * @brief Prints an unsigned long number in uppercase hexadecimal format.
 * 
 * This function prints an unsigned long number in uppercase hexadecimal format.
 * 
 * @param nbr The number to be printed.
 * @param base The base of the number system (usually 16 for hexadecimal).
 * @param f The format specifier.
 * @return The number of characters printed.
 */
// unsigned long print_h_up(unsigned long nbr, unsigned int base, t_format *f);

static int	min_conv(t_format *f, int i)
{
	f -> type = 0;
	while (i < f->width)
		i += write(1, " ", 1);
	return (i);
}

unsigned long	print_hb(unsigned long nbr, unsigned int base, t_format *f)
{
	int		i;
	char	*low_base;

	i = 0;
	low_base = "0123456789ABCDEF";
	if (nbr < base)
		i += ft_putchar(low_base[nbr]);
	else
	{
		i += print_hb(nbr / base, base, f);
		if (i == -1)
			return (-1);
		i += print_hb(nbr % base, base, f);
	}
	return (i);
}

unsigned long	print_h_up(unsigned long nbr, unsigned int base, t_format *f)
{
	int		i;
	int		len;

	i = 0;
	len = ft_digit_len(nbr, base, f);
	f->type = 'X';
	i += non_minus_conv(nbr, f, len);
	if (f->prec >= 0)
		i += print_hb(nbr, base, f);
	if (f->minus == 1)
		i = (min_conv(f, i));
	return (i);
}
