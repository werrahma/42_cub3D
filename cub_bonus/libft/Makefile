SRC = ft_atoi.c  ft_split.c   ft_strjoin.c  ft_strncmp.c  ft_substr.c \
		ft_isdigit.c  ft_strdup.c  ft_strlen.c 

NAME = libft.a
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME)	: $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
