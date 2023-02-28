NAME		= a.out

CC			= gcc
CFLAGS		= -Wall -Wextra -Wextra

SRC			= main.c get_next_line.c get_next_line_utils.c
SRC_B		= main.c get_next_line_bonus.c get_next_line_utils_bonus.c

DEPS		= get_next_line.h
DEPS_B		= get_next_line_bonus.h

OBJ			= $(SRC:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(BFLAGS) $(DEPS) -c $(SRC)
	$(CC) $(OBJ) -o $(NAME)

bonus:
	$(CC) $(CFLAGS) $(BFLAGS) $(DEPS_B) -c $(SRC_B)
	$(CC) $(OBJ_B) -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
