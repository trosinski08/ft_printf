# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 01:54:44 by trosinsk          #+#    #+#              #
#    Updated: 2023/10/20 04:05:39 by trosinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMPILER
GCC = cc

#FLAGI KOMPILACJI
FLAGS = -Wall -Wextra -Werror

#NAZWA PROGRAMU
NAME = libftprintf.a

#LISTA PLIKOW ZRODLOWYCH
SRCS = ft_printf.c print_char.c print_digit.c print_hexa_up.c \
	print_digit.c print_pointer.c print_string.c print_hexa.c

BONUS = flag_spec.c

#PLIKI OBIEKTOWE
OBJS = $(SRCS:.c=.o)
OBONUS = $(BONUS:.c=.o)

#ALL RULE

all: $(NAME)

#RULE DO ZROBIENIA BIBLIOTEKI
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus:$(OBONUS)
	ar rcs $(NAME) $(OBONUS)

#RULE DO STWORZENIA PLIKOW OBIEKTOWYCH
%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS)

#RULE DO CZYSZCZENIA WSZYSTKIEGO
fclean: clean
	rm -f $(NAME)

#RULE DO REKOMIPLACJI
re: fclean all

.PHONY: all clean fclean re