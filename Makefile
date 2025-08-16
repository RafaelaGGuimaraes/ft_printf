# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 18:18:45 by rgomes-g          #+#    #+#              #
#    Updated: 2025/08/15 21:41:55 by rgomes-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =	ft_printf.c \
	convert_hex.c \
	print_char.c \
	convert_int.c \
	handle_specifier.c \
	convert_ptr.c \
	print_percent.c \
	print_str.c \
	parse_format.c \
	convert_unsigned.c \
	ft_strlen.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean $(NAME)

.PHONY: all fclean clean re