/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:00:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 22:19:16 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @file print_digit.c
 * @brief Contains functions for printing digits with various formatting options.
 */

/**
 * @brief Handles the case when the precision is less than or equal to 0.
 *        Prints the necessary number of spaces and handles the plus sign.
 * @param len The length of the number to be printed.
 * @param f The format specifier.
 * @param i The current count of characters written.
 * @return The updated count of characters written.
 */
// static int	prec_min(int len, t_format *f, int i);

/**
 * @brief Handles the case when the conversion type is not specified.
 *        Prints the necessary number of spaces.
 * @param f The format specifier.
 * @param i The current count of characters written.
 * @return The updated count of characters written.
 */
// static int	min_conv(t_format *f, int i);

/**
 * @brief Handles the case when the minus flag is not set.
 *        Prints the necessary number of zeros, spaces, and the number itself.
 * @param nbr The number to be printed.
 * @param f The format specifier.
 * @param len The length of the number to be printed.
 * @return The count of characters written.
 */
// int	non_minus_conv(long nbr, t_format *f, int len);

/**
 * @brief Prepares and prints the digit with the specified base 
 * and formatting options.
 * @param nbr The number to be printed.
 * @param base The base of the number.
 * @param f The format specifier.
 * @return The count of characters written.
 */
// int	print_digit_prep(long nbr, int base, t_format *f);

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

static int	min_conv(t_format *f, int i)
{
	f -> type = 0;
	while (i < f->width)
		i += write(1, " ", 1);
	return (i);
}

int	non_minus_conv(long nbr, t_format *f, int len)
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
	zero_len = zero_len_calc(f, len, nbr);
	space_len = space_len_calc(f, len, nbr, c);
	if (c == '0')
		i += flag_checker(nbr, f);
	while (i < space_len)
		i += write(1, &c, 1);
	if (c != '0')
		i += flag_checker(nbr, f);
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
	i += non_minus_conv(nbr, f, len);
	if (f->prec >= 0)
		i += print_digit(nbr, base);
	if (f->minus == 1)
		i = min_conv(f, i);
	return (i);
}
