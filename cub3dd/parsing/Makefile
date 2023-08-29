SRC = get_map.c

NAME = cub3d
LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

CC = cc

all: $(NAME)
$(NAME): $(OBJ)
	cd libft && &(MAKE)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		rm -rf $(OBJ)
		rm -rf libft/*.o