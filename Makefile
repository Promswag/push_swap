# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 14:35:47 by gbaumgar          #+#    #+#              #
#    Updated: 2022/10/05 19:19:28 by gbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

INCLUDE_DIR		= ./include/
SRC_DIR			= ./src/
OUT_DIR			= ./

SRC				= 	push_swap.c ps_op.c ps_misc.c ps_sort.c ps_args.c ps_error.c ps_utils.c
OBJS			= ${SRC:%.c=${OUT_DIR}%.o}

INCLUDE			= -I${INCLUDE_DIR}	
LIB_FT			= -L libft -lft
LIB_PRINTF		= -L ft_printf -lftprintf

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address
RM				= rm -f

all: ${NAME}

${NAME}: ${OBJS}
	make -C libft
	make -C ft_printf
	${CC} -o ${NAME} ${LIB_FT} ${LIB_PRINTF} ${INCLUDE} ${OBJS} ${CFLAGS}

${OUT_DIR}%.o: ${SRC_DIR}%.c 
	${CC} ${CFLAGS} ${INCLUDE} $< -c -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	${RM} ${OBJS}

fclean:	clean
	make fclean -C libft
	make fclean -C ft_printf
	${RM} ${NAME}

re: fclean ${NAME}

bonus:	all

.PHONY:	all clean fclean re bonus
