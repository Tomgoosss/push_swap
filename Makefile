NAME    := a.out
CFLAGS = -Wunreachable-code -Ofast
GLFW_PATH := /opt/homebrew/lib
LIBFT := ./libft

HEADERS := -I./include -I /include -I$(LIBFT)
LIBS    := -ldl -lglfw -pthread -lm $(LIBFT)/libft.a 
SRCS    := push_swap.c checker.c swapf.c #$(shell find ./src -iname "*.c")
OBJS    := ${SRCS:.c=.o}

all:  libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -L$(GLFW_PATH)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft removemlx