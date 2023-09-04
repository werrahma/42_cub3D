NAME = cub3D
LIBFT = libft/libft.a

SRC = parsing/init_textures.c parsing/parsing.c parsing/read_file.c parsing/colors.c parsing/check_characters.c parsing/is_mapclosed.c\
	parsing/ft_strcmp.c parsing/path_checker.c parsing/make_rectangle_map.c main.c parsing/get_map.c parsing/get_next_line_utils.c parsing/get_next_line.c \
	parsing/ft_lstadd_back.c parsing/ft_lstlast.c parsing/ft_lstnew.c \
	raycasting/rotation.c raycasting/move_player.c \
	raycasting/raycasting_utils.c raycasting/vertical_check.c \
	raycasting/horizontal_check.c raycasting/player.c \
	raycasting/mlx_hook.c raycasting/mathch.c raycasting/minimap.c \
	raycasting/wall_checks.c raycasting/raycasting.c raycasting/mlx_.c
 
CC = cc
 CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
OBJ = $(SRC:.c=.o)

bonus : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ)  $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	rm -rf libft/*.o
	rm -rf $(OBJ)

fclean : clean
	rm -rf libft/*.a
	rm -rf $(NAME)

re : fclean bonus