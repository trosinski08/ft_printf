/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:02:40 by trosinsk          #+#    #+#             */
/*   Updated: 2023/10/20 03:17:03 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formspecifier(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == '-' || spec == '0' || spec == '#' || spec == ' '
		|| spec == '+' || spec == '.')
		count += flag_spec(va_arg(ap, int));
	else if (spec == 'c')
		count += print_char(va_arg(ap, int));
	else if (spec == 's')
		count += print_string(va_arg(ap, char *));
	else if (spec == 'p')
		count += print_pointer(va_arg(ap, unsigned long), 16);
	else if (spec == 'd' || (spec == 'i'))
		count += print_digit(va_arg(ap, int), 10);
	else if (spec == 'u')
		count += print_digit(va_arg(ap, unsigned int), 10);
	else if (spec == 'x')
		count += print_hexa(va_arg(ap, unsigned int), 16);
	else if (spec == 'X')
		count += print_hexa_up(va_arg(ap, unsigned int), 16);
	else if (spec == '%')
		count += write(1, &spec, 1);
	else
		count += write(1, &spec, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (count == -1)
			return (-1);
		if (*format == '%')
			count += ft_formspecifier(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// #include <unistd.h>
// #include <stdio.h>

// int main()
// {
// 	ft_printf("%p", "");
// 	printf("%p", "");

// 	return 0;
// }
