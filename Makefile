# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 01:54:44 by trosinsk          #+#    #+#              #
#    Updated: 2024/06/09 23:28:30 by trosinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMPILER
CC = cc

#FLAGI KOMPILACJI
FLAGS = -Wall -Wextra -Werror

#NAZWA PROGRAMU
NAME := libftprintf.a
LIBFT := ./libft
INCLUDE := -I./include
LIBFT_INCLUDE := -I./libft/include
LIBFT_LIB := -L $(LIBFT) -libft.a
#LISTA PLIKOW ZRODLOWYCH
SRCS = ./mandatory/ft_printf.c  \
		./mandatory/print_digit.c \
		./mandatory/print_h_up.c \
		./mandatory/print_hexa.c \
		./mandatory/print_point.c \
		./mandatory/print_string.c \
		ft_putchar.c ft_strchr.c ft_strlen.c 
		# ./mandatory/flag_spec.c \
		# ./mandatory/print_char.c \
	
BNS = ./mandatory/flag_spec.c \
		./mandatory/print_char.c
	
#PLIKI OBIEKTOWE
OBJS = $(SRCS:.c=.o)
OBJSB = $(BNS:.c=.o)

#ALL RULE

all: $(NAME)

#RULE DO ZROBIENIA BIBLIOTEKI
$(NAME): $(OBJS) $(OBJSB)
	make -C $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(OBJSB) ./libft/libft.a
	
bonus: $(NAME) $(OBJSB)
	ar rcs $(NAME) $(OBJSB)

#RULE DO STWORZENIA PLIKOW OBIEKTOWYCH
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJSB)
	make -C $(LIBFT) clean

#RULE DO CZYSZCZENIA WSZYSTKIEGO
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

#RULE DO REKOMIPLACJI
re: fclean all

.PHONY: all clean fclean re