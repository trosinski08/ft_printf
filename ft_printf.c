/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:02:40 by trosinsk          #+#    #+#             */
/*   Updated: 2023/11/11 17:05:31 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formspecifier(char spec, va_list ap, t_format *flags)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(ap, int));
	else if (spec == 's')
		count += print_string(va_arg(ap, char *), flags);
	else if (spec == 'p')
		count += print_point(va_arg(ap, unsigned long), 16, flags);
	else if (spec == 'd' || (spec == 'i'))
		count += print_digit(va_arg(ap, int), 10, flags);
	else if (spec == 'u')
		count += print_digit(va_arg(ap, unsigned int), 10, flags);
	else if (spec == 'x')
		count += print_hexa(va_arg(ap, unsigned int), 16, flags);
	else if (spec == 'X')
		count += print_h_up(va_arg(ap, unsigned int), 16, flags);
	else if (spec == '%')
		count += write(1, &spec, 1);
	else
		count += write(1, &spec, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	t_format	my_format;

	va_start(ap, format);
	count = 0;
	my_format = (t_format){0, 0, 0, 0, 0, 0, 0, 0, 0, NULL};
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_strchr(FLAG_LIST, *(++format)))
			{
				flag_spec(*format, &my_format);
				++format;
			}
			count += ft_formspecifier(*format, ap, &my_format);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
