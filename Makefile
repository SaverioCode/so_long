# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 15:02:31 by fgarzi-c          #+#    #+#              #
#    Updated: 2023/03/20 15:21:24 by fgarzi-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIB = so_long.a
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(%.c)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rcs $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGl -framework AppKit $(OBJS) $(LIB) -o $(NAME)

%.c: %.o
	@$(CC) $(CFLAGS) -Imlx -o $<

clean:
	@rm -f $(OBJS) $(OBJSB)

fclean: clean
	@rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re