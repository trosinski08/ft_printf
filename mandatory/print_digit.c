/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:00:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/11 16:19:40 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
    char	*str;
    long	n;
    int		i;
    char	*ref_base;

    ref_base = "0123456789abcdef";
    if (base < 2 || base > 16)
        return (NULL);
    n = value;
    i = 1;
    while ((n = n / base))
        i++;
    n = value;
    if (n < 0)
    {
        if (base == 10)
            i++;
        n = -n;
    }
    if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    str[i] = '\0';
    while (i--)
    {
        str[i] = ref_base[n % base];
        n = n / base;
    }
    if (value < 0 && base == 10)
        str[0] = '-';
    return (str);
}

static int	num_counter(int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static int	min_conv(long nbr, int base, t_format *f)
{
	int	c;
	int	i;
	int	h;

	i = 0;
	h = 1;
	if (nbr < 0 || (f ->plus == 1 && nbr >= 0))
		h++;
	while (nbr / base != 0)
	{
		h++;
		nbr /= base;
	}
	c = f->width - h;
	f->width = 0;
	f -> type = 0;
	while (i < c)
		i += write(1, " ", 1);
	return (i);
}

int	minus_nbr(long nbr, int base, t_format *f)
{
	int	i;

	i = 0;
	i += write (1, "-", 1);
	if (i == -1)
		return (-1);
	f -> plus = 0;
	f -> space = 0;
	return (print_digit(-nbr, base, f) + 1);
}

int	plus_conv(long nbr, int base, t_format *f)
{
	int	i;

	i = 0;
	i += write(1, "+", 1);
	if (i == -1)
		return (-1);
	f ->plus = 0;
	return (i + print_digit(nbr, base, f));
}

int	space_conv(long nbr, int base, t_format *f)
{
	int	i;

	i = 0;
	i += write(1, " ", 1);
	if (i == -1)
		return (-1);
	f ->space = 0;
	return (i + print_digit(nbr, base, f));
}

int	print_digit(long nbr, int base, t_format *f)
{
	int		i;
	int		c;
	char	*low_base;
	char 	*str;

	i = 0;
	low_base = "0123456789abcdef";
	str = ft_itoa_base(nbr, base);
	c = ft_strlen(str);
	// if (nbr < 0)
	// 	c--;
	if (f->width > i && f->minus == 0)
		i += (min_conv(nbr, base, f));
	if (f->prec > c)
	{
		c = f->prec - c;
		while (i < c && i < f->width)
			i += write(1, "0", 1);
	}
	if (nbr < 0)
		i += minus_nbr(nbr, base, f);
	else if ((f ->plus == 1 && nbr >= 0) && f->minus == 0)
		i += plus_conv(nbr, base, f);
	else if (f ->space == 1 && nbr >= 0 && f->minus == 0)
		i += space_conv(nbr, base, f);
	else if (nbr < base)
		i += ft_putchar(low_base[nbr]);
	else if (f ->space == 1 && nbr >= 0 && f->minus == 0)
        i += space_conv(nbr, base, f);
    else
		i += write(1, str, c);
	if (f->width > i && f->minus == 1)
		i += (min_conv(nbr, base, f));
	return (i);
}
