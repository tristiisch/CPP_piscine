CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror
NAME			=	phonebook
INCLUDES		=	Contact.hpp PhoneBook.hpp
SRC				=	main.cpp Contact.cpp PhoneBook.cpp

OBJS			=	$(SRC:%.cpp=%.o)

all: $(NAME)

%.o : %.cpp $(INCLUDES)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
