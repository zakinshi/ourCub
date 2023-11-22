NAME		= cub3D

ADDRESS		= -fsanitize=address
CC			= cc
FLAG		= -Wall -Wextra -Werror -Imlx -ofast
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
# **	--> parr
#**
PATH_PARS	= ./parsing/
FILE_PARS_C	= color.c color_utile.c color_utile1.c compass.c compass_utile.c get_next_line.c get_next_line_utile.c libft.c \
			makemap.c map_pars.c pars_utile2.c pars_utils.c pars_utils1.c compass_utile1.c


PATH_PARS_B	= $(PATH_OBJ)parsing/
FILE_PARS_B	= $(FILE_PARS_C:.c=.o)
PARS_OBJ	= $(addprefix $(PATH_PARS_B), $(FILE_PARS_B))
#	----------------------------------

#**
# **	--> PROJECTION
#**
PATH_PROJ	= ./projection/
FILE_PROJ_C	= 3dwall.c calcul_text.c dda.c player.c

PATH_PROJ_B	= $(PATH_OBJ)projection/
FILE_PROJ_B	= $(FILE_PROJ_C:.c=.o)
PROJ_OBJ	= $(addprefix $(PATH_PROJ_B), $(FILE_PROJ_B))
#	----------------------------------

#**
# **	--> SOURCE
#**
FILE_SRC_C	= main.c ft_mlx.c draw.c	hook.c tools.c	frees.c

PATH_SRC_B	= $(PATH_OBJ)
FILE_SRC_B	= $(FILE_SRC_C:.c=.o)
SRC_OBJ		= $(addprefix $(PATH_SRC_B), $(FILE_SRC_B))
#	----------------------------------

# ** Global Vars
HEADERS		= ./source/cub3d.h
ALLOBJ		= $(OBJ) $(RAY_OBJ) $(PROJ_OBJ) $(SRC_OBJ) $(PARS_OBJ)
# **

all : $(NAME)

$(NAME) : $(ALLOBJ) $(HEADERS)
	$(CC) $(ALLOBJ) $(GRAPHICS) -o $(NAME)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(HEADERS)
		@mkdir -p $(PATH_OBJ)
		@mkdir -p $(PATH_RAY_B)
		@mkdir -p $(PATH_PROJ_B)
		@mkdir -p $(PATH_PARS_B)
		$(CC) $(FLAG) -c $< -o $@

clean :
	@rm -rf $(PATH_OBJ)

fclean : clean
		@rm -rf $(NAME)

re		: fclean all
