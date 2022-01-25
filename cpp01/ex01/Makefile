CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
NAME			=	ex01
INCLUDES		=	Zombie.hpp
SRCS			=	main.cpp Zombie.cpp ZombieHorde.cpp

OBJS_DIR		=	objs
OBJS			=	$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp $(INCLUDES)
	mkdir -p $(dir $@) && $(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME) $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean re
