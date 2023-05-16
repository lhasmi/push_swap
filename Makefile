# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 23:50:47 by lhasmi            #+#    #+#              #
#    Updated: 2023/05/16 10:29:01 by lhasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = parse_bis.c main.c parse_input_ll.c create_stacks_lst.c quick_sort.c \
		ft_free_lst.c stack_ops.c sorting_3to10.c sort_11to500.c


OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	@cd libft && make --silent
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME} -fsanitize=address -g3
	@echo "push_swap compiled"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@cd libft && make clean --silent
	@${RM} ${OBJS} --silent

fclean: clean
	@cd libft && make fclean --silent
	@${RM} ${NAME} --silent
	@echo "push_swap fcleaned"

re: fclean all

viz: ${NAME}
	@pip3 install push_swap_gui
	@cd libft && make --silent
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME} -fsanitize=address -g3
	@echo "push_swap compiled"
	@push_swap_gui

.PHONY: all clean fclean re viz
