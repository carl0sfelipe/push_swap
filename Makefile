NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
AR = ar rcs
LIBFTPRINTF = printf/libftprintf.a
LIBFT = printf/libft/libft.a
LIBFT_PATH = printf/libft/

# Source files for push_swap
SRC = has_duplicate.c has_only_int.c is_out_of_bounds.c main.c push.c radix.c rev_rotate.c rotate.c sort.c stack.c swap.c utils.c
OBJS = $(SRC:.c=.o)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all
	cp $(LIBFT) printf/

$(LIBFTPRINTF): $(LIBFT)
	$(MAKE) -C printf/ all

# Build rules
all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	$(MAKE) -C printf/ clean
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTPRINTF)
	rm -f $(LIBFT)
	rm -f printf/libft.a

re: fclean all

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
