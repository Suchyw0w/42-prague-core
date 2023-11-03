NAME = Inception
SRC = ./srcs/docker-compose.yaml

all: $(NAME)

$(NAME):
	docker compose -f $(SRC) up --build

clean:
	docker compose -f $(SRC) down

fclean: clean
	docker system prune -af

re: fclean $(NAME)
