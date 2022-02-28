# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 06:35:11 by dmonteir          #+#    #+#              #
#    Updated: 2022/02/28 17:01:25 by dmonteir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -g3
INCLUDE = ./includes/push_swap.h
LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a
FILES =			./Sources/main.c \
				./Sources/validates.c \
				./Libft/ft_atoi.c \
				./Libft/ft_lstadd_back.c \
				./Libft/ft_lstnew.c \
				./Libft/ft_lstlast.c \


RM = rm -f
OBJS = $(FILES:.c=.o)

all:		$(NAME) $(INCLUDE)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			make -C $(LIBFT_PATH)

clean:
			$(RM) $(OBJS)
			make clean -C $(LIBFT_PATH)

fclean:
			$(RM) $(NAME) $(OBJS)
			make fclean -C $(LIBFT_PATH)

re:			fclean all