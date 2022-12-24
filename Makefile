# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 18:41:38 by jdomingu          #+#    #+#              #
#    Updated: 2022/09/28 18:59:15 by jdomingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = src/related_to_chunks.c src/push_swap.c src/utils_ps.c src/operations.c src/sorting_algorihms.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft
LIBFT_LIB = libft/libft.a
INCLUDE = -I include
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

all:			$(NAME)	

$(NAME):		$(LIBFT_LIB)
				$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) $(INCLUDE) -o $(NAME)

$(LIBFT_LIB):	
				@make -C $(LIBFT)

clean:
				$(RM) $(OBJS)
				@make clean -C $(LIBFT)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(LIBFT_LIB)

re:				fclean all

.PHONY:			all clean fclean re
