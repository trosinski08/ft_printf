/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:47:16 by tomek             #+#    #+#             */
/*   Updated: 2024/06/24 22:27:37 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @file digit_utils.c
 * @brief Utility functions for handling digits in ft_printf.
 */

/**
 * @brief Calculates the number of zeros needed for padding.
 * 
 * This function calculates the number of zeros needed for padding 
 * based on the precision and length of the number.
 * 
 * @param f The format specifier.
 * @param len The length of the number.
 * @param nbr The number.
 * @return The number of zeros needed for padding.
 */

/**
 * @brief Handles the hash conversion for 'x' and 'X' types.
 * 
 * This function handles the hash conversion for 'x' and 'X' 
 * types by writing '0x' or '0X' to the output.
 * 
 * @param f The format specifier.
 * @return The number of characters written to the output.
 */

/**
 * @brief Calculates the number of spaces needed for padding.
 * 
 * This function calculates the number of spaces needed for padding 
 * based on the width, precision, length of the number, and the character.
 * 
 * @param f The format specifier.
 * @param len The length of the number.
 * @param nbr The number.
 * @param c The character.
 * @return The number of spaces needed for padding.
 */

/**
 * @brief Checks and handles various flags for the number.
 * 
 * This function checks and handles various flags for the number, 
 * such as the hash flag, minus flag, plus flag, and space flag.
 * 
 * @param nbr The number.
 * @param f The format specifier.
 * @return The number of characters written to the output.
 */

/**
 * @brief Prints the specified number of zeros.
 * 
 * This function prints the specified number of zeros to the output.
 * 
 * @param zero_len The number of zeros to print.
 * @return The number of characters written to the output.
 */

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

int	hash_conv(t_format *f)
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

int	flag_checker(long nbr, t_format *f)
{
	int		i;

	i = 0;
	if (f->hash == 1 && nbr != 0)
		i += hash_conv(f);
	else if (nbr < 0)
		i += minus_nbr(f);
	else if (f ->plus == 1 && nbr >= 0)
		i += plus_conv();
	else if (f ->space == 1 && nbr >= 0)
		i += space_conv();
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
