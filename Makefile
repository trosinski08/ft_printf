# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 01:54:44 by trosinsk          #+#    #+#              #
#    Updated: 2024/06/24 20:32:14 by trosinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMPILER
CC = cc

#FLAGI KOMPILACJI
# FLAGS = -Wall -Wextra -Werror

#NAZWA PROGRAMU
NAME := libftprintf.a
INCLUDE := -I./include
LIBFT_INCLUDE := -I./include 
#LISTA PLIKOW ZRODLOWYCH
SRCS = ./mandatory/ft_printf.c  \
		./mandatory/print_digit.c \
		./mandatory/print_h_up.c \
		./mandatory/print_hexa.c \
		./mandatory/print_point.c \
		./mandatory/print_string.c \
		./mandatory/ft_putchar.c \
		./mandatory/print_char.c \
		./utils/digit_utils.c \
		./utils/digit_utils2.c \
		./utils/ft_strchr.c \
		./utils/ft_strlen.c

	
BNS = ./bonus/flag_spec.c \
	
#PLIKI OBIEKTOWE
OBJS = $(SRCS:.c=.o)
OBJSB = $(BNS:.c=.o)

#ALL RULE
all: $(NAME)

#RULE DO ZROBIENIA BIBLIOTEKI
$(NAME): $(OBJS) $(OBJSB)
	ar rcs $(NAME) $(OBJS) $(OBJSB) 
# ar rcs $(NAME) $(LIBFT)/libft.a
	
bonus: $(NAME) $(OBJSB)
	ar rcs $(NAME) $(OBJSB)
	# ar rcs $(NAME) $(LIBFT)/libft.a

#RULE DO STWORZENIA PLIKOW OBIEKTOWYCH
%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSB)
# $(MAKE) -C $(LIBFT) clean

#RULE DO CZYSZCZENIA WSZYSTKIEGO
fclean: clean
	rm -f $(NAME)
# $(MAKE) -C $(LIBFT) fclean
#RULE DO REKOMIPLACJI
re: fclean all

.PHONY: all clean fclean re bonus init