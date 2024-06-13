/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:00:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/13 02:17:31 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	min_conv(long nbr, int base, t_format *f, int len)
{
	int		c;
	int		i;
	char	l;

	i = 0;
	if (f->space == 1 && nbr >= 0)
		len++;
	else if ((f->plus == 1 && f->prec < 0))
		len++;
	if (f->prec >= len)
	{
		len = f->prec;
		if (nbr < 0 || f->plus == 1 || f->space == 1)
			len++;
	}
	c = f ->width - len;
	f -> type = 0;
	while (i < c)
		i += write(1, " ", 1);
	return (i);
}

int	zero_conv(long nbr, int base, t_format *f, int len)
{
	int	c;
	int	i;

	i = 0;
	if (f->width > f->prec)
		c = f->width - f ->prec - len;
	else
	{
		if (nbr < 0)
			len--;
		c = f->prec - len;
	}
	f -> type = 0;
	while (i < c)
		i += write(1, "0", 1);
	return (i);
}

int	space_conv(long nbr, int base, t_format *f)
{
	int	i;

	i = 0;
	i += write(1, " ", 1);
	if (i == -1)
		return (-1);
	return (i);
}

static int	prec_min(int len, t_format *f, int *i)
{
	f->prec = -1;
	// printf("\nprec: %d\n", f->prec);
	// printf("\nwidth: %d\n", f->width);
	while (*i < f->width - f->plus - f->space)
		*i += write(1, " ", 1);
	// printf("\nprec: %d\n", f->prec);
	len = 0;
	return (len);
}

int	print_digit_prep(long nbr, int base, t_format *f)
{
	int		i;
	int		len;

	i = 0;
	len = ft_digit_len(nbr, base, f);
	if (f->prec == 0 && nbr == 0 && f->dot == 1)
		len = prec_min(len, f, &i);
	// printf("\nprec: %d\n", f->prec);
	if (f ->width > len && f->minus == 0 && f->zero == 0 && f->prec >= 0)
		i += min_conv(nbr, base, f, len);
	if (nbr < 0)
		i += minus_nbr(nbr, base, f);
	else if ((f ->plus == 1 && nbr >= 0) && f->minus == 0)
		i += plus_conv(nbr, base, f);
	else if (f ->space == 1 && nbr >= 0 && f->minus == 0)
		i += space_conv(nbr, base, f);
	if (f->zero == 1 && f->minus == 0 && f->prec >= 0)
		i += zero_conv(nbr, base, f, len);
	else if (f->minus == 0 && f->zero == 0 && f->prec > 0)
		i += prec_conv(nbr, base, f, len);
	if (f->prec >= 0)
		i += print_digit(nbr, base);
	if (f->width > i && f->minus == 1)
		i += (min_conv(nbr, base, f, len));
	return (i);
}

//kolejnosc dzialania
//1. sprawdzamy czy liczba jest ujemna, jezeli tak, write("-") i 
//zmieniamy liczbe na dodatnia
//2. sprawdzamy czy flag plus jest wlaczony, jezeli tak, write("+") 
//i zmieniamy liczbe na dodatnia
//3. sprawdzamy czy flag space jest wlaczony, jezeli tak, write(" ")
//i zmieniamy liczbe na dodatnia
//4. porownujemy width i prec ioraz z iloscia znakow do wyprintowania, 
//jezeli width jest wiekszy od prec,
// i nie ma flagi minus to printujemy roznice w spacjach
//5.roznice pomiedzy prec a dlugoscia liczby to ilosc zer 
//do dodania przed liczba
//6. jezeli liczba jest mniejsza od podstawy to printujemy liczbe
//7. jezeli liczba jest wieksza od podstawy to dzielimy liczbe 
//przez podstawe i wywolujemy funkcje rekurencyjnie
//8. jezeli liczba jest mniejsza od podstawy to printujemy liczbe
//9. jezeli width jest wiekszy od prec i jest wlaczona flaga minus 
//to printujemy roznice w spacjach
//10. zwracamy ilosc znakow wypisanych na ekran