NAME		= a.out

CC			= gcc
CFLAGS		= -Wall -Wextra
BFLAGS		= -D BUFFER_SIZE=n

SRC			= main.c get_next_line.c get_next_line_utils.c
DEPS		= get_next_line.h
OBJ			= $(SRC:.c=.o)


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
