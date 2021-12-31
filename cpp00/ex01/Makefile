CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror
NAME			=	phonebook
INCLUDES		=	Contact.h
SRC				=	main.cpp Contact.cpp

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
