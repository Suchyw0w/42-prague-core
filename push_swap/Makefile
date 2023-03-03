SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
NAME = push_swap
MAIN = push_swap.c
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
LIBFT = ./libft/libft.a

SRCS := $(wildcard $(SRC_DIR)/*.c)
INCS := $(wildcard $(IDIR)/*.h)
OBJS = $(SRCS:.c=.o)

all: ${NAME}

${LIBFT}:
	make -C ./libft

${NAME}: ${OBJS} ${LIBFT}
	cc ${CFLAGS} $^ ${MAIN} -o $@

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJS}

fclean:	clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re: fclean all
