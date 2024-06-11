/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:51:09 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/11 00:16:01 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

//first are printed spaces, then amount of chars declared by precision, summed to width
int	dot_menager(t_format *f, char *str, int len)
{
	int	i;
	int j;
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
		f ->type = 0;
	}
	return (i);
}

int	minus_menager(int d, t_format *f, char *str, int len)
{
	int	i;

	i = 0;
	if (len > d)
	{
		while (str[i] != '\0')
		{
			i += ft_putchar((int)str[i]);
			if (i == -1)
				return (-1);
			f ->type = 0;
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

int	d_menager(int d, t_format *f, char *str, int len)
{
	int	i;

	i = 0;
	if (len >= d)
	{
		while (str[i] != '\0')
		{
			i += ft_putchar((int)str[i]);
			if (i == -1)
				return (-1);
			f ->type = 0;
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

int	str_menager(char *str, int len, int i)
{
	if (str == NULL)
		i += write(1, "(null)", 6);
	else
		i += write(1, str, len);
	return (i);
}

int	print_string(char *str, t_format *f)
{
	int	i;
	int	d;
	int	len;

	i = 0;
	d = f->width;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (f->dot == 1 && len > f->prec)
		len = f->prec;
	if (!str && f->space == 1)
		return (-1);
	else if (f->minus && d > 0)
		i = minus_menager(d, f, str, len);
	else if (f->prec)
		i = dot_menager(f, str, len);
	else if (d > 0)
		i = d_menager(d, f, str, len);
	else
		i += str_menager(str, len, i);
	f ->width = 0;
	f ->type = 0;
	return (i);
}

	// printf("\nprec: %d\n", f->prec);
	// printf("width: %d\n", f->width);