CC				=	clang++
NAME			=	ex00
SRCS			=	megaphone.cpp
OBJS_DIR		=	objs
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

OBJS			=	$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(dir $@) && $(CC) -c $(CFLAGS) -o $@ $< 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(OBJS_DIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re
