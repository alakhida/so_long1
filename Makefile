# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 21:41:43 by alakhida          #+#    #+#              #
#    Updated: 2023/05/05 22:50:59 by alakhida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c errors_checker.c read_map.c check_pce.c tools.c check_path.c render.c movement.c move_handler.c

CC = cc

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJS}
	make -C ./libft
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
	make clean -C  ./libft
	rm -fr ${OBJS}

fclean: clean
	make fclean -C  ./libft
	rm -fr ${NAME}

re: fclean all