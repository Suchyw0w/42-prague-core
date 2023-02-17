SRC = ft_printf.c ft_printf_utils.c ft_print_strings.c ft_print_numbers.c
SRC_BONUS = ft_printf_bonus.c ft_printf_utils_bonus.c ft_print_strings_bonus.c ft_print_numbers_bonus.c ft_print_hexadecimals_bonus.c
INC = ft_printf.h
INC_BONUS = ft_printf_bonus.h
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = libftprintf.a
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
LIBFT = ./libft/libft.a

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}

${NAME}: ${OBJ}
	make -C ./libft
	cp ./libft/libft.a ${NAME}
	${LIBC} ${NAME} ${OBJ}

all: ${NAME}

bonus:
	make -C ./libft
	cp ./libft/libft.a ${NAME}
	cc -fPIE ${CFLAGS} -c ${SRC_BONUS} -I ${INC_BONUS}
	${LIBC} ${NAME} ${OBJ_BONUS}

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}

fclean:	clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re: fclean all
