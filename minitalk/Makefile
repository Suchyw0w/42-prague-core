CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT = client
SERVER = server
NAME =
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
LIBFT = ./libft/libft.a

all: ${CLIENT} ${SERVER}

${NAME}: all

${CLIENT}:
	make -C ./libft
	cc -g ${CFLAGS} ${CLIENT_SRC} ${LIBFT} -o ${CLIENT}

${SERVER}:
	make -C ./libft
	cc -g ${CFLAGS} ${SERVER_SRC} ${LIBFT} -o ${SERVER}

bonus:	${CLIENT} ${SERVER}

clean:
	${MAKE} clean -C ./libft
	${RM} ${CLIENT} ${SERVER}

fclean:	clean
	${MAKE} fclean -C ./libft
	${RM} ${CLIENT} ${SERVER}

re: fclean all
