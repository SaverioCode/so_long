# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:37:33 by fgarzi-c          #+#    #+#              #
#    Updated: 2023/03/22 16:47:02 by fgarzi-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsl.a
SRCS = ft_calloc.c ft_check_input.c ft_error.c ft_free.c \
	ft_free_on_error.c ft_strlen.c map_handler.c map_checker.c \
	
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(%.c)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rcs $(NAME) $(OBJS)

%.c: %.o
	@$(CC) $(CFLAGS) -o $<

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
