NAME		= a.out

CC			= gcc -g
CFLAGS		= -Wall -Wextra
N			= 10
BFLAGS		= -D BUFFER_SIZE=$(N)

SRC			= main.c get_next_line.c get_next_line_utils.c
DEPS		= get_next_line.h
OBJ			= $(SRC:.c=.o)


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(BFLAGS) -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
