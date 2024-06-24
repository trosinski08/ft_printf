/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:51:09 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 22:26:26 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @brief Handles the case when the precision is specified with a dot.
 * 
 * @param f The format structure.
 * @param str The string to be printed.
 * @param len The length of the string.
 * @return The number of characters printed.
 */
int	dot_menager(t_format *f, char *str, int len)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	d = 0;
	j = 0;
	if (str[0] == '\0')
		len = 0;
	if (f->prec > 0 && f->prec < len)
		len = f->prec;
	if (f->width > len)
		d = f->width - len;
	while (i < d)
		i += write(1, " ", 1);
	while (j < len)
	{
		i += ft_putchar(str[j]);
		if (i == -1)
			return (-1);
		j++;
		f->type = 0;
	}
	return (i);
}

/**
 * @brief Handles the case when the minus flag is specified.
 * 
 * @param f The format structure.
 * @param str The string to be printed.
 * @param len The length of the string.
 * @return The number of characters printed.
 */
int	minus_menager(t_format *f, char *str, int len)
{
	int	i;
	int	d;

	i = 0;
	d = f->width;
	if (f->prec > 0 && f->prec < len)
		len = f->prec;
	if (len > d)
	{
		while (str[i] != '\0' && i < len)
		{
			i += ft_putchar((int)str[i]);
			if (i == -1)
				return (-1);
			f->type = 0;
		}
	}
	else
	{
		i += write(1, str, len);
		while (i < d)
			i += write(1, " ", 1);
	}
	return (i);
}

/**
 * @brief Handles the case when the width is specified.
 * 
 * @param f The format structure.
 * @param str The string to be printed.
 * @param len The length of the string.
 * @return The number of characters printed.
 */
int	d_menager(t_format *f, char *str, int len)
{
	int	i;
	int	d;

	i = 0;
	d = f->width;
	if (f->prec > 0 && f->prec < len)
		len = f->prec;
	if (len >= d)
	{
		while (str[i] != '\0')
		{
			i += ft_putchar((int)str[i]);
			if (i == -1)
				return (-1);
			f->type = 0;
		}
	}
	else
	{
		while (i < d - len)
			i += write(1, " ", 1);
		i += write(1, str, len);
	}
	return (i);
}

/**
 * @brief Handles the case when the string is printed without any formatting.
 * 
 * @param str The string to be printed.
 * @param len The length of the string.
 * @param i The current count of characters printed.
 * @return The number of characters printed.
 */
int	str_menager(char *str, int len, int i)
{
	if (str == NULL)
		i += write(1, "(null)", 6);
	else
		i += write(1, str, len);
	return (i);
}

/**
 * @brief Prints a string according to the specified format.
 * 
 * @param str The string to be printed.
 * @param f The format structure.
 * @return The number of characters printed.
 */
int	print_string(char *str, t_format *f)
{
	int	i;
	int	len;

	i = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (f->dot == 1 && len > f->prec)
		len = f->prec;
	if (!str && f->space == 1)
		return (-1);
	else if (f->minus && f->width > 0)
		i = minus_menager(f, str, len);
	else if (f->prec)
		i = dot_menager(f, str, len);
	else if (f->width > 0)
		i = d_menager(f, str, len);
	else
		i += str_menager(str, len, i);
	f->width = 0;
	f->type = 0;
	return (i);
}
