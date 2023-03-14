CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

GETLIB = make -C

SRCS = ./src/main.c ./src/control.c ./src/create_map.c  \
		./src/map_errors.c ./src/check_path.c \
		./src/get_images.c \
		./src/check_exit.c


OBJS = $(SRCS:.c=.o)

NAME = so_long

INCLUDE = -I./libft/headers -I./mlx

LIBFT = ./libft/libft.a ./mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME) $(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	make -C libft clean
	make -C mlx clean
	rm -rf ./src/*.o

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
