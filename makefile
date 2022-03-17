# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 06:35:11 by dmonteir          #+#    #+#              #
#    Updated: 2022/03/17 12:36:59 by dmonteir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCLUDE = ./includes/push_swap.h
LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a
FILES =			./Sources/main.c \
				./Sources/validates.c \
				./Sources/order.c \
				./Sources/moviments/swap.c \
				./Sources/moviments/rotate.c \
				./Sources/moviments/reverse_rotate.c \
				./Sources/moviments/push.c \
				./Sources/radix_sort.c \
				./Sources/aux_order.c \
				./Sources/array_index.c \

LIBFT_BONUS_UTILS = ./Libft/ft_atoi.c \
				./Libft/ft_lstadd_front.c \
				./Libft/ft_lstadd_back.c \
				./Libft/ft_lstnew.c \
				./Libft/ft_lstlast.c \
				./Libft/ft_lstsize.c \

RM = rm -f
OBJS = $(FILES:.c=.o)
OBJS_UTILS = $(LIBFT_BONUS_UTILS:.c=.o)

all:		$(NAME) $(INCLUDE)

$(NAME):	$(OBJS) $(OBJS_UTILS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(OBJS_UTILS) $(LIBFT) -o $(NAME)

$(LIBFT):
			make -C $(LIBFT_PATH)

clean:
			$(RM) $(OBJS) $(OBJS_UTILS)
			make clean -C $(LIBFT_PATH)

fclean:
			$(RM) $(NAME) $(OBJS) $(OBJS_UTILS)
			make fclean -C $(LIBFT_PATH)

re:			fclean all