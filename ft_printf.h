/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:22:01 by trosinsk          #+#    #+#             */
/*   Updated: 2023/10/20 03:47:58 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				print_char(int c);
unsigned long	print_hexa_up(unsigned long nbr, unsigned int base);
int				print_digit(long nbr, int base);
unsigned long	print_pointer(unsigned long nbr, unsigned int base);
unsigned long	print_hexa(unsigned long nbr, unsigned int base);
int				print_string(char *str);
int				flag_spec(int c);

#endif