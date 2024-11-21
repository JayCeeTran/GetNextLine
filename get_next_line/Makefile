NAME = libgetnext.a
SRCS = get_next_line_utils.c \
	get_next_line.c \

OBJ = $(SRCS:.c=.o)
RM = rm -f
EXE = a.out
CC = cc
CFLAGS = -Wall -Wextra -Wextra -D BUFFER_SIZE=42

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

run: $(EXE)
	./a.out

$(EXE): $(NAME)
	$(CC) $(CFLAGS) -L. -lgetnext -o $(EXE)

clean: 
	$(RM) $(OBJ)

fclean:
	$(RM) $(EXE) $(NAME)

re: fclean all
