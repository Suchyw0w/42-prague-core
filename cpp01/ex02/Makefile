SRCS			= main.cpp
OBJS			= $(SRCS:.cpp=.o)
CPP				= c++
RM				= rm -f
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME			= Brain
PINK	= "\033[0;35m"
RESET	= "\033[0m"

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
				@echo $(PINK)• ... COMPILED ...	•$(RESET)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)
				@echo $(PINK)• ... CLEANED ...	•$(RESET)

re:				fclean $(NAME)

.PHONY:			all clean fclean re