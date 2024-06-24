/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:30 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 22:28:38 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @file digit_utils2.c
 * @brief Utility functions for handling digits in ft_printf
 */

/**
 * @brief Writes a minus sign to the standard output.
 *
 * This function writes a minus sign to the standard output and 
 * updates the format flags accordingly.
 *
 * @param f A pointer to the format structure.
 * @return The number of characters written, or -1 if an error occurred.
 */

/**
 * @brief Writes a plus sign to the standard output.
 *
 * This function writes a plus sign to the standard output.
 *
 * @return The number of characters written, or -1 if an error occurred.
 */

/**
 * @brief Writes a space character to the standard output.
 *
 * This function writes a space character to the standard output.
 *
 * @return The number of characters written, or -1 if an error occurred.
 */

/**
 * @brief Prints a digit in the specified base.
 *
 * This function prints a digit in the specified base to the standard output.
 *
 * @param nbr The digit to be printed.
 * @param base The base of the digit.
 * @return The number of characters written, or -1 if an error occurred.
 */

/**
 * @brief Calculates the length of a digit in the specified base.
 *
 * This function calculates the length of a digit in 
 * the specified base, taking into account the format flags.
 *
 * @param nbr The digit whose length is to be calculated.
 * @param base The base of the digit.
 * @param f A pointer to the format structure.
 * @return The length of the digit.
 */

int	minus_nbr(t_format *f)
{
	int	i;

	i = 0;
	i += write (1, "-", 1);
	if (i == -1)
		return (-1);
	f -> plus = 0;
	f -> space = 0;
	return (i);
}

int	plus_conv(void)
{
	int	i;

	i = 0;
	i += write(1, "+", 1);
	if (i == -1)
		return (-1);
	return (i);
}

int	space_conv(void)
{
	int	i;

	i = 0;
	i += write(1, " ", 1);
	if (i == -1)
		return (-1);
	return (i);
}

int	print_digit(long nbr, int base)
{
	int		i;
	char	*low_base;

	i = 0;
	low_base = "0123456789abcdef";
	if (nbr < 0)
		nbr *= -1;
	if (nbr < base)
		i += ft_putchar(low_base[nbr]);
	else
	{
		i += print_digit(nbr / base, base);
		if (i == -1)
			return (-1);
		i += print_digit(nbr % base, base);
	}
	return (i);
}

int	ft_digit_len(long nbr, int base, t_format *f)
{
	int		i;
	long	temp;

	i = 1;
	temp = nbr;
	if ((f->plus == 1 || f->space == 1) && nbr >= 0)
		i++;
	if (temp < 0)
	{
		temp *= -1;
		i++;
	}
	while (temp / base != 0)
	{
		i++;
		temp /= base;
	}
	return (i);
}
