/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:51:09 by trosinsk          #+#    #+#             */
/*   Updated: 2023/11/11 17:17:15 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str, t_format *f)
{
	int	i;

	i = 0;
	if (!str && f->space == 1)
		return (-1);
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		i += print_char((int)str[i]);
		if (i == -1)
			return (-1);
	}
	return (i);
}
