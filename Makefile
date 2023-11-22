NAME		= cub3D_bonus

ADDRESS		= -fsanitize=address
CC			= cc
FLAG		= -Wall -Wextra -Werror -Imlx -ofast
GRAPHICS	= -lmlx -framework OpenGL -framework AppKit

PATH_SRC_B	= ./source_b/
PATH_OBJ_B	= ./build_b/

#**
# **	--> raycasting
#**
PATH_RAY_B		= ./raycasting_b/
FILE_RAY_C_B	= raycasting_bonus.c	hori_ray_bonus.c	ver_ray_bonus.c	tools_bonus.c

PATH_RAY_BB		= $(PATH_OBJ_B)raycasting_b/
B_FILE_RAY_B	= $(FILE_RAY_C_B:.c=.o)
RAY_OBJ_B		= $(addprefix $(PATH_RAY_BB), $(B_FILE_RAY_B))
#	----------------------------------

#**
# **	--> parr
#**
PATH_PARS_B		= ./parsing_b/
FILE_PARS_B_C	= color_bonus.c color_utile_bonus.c color_utile1_bonus.c compass_bonus.c compass_utile_bonus.c get_next_line_bonus.c get_next_line_utile_bonus.c libft_bonus.c \
					makemap_bonus.c map_pars_bonus.c pars_utile2_bonus.c pars_utils_bonus.c pars_utils1_bonus.c compass_utile1_bonus.c


PATH_PARS_B_B	= $(PATH_OBJ_B)parsing_b/
FILE_PARS_B_B	= $(FILE_PARS_B_C:.c=.o)
PARS_OBJ_B	= $(addprefix $(PATH_PARS_B_B), $(FILE_PARS_B_B))
#	----------------------------------

#**
# **	--> MINMAP
#**
PATH_MNMP	= ./minimap_b/
FILE_MNMP_C	= tools_bonus.c	gridWall_bonus.c	player_bonus.c	minimap_bonus.c	mini_mlx_bonus.c

PATH_MNMP_B	= $(PATH_OBJ_B)minimap_b/
FILE_MNMP_B	= $(FILE_MNMP_C:.c=.o)
MNMP_OBJ_B	= $(addprefix $(PATH_MNMP_B), $(FILE_MNMP_B))
#	----------------------------------

#**
# **	--> PROJECTION
#**
PATH_PROJ_B	= ./projection_b/
FILE_PROJ_C_B	= 3dwall_bonus.c calcul_text_bonus.c dda_bonus.c

PATH_PROJ_B_B	= $(PATH_OBJ_B)projection_b/
FILE_PROJ_B_B	= $(FILE_PROJ_C_B:.c=.o)
PROJ_OBJ_B	= $(addprefix $(PATH_PROJ_B_B), $(FILE_PROJ_B_B))
#	----------------------------------

#**
# **	--> SOURCE
#**
FILE_SRC_C_B	= main_bonus.c ft_mlx_bonus.c draw_bonus.c	hook_bonus.c tools_bonus.c	frees_bonus.c

PATH_SRC_B_B		= $(PATH_OBJ_B)
FILE_SRC_B_B	= $(FILE_SRC_C_B:.c=.o)
SRC_OBJ_B		= $(addprefix $(PATH_SRC_B_B), $(FILE_SRC_B_B))
#	----------------------------------

# ** Global Vars
HEADERS_B		= ./source_b/cub3d_bonus.h ./source_b/minimap_b/minimap_bonus.h
ALLOBJ		= $(OBJ) $(RAY_OBJ_B) $(MNMP_OBJ_B) $(PROJ_OBJ_B) $(SRC_OBJ_B) $(PARS_OBJ_B)
# **

all : $(NAME)

$(NAME) : $(ALLOBJ) $(HEADERS_B)
	$(CC) $(ALLOBJ) $(GRAPHICS) -o $(NAME)

$(PATH_OBJ_B)%.o: $(PATH_SRC_B)%.c $(HEADERS_B)
		@mkdir -p $(PATH_OBJ_B)
		@mkdir -p $(PATH_RAY_BB)
		@mkdir -p $(PATH_MNMP_B)
		@mkdir -p $(PATH_PROJ_B_B)
		@mkdir -p $(PATH_PARS_B_B)
		$(CC) $(FLAG) -c $< -o $@

clean :
	@rm -rf $(PATH_OBJ_B)

fclean : clean
		@rm -rf $(NAME)

re		: fclean all
