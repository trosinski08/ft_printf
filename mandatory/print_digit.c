/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:00:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/12 03:03:09 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	min_conv(long nbr, int base, t_format *f, int len)
{
	int	c;
	int	i;

	i = 0;
	c = f ->width - len;
	f->width = 0;
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
	c = f ->width - len;
	f->width = 0;
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
	f ->space = 0;
	return (i);
}

int	print_digit_prep(long nbr, int base, t_format *f)
{
	int		i;
	int		len;

	i = 0;
	len = ft_digit_len(nbr, base, f);
	if (f->prec == 0 && nbr == 0 && f->dot == 1)
		f->prec = -1;
	if (f ->width > len && f->minus == 0 && f->zero == 0 && f->prec == 0)
		i += min_conv(nbr, base, f, len);
	if (nbr < 0)
		i += minus_nbr(nbr, base, f);
	if (f ->width > len && f->minus == 0 && f->zero == 1)
		i += zero_conv(nbr, base, f, len);
	else if (f->minus == 0 && f->zero == 0 && f->prec > 0)
		i += prec_conv(nbr, base, f, len);
	else if ((f ->plus == 1 && nbr >= 0) && f->minus == 0)
		i += plus_conv(nbr, base, f);
	else if (f ->space == 1 && nbr >= 0 && f->minus == 0)
		i += space_conv(nbr, base, f);
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