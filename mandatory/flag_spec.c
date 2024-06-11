/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:32:30 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/11 14:07:09 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	flag_spec(char fspec, t_format *flags)
{
	// printf("\nf->prec: %d\n", flags->prec);
	// printf("f->width: %d\n", flags->width);
	// printf("f->minus: %d\n", flags->minus);
	// printf("f->dot: %d\n", flags->dot);
	// printf("f->type: %c\n", flags->type);
	// printf("f->zero: %d\n", flags->zero);
	// printf("\n\t%c\n", fspec);
	if (ft_strchr("0123456789", fspec) && flags -> zero == 0)
	{
		flags->type = flags->type * 10 + (fspec - '0');
		if (flags->dot == 0)
			flags->width = flags->type;
		else
			flags->prec = flags->type;
	}
	else if (fspec == '-')
		flags->minus = 1;
	else if (fspec == '.')
	{
		flags->dot = 1;
		flags->type = 0;
	}
	else if (fspec == '0' && flags ->type == 0)
		flags->zero = 1;
	else if (fspec == '+')
		flags->plus = 1;
	else if (fspec == ' ')
		flags->space = 1;
	else if (fspec == '#')
		flags->hash = 1;
}
