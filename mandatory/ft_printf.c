/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:02:40 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 22:16:18 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @brief Handles formatting and printing of diff. specifiers in ft_printf.
 *
 * This function takes a specifier character, a va_list containing
 * the arguments, and a t_format structure containing formatting flags. 
 * It determines the type of specifier and calls the appropriate print 
 * function to format and print the value.
 *
 * @param spec The specifier character.
 * @param ap The va_list containing the arguments.
 * @param flags The t_format structure containing formatting flags.
 * @return The number of characters printed.
 */
static int	ft_formspecifier(char spec, va_list ap, t_format *flags)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(ap, int), flags);
	else if (spec == 's')
		count += print_string(va_arg(ap, char *), flags);
	else if (spec == 'p')
		count += print_point(va_arg(ap, unsigned long), 16, flags);
	else if (spec == 'd' || (spec == 'i'))
		count += print_digit_prep(va_arg(ap, int), 10, flags);
	else if (spec == 'u')
		count += print_digit_prep(va_arg(ap, unsigned int), 10, flags);
	else if (spec == 'x')
		count += print_hexa(va_arg(ap, unsigned int), 16, flags);
	else if (spec == 'X')
		count += print_h_up(va_arg(ap, unsigned int), 16, flags);
	else if (spec == '%')
		count += print_char(spec, flags);
	else
		count += ft_putchar(spec);
	return (count);
}

/**
 * @brief Implements a formatted output function similar to printf.
 *
 * This function takes a format string and a variable number of arguments and
 * produces output according to the format specifier in the format string.
 *
 * @param format The format string that specifies how subsequent arguments are
 *               converted for output.
 * @param ...    Additional arguments to be formatted according to the format
 *               string.
 *
 * @return The number of characters written to the output stream.
 */

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	t_format	my_format;

	va_start(ap, format);
	count = 0;
	my_format = (t_format){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (*format)
	{
		if (*format == '%')
		{
			while (ft_strchr(FLAG_LIST, *(++format)))
			{
				flag_spec(*format, &my_format);
				if (ft_strchr(SPEC_LIST, *format))
					break ;
			}
			count += ft_formspecifier(*format, ap, &my_format);
			my_format = (t_format){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		}
		else
			count += ft_putchar(*format);
		++format;
	}
	return (va_end(ap), count);
}
