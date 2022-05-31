SRC			= ft_printf.c ft_printf_utils.c ft_print_ptr.c ft_print_unsign.c ft_print_hex.c
SRCS		= ${addprefix ${PRE}, ${SRC}}
OBJS		= ${SRCS:.c=.o}
PRE			= ./src/
HEAD		= ./include/
NAME		= libftprintf.a
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