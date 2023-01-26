SRC = ft_print_numbers.c ft_print_strings.c ft_printf_utils.c ft_printf.c
INC = ft_printf.h
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
LIBFT = ./libft/libft.a

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}

${NAME}: ${OBJ}
	make bonus -C ./libft
	cp ./libft/libft.a ${NAME}
	${LIBC} ${NAME} ${OBJ}

all: ${NAME}

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}

fclean:	clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re: fclean all
