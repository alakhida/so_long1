# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 15:25:51 by alakhida          #+#    #+#              #
#    Updated: 2022/11/12 17:24:30 by alakhida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS=ft_putstr.c ft_putchar.c ft_printf.c \
	ft_hexadecimal.c ft_hex.c ft_putnbr.c \
	ft_putunbr.c \

OBJECTS= ${SRCS:.c=.o}

HEADERS= ft_printf.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

%.o: %.c
	$(CC) -c $<  $(FLAGS) 

$(NAME):$(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

clean:
	rm -rf *.o

fclean:clean
	rm -rf $(NAME)

re: fclean all
