# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 18:32:53 by mahoang           #+#    #+#              #
#    Updated: 2020/01/27 05:51:07 by mahoang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g3

HEADER = fr_printf.h

SRC     = ft_printf.c \
ft_flags.c \
ft_printf_c.c \
ft_printf_s.c \
ft_printf_du.c \
ft_printf_p.c \
ft_printf_x.c \
ft_printf_misc.c \
ft_printf_misc2.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	@echo "\033[0;32mGenerating obj..."
	$(CC) -c $< $(CFLAGS)
	@echo "\033[0m"

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean

