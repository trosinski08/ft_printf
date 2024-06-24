# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 01:54:44 by trosinsk          #+#    #+#              #
#    Updated: 2024/06/24 22:10:17 by trosinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMPILER
CC = cc

#COMPILATION FLAGS
FLAGS = -Wall -Wextra -Werror

#PROGRAM NAME
NAME := libftprintf.a
INCLUDE := -I./include
LIBFT_INCLUDE := -I./include

#LIST OF SOURC FILES
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
		./utils/ft_strlen.c \
# ./bonus/flag_spec.c

	
BNS = ./bonus/flag_spec.c \
	
#OBJECT FILES
OBJS = $(SRCS:.c=.o)
OBJSB = $(BNS:.c=.o)

#MAIN RULE
all: $(NAME)

#RULE TO COMPILE PROGRAM
$(NAME): $(OBJS) $(OBJSB)
	ar rcs $(NAME) $(OBJS) $(OBJSB)
	
bonus: $(NAME) $(OBJSB)
	ar rcs $(NAME) $(OBJSB)

#RULE TO CREATE OBJECT FILES
%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

#RULE TO CLEAN
clean:
	rm -f $(OBJS) $(OBJSB)

#RULE TO CLEAN ALL FILES
fclean: clean
	rm -f $(NAME)
	
#RULE TO REKOMPILATION
re: fclean all

.PHONY: all clean fclean re bonus init