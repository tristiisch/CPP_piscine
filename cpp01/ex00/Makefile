CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror
NAME			=	ex00
INCLUDES		=	Zombie.hpp
SRCS			=	Zombie.cpp randomChump.cpp newZombie.cpp main.cpp

OBJS_DIR		=	objs
OBJS			=	$(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(INCLUDES)
	mkdir -p $(dir $@) && $(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
