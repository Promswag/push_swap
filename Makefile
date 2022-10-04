# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 14:35:47 by gbaumgar          #+#    #+#              #
#    Updated: 2022/09/28 13:22:41 by gbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

INCLUDE_DIR		= ./include/
SRC_DIR			= ./src/
OUT_DIR			= ./

SRC				= 	push_swap.c ps_push.c ps_swap.c ps_rotate.c ps_reverse.c
OBJS			= ${SRC:%.c=${OUT_DIR}%.o}

INCLUDE			= -I${INCLUDE_DIR}	
# LIB_FT			= -L libft -lft
# LIB_PRINTF		= -L ft_printf -lftprintf

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all: ${NAME}

${NAME}: ${OBJS}
#	make -C libft
#	make -C ft_printf
#	${CC} -o ${NAME} ${LIB_FT} ${LIB_PRINTF} ${INCLUDE} ${OBJS}
	${CC} -o ${NAME} ${INCLUDE} ${OBJS}

${OUT_DIR}%.o: ${SRC_DIR}%.c 
	${CC} ${CFLAGS} ${INCLUDE} $< -c -o $@

clean:
#	make clean -C libft
#	make clean -C ft_printf
	${RM} ${OBJS}

fclean:	clean
#	make fclean -C libft
#	make fclean -C ft_printf
	${RM} ${NAME}

re: fclean ${NAME}

bonus:	all

.PHONY:	all clean fclean re bonus
