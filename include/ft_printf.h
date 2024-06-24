/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:22:01 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 21:39:10 by trosinsk         ###   ########.fr       */
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
int				ft_putchar(char c);
int				print_char(int c, t_format *f);
unsigned long	print_h_up(unsigned long nbr, unsigned int base, t_format *f);
int				print_digit_prep(long nbr, int base, t_format *f);
unsigned long	print_point(unsigned long nbr, unsigned int base, t_format *f);
unsigned long	print_hexa(unsigned long nbr, unsigned int base, t_format *f);
int				print_string(char *str, t_format *f);
int				ft_digit_len(long nbr, int base, t_format *f);
int				print_digit(long nbr, int base);
int				non_minus_conv(long nbr, t_format *f, int len);
int				zero_printer(int zero_len);
int				hash_conv(t_format *f);
//./utils
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
int				flag_checker(long nbr, t_format *f);
int				minus_nbr(t_format *f);
int				space_conv(void);
int				plus_conv(void);
int				space_len_calc(t_format *f, int len, long nbr, char c);
int				zero_len_calc(t_format *f, int len, long nbr);
//./bonus
void			flag_spec(char fspec, t_format *flags);

#endif
