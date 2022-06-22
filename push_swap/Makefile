SRC			= stack_aux.c stack_op_rotate.c stack_op_switch.c stack_op_aux.c order_comb.c stack_op_push.c radix.c
SRCS		= ${addprefix ${PRE}, ${SRC}}
OBJS		= ${SRCS:.c=.o}
PRE			= ./src/
HEAD		= ./include/
NAME		= pushswap.a
AR			= ar src
RM			= rm -f
LIB			= ranlib
GCC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			@make -C libft
			@cp libft/libft.a $(NAME)
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM}  ${NAME}

re:			fclean all

.PHONY:		all clean fclean re