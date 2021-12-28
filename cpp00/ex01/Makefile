CC				=	clang++
NAME			=	ex01
SRCS			=	$(wildcard *.cpp)
INCLUDES		=	$(wildcard *.h) $(wildcard *.hpp)
OBJS_DIR		=	objs
#CFLAGS			=	-Wall -Wextra #-Werror

OBJS			=	$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: %.cpp $(INCLUDES)
	mkdir -p $(dir $@) && $(CC) -c $(CFLAGS) -o $@ $< 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(OBJS_DIR) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
