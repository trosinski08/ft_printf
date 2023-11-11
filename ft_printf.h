/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:22:01 by trosinsk          #+#    #+#             */
/*   Updated: 2023/11/10 15:30:51 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef FLAG_LIST
#  define FLAG_LIST "# +"

# endif

# ifndef SPEC_LIST
#  define SPEC_LIST "cspdiuxX%"

# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_format
{
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hash;
	int				dot;
	int				width;
	int				pcs;
	char			type;
	struct s_format	*next;
}	t_format;

int				ft_printf(const char *str, ...);
int				print_char(int c);
unsigned long	print_h_up(unsigned long nbr, unsigned int base, t_format *f);
int				print_digit(long nbr, int base, t_format *f);
unsigned long	print_point(unsigned long nbr, unsigned int base, t_format *f);
unsigned long	print_hexa(unsigned long nbr, unsigned int base, t_format *f);
int				print_string(char *str, t_format *f);
int				flag_spec(char fspec, t_format *flags);
char			*ft_strchr(const char *s, int c);

#endif