NAME    := push_swap
CFLAGS =  -Wall -Wextra -Werror -Wunreachable-code -Ofast -g #-fsanitize=address
LIBFT := ./libft
CC = cc

HEADERS := -I./include -I /include -I$(LIBFT)
LIBS    := -ldl -pthread -lm $(LIBFT)/libft.a 
SRCS    := src/push_swap.c src/checker.c src/swapf.c src/sort_stacks.c src/sort_all_nodes.c src/push_to_a.c src/push_to_a_2.c \
			src/sort_5.c src/sort_all_nodes_2.c src/rotate.c
OBJS    := ${SRCS:.c=.o}

all:  libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft