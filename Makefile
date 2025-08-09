# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 18:18:45 by rgomes-g          #+#    #+#              #
#    Updated: 2025/08/09 14:29:17 by rgomes-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program or library

NAME = libftprintf.a

# Flags and Compilers

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Archives .c

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

# Archives .o

OBJS = $(SRCS:.c=.o)

# Main

all: $(NAME)

# Main rule

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# .c -> .o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clear

clean:
	rm -f $(OBJS)

# Full clean

fclean: clean
	rm -f $(NAME) 

# restart

re: fclean $(NAME)

.PHONY: all fclean clean re