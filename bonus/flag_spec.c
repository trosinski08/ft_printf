/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:32:30 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 22:13:16 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
/**
 * @brief Sets the flag specifications based on the given character.
 * 
 * This function sets the flag specifications in the t_format structure based
 * on the given character. The flag specifications include zero padding,
 * width, precision, minus, dot, plus, space, and hash.
 * 
 * @param fspec The character representing the flag specification.
 * @param flags A pointer to the t_format structure 
 * to store the flag specifications.
 */

void	flag_spec(char fspec, t_format *flags)
{
	if (fspec == '0' && !flags->type && !flags->minus && !flags->dot)
		flags->zero = 1;
	else if (ft_strchr("0123456789", fspec))
	{
		flags->type = flags->type * 10 + (fspec - '0');
		if (flags->dot == 0)
			flags->width = flags->width * 10 + (fspec - '0');
		else
			flags->prec = flags->prec * 10 + (fspec - '0');
	}
	if (fspec == '-')
		flags->minus = 1;
	else if (fspec == '.')
	{
		flags->dot = 1;
		flags->type = 0;
	}
	else if (fspec == '+')
		flags->plus = 1;
	else if (fspec == ' ')
		flags->space = 1;
	else if (fspec == '#')
		flags->hash = 1;
}
