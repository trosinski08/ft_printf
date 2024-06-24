/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:22:01 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 10:50:16 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_LIST "-0.# +123456789"
# define SPEC_LIST "cspdiuxX%"

// # include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_format
{
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hash;
	int				dot;
	int				width;
	int				prec;
	char			type;
	struct s_format	*next;
}	t_format;

//./mandatory
int				ft_printf(const char *str, ...);
int				print_char(int c, t_format *f);
unsigned long	print_h_up(unsigned long nbr, unsigned int base, t_format *f);
int				print_digit_prep(long nbr, int base, t_format *f);
unsigned long	print_point(unsigned long nbr, unsigned int base, t_format *f);
unsigned long	print_hexa(unsigned long nbr, unsigned int base, t_format *f);
int				print_string(char *str, t_format *f);
void			flag_spec(char fspec, t_format *flags);
size_t			ft_strlen(const char *str);
int				ft_putchar(char c);
char			*ft_strchr(const char *s, int c);
int				ft_digit_len(long nbr, int base, t_format *f);
int				print_digit(long nbr, int base);
int				minus_nbr(long nbr, int base, t_format *f);
int				plus_conv(long nbr, int base, t_format *f);
int				non_minus_conv(long nbr, t_format *f, int len, int base);
// int				zero_conv(long nbr, int base, t_format *f, int len);
// int				prec_conv(long nbr, int base, t_format *f, int len);
int				space_conv(long nbr, int base, t_format *f);
int				zero_printer(int zero_len);
int				flag_checker(int nbr, int base, t_format *f);
int				space_len_clac(t_format *f, int len, int zero_len, int nbr);
int				zero_len_clac(t_format *f, int len, int nbr);
int				hash_conv(int nbr, t_format *f);

#endif
