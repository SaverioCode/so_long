# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 15:02:31 by fgarzi-c          #+#    #+#              #
#    Updated: 2023/03/26 19:42:36 by fgarzi-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIB_L = libsl/libsl.a
LIB_G = libsl/get_next_line/get_next_line.a
LIB_M = -lmlx -framework OpenGl -framework AppKit
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(%.c)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@make -C libsl/get_next_line
	@make -C libsl/
	@$(CC) $(CFLAGS) $(LIB_M) $(OBJS) $(LIB_L) $(LIB_G) -o $(NAME)

%.c: %.o
	@$(CC) $(CFLAGS) -o $<

clean:
	@rm -f $(OBJS)
	@make clean -C libsl/get_next_line
	@make clean -C libsl

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libsl/get_next_line
	@make fclean -C libsl

re: fclean all

.PHONY: all clean fclean re
