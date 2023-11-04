NAME	= Cub3D

CC		= gcc -fsanitize=address
GRAPHICS= -Imlx -lmlx -framework OpenGL -framework AppKit

SRC		= haah1.c split.c player.c ft_mlx.c dda.c gridWall.c raycasting.c hori_ray.c ver_ray.c
OBJ		= $(SRC:.c=.o)
f : $(OBJ)
	$(CC) $(GRAPHICS) $(OBJ) -o $(NAME)

a : f clean

clean :
	@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)
