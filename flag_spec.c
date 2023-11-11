/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:32:30 by trosinsk          #+#    #+#             */
/*   Updated: 2023/11/11 17:20:46 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_spec(char fspec, t_format *flags)
{
	int	count;

	count = 0;
	if (fspec == '+')
	{
		flags->plus = 1;
		count ++;
	}
	else if (fspec == ' ')
	{
		flags ->space = 1;
		count ++;
	}
	else if (fspec == '#')
	{
		flags -> hash = 1;
		count ++;
	}
	return (count);
}
