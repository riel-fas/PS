NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRCS = push_swap.c stack_utils_1.c stack_utils_2.c string_pars.c algo_func_1.c algo_func_2.c algo_func_3.c operations_1.c operations_2.c

# LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h


all: $(NAME)

# $(LIBFT)
# $(LIBFT)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


# $(LIBFT):
# make -C libft
#

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJS)
# make clean -C libft


fclean: clean
	rm -rf $(NAME)
# make fclean -C libft


re: fclean all

.PHONY: all clean fclean re
