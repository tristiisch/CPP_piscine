CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror
NAME			=	ex00
INCLUDES		=	Zombie.hpp
SRC				=	Zombie.cpp

OBJ				=	$(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

%.o : %.cpp $(INCLUDES)
	$(CC) $(FLAGS) -c -o $@ $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
