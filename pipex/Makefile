# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 09:14:26 by jhurtado          #+#    #+#              #
#    Updated: 2022/06/27 16:31:23 by jhurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c pipex_aux.c
SRCS		= ${addprefix ${PRE}, ${SRC}}
OBJS		= ${SRCS:.c=.o}
PRE			= ./srcs/
HEAD		= ./includes/
NAME		= pipexlibrary.a
AR			= ar src
RM			= rm -f
LIB			= ranlib
GCC			= gcc
CFLAGS		= -Wall -Wextra -Werror
P_NAME		=	pipex

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			@make -C libft
			@cp libft/libft.a $(NAME)
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}
			${GCC} -o ${P_NAME} ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM}  ${NAME}

re:			fclean all

.PHONY:		all clean fclean re