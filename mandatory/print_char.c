/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:56:48 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 22:17:18 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @file print_char.c
 * @brief Contains the implementation of the print_char function.
 */

/**
 * @brief Prints a character and handles formatting options.
 * 
 * This function prints a character and handles formatting 
 * options such as width and alignment.
 * 
 * @param c The character to be printed.
 * @param f A pointer to the t_format struct containing formatting options.
 * @return The number of characters printed.
 */

int	print_char(int c, t_format *f)
{
	int	i;
	int	d;

	i = 0;
	d = f ->width - 1;
	if (f ->minus == 1)
	{
		i += write(1, &c, 1);
		while (d-- > 0)
			i += write(1, " ", 1);
	}
	else
	{
		while (d-- > 0)
			i += write(1, " ", 1);
		i += write(1, &c, 1);
	}
	f ->width = 0;
	f ->type = 0;
	return (i);
}
