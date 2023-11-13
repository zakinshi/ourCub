NAME		= Cub3D

ADDRESS		= -fsanitize=address
CC			= cc $(ADDRESS)
FLAG		= -Wall -Wextra -Werror -Imlx
GRAPHICS	= -lmlx -framework OpenGL -framework AppKit

PATH_SRC	= ./source/
PATH_OBJ	= ./build/

#**
# **	--> raycasting
#**
PATH_RAY	= ./raycasting/
FILE_RAY_C	= raycasting.c	hori_ray.c	ver_ray.c	tools.c

PATH_RAY_B	= $(PATH_OBJ)raycasting/
FILE_RAY_B	= $(FILE_RAY_C:.c=.o)
RAY_OBJ		= $(addprefix $(PATH_RAY_B), $(FILE_RAY_B))
#	----------------------------------

#**
# **	--> MINMAP
#**
PATH_MNMP	= ./minimap/
FILE_MNMP_C	= tools.c	gridWall.c	player.c

PATH_MNMP_B	= $(PATH_OBJ)minimap/
FILE_MNMP_B	= $(FILE_MNMP_C:.c=.o)
MNMP_OBJ	= $(addprefix $(PATH_MNMP_B), $(FILE_MNMP_B))
#	----------------------------------

#**
# **	--> PROJECTION
#**
PATH_PROJ	= ./projection/
FILE_PROJ_C	= dda.c		3dwall.c

PATH_PROJ_B	= $(PATH_OBJ)projection/
FILE_PROJ_B	= $(FILE_PROJ_C:.c=.o)
PROJ_OBJ	= $(addprefix $(PATH_PROJ_B), $(FILE_PROJ_B))
#	----------------------------------

#**
# **	--> SOURCE
#**
FILE_SRC_C	= main.c	split.c	ft_mlx.c	draw.c

PATH_SRC_B	= $(PATH_OBJ)
FILE_SRC_B	= $(FILE_SRC_C:.c=.o)
SRC_OBJ		= $(addprefix $(PATH_SRC_B), $(FILE_SRC_B))
#	----------------------------------

# ** Global Vars
HEADERS		= ./source/minimap.h
ALLOBJ		= $(OBJ) $(RAY_OBJ) $(MNMP_OBJ) $(PROJ_OBJ) $(SRC_OBJ)
# **

all : $(NAME)

$(NAME) : $(ALLOBJ) $(HEADERS)
	$(CC) $(FLAG) $(GRAPHICS) $(ALLOBJ) -o $(NAME)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(HEADERS)
		@mkdir -p $(PATH_OBJ)
		@mkdir -p $(PATH_RAY_B)
		@mkdir -p $(PATH_MNMP_B)
		@mkdir -p $(PATH_PROJ_B)
		$(CC) $(FLAG) -c $< -o $@

clean :
	@rm -r $(PATH_OBJ)

fclean : clean
		@rm -f $(NAME)

re	: fclean all
