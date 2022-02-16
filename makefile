# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 06:35:11 by dmonteir          #+#    #+#              #
#    Updated: 2022/01/19 18:53:51 by dmonteir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -g3
INCLUDE = ./includes/pipex.h
LIBFT_PATH = Libft
LIBFT = $(LIBFT_PATH)/libft.a
FILES =			./main.c \

FILES_UTILS =

RM = rm -f
OBJS = $(FILES:.c=.o)
OBJS_UTILS = $(FILES_UTILS:.c=.o)

all:		$(NAME) $(INCLUDE)

$(NAME):	$(OBJS) $(OBJS_UTILS) $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_UTILS)

$(LIBFT):
			make -C $(LIBFT_PATH)

clean:
			$(RM) $(OBJS) $(OBJS_UTILS)
			make clean -C $(LIBFT_PATH)

fclean:
			$(RM) $(NAME) $(OBJS) $(OBJS_UTILS)
			make fclean -C $(LIBFT_PATH)

re:			fclean all