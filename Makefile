# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 18:41:38 by jdomingu          #+#    #+#              #
#    Updated: 2022/12/26 18:55:36 by jdomingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	push_swap
NAME_BONUS = checker
SRCS = 	src/push_swap.c src/calculate_max_length.c src/control_status.c src/parse_data.c \
	src/sort_data.c src/operations.c src/operations_both_stacks.c src/resolve.c \
	src/heuristics.c src/push_back.c src/repositon_stack_a.c

GNL_SRCS = gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c

BSRCS = bns/checker_bonus.c bns/calculate_max_length_bonus.c bns/control_status_bonus.c \
	bns/parse_data_bonus.c bns/operations_bonus.c bns/operations_both_stacks_bonus.c \
	bns/execute_moves.c $(GNL_SRCS)
OBJS = $(SRCS:.c=.o)
BOJS = $(BRCS:.c=.o)
LIBFT = libft
LIBFT_LIB = libft/libft.a
GNL_DIR = -I gnl
CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUFFER_FLAG = -D BUFFER_SIZE=42
RM = rm -f

all:			$(NAME)	

$(NAME):		$(LIBFT_LIB)
				$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):	
				@make bonus -C $(LIBFT)

clean:
				$(RM) $(OBJS)
				$(RM) $(BOBJS)
				@make clean -C $(LIBFT)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(NAME_BONUS)
				$(RM) $(LIBFT_LIB)

re:			fclean all

re2:			fclean all bonus

bonus:			$(NAME_BONUS)

$(NAME_BONUS):		$(LIBFT_LIB)
				$(CC) $(CFLAGS) $(BUFFER_FLAG) $(BSRCS) $(LIBFT_LIB) $(GNL_DIR) -o $(NAME_BONUS)
			
.PHONY:			all clean fclean re bonus re2
