# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:03:04 by cmateos-          #+#    #+#              #
#    Updated: 2023/05/21 20:41:35 by cmateos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
MAIN = mainprintf.c
MAIN_OBJ = $(MAIN:.c=.o)
SRC = ft_printf.c \
	ft_putchr_pf.c \
	ft_putstr_pf.c \
	ft_putnbr_pf.c \
	ft_putptr_pf.c \
	ft_puthex.c \
	ft_putun.c
OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h
all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

normi:
	norminette

main: $(NAME) $(MAIN_OBJ)
	gcc $(NAME) $(MAIN_OBJ) -o printf

run_main: $(NAME) $(MAIN_OBJ)
	gcc $(NAME) $(MAIN_OBJ) -o printf && ./printf

re: fclean all

.PHONY: all, clean, fclean, re, normi
