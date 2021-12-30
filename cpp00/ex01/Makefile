CC				=	clang++
NAME			=	ex01
SRCS_DIR		=	srcs
INCLUDES_DIR	=	includes
OBJS_DIR		=	objs
SRCS			=	$(wildcard $(SRCS_DIR)/*.cpp)
INCLUDES		=	$(wildcard $(INCLUDES_DIR)/*.h) $(wildcard $(INCLUDES_DIR)/*.hpp)
HEADER			=	$(addprefix -I, $(INCLUDES_DIR))
#CFLAGS			=	-Wall -Wextra #-Werror

OBJS			=	$(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(INCLUDES)
	mkdir -p $(dir $@) && $(CC) -c $(HEADER) $(CFLAGS) -o $@ $< 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HEADER) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(OBJS_DIR) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
