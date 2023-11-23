NAME_BONUS		= cub3D_bonus
NAME			= cub3D

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


# ###
# #####		B O N U S  P A R T    ###########
# ###

PATH_SRC_BNS	= ./source_b/
PATH_OBJ_BNS	= ./build_b/

#**
# **	--> raycasting_bonus
#**
PATH_RAY_BNS		= ./raycasting_b/
FILE_RAY_C_BNS		= raycasting_bonus.c	hori_ray_bonus.c	ver_ray_bonus.c	tools_bonus.c

PATH_RAY_B_BNS		= $(PATH_OBJ_BNS)raycasting_b/
FILE_RAY_OBJ_BNS	= $(FILE_RAY_C_BNS:.c=.o)
RAY_OBJ_BNS			= $(addprefix $(PATH_RAY_B_BNS), $(FILE_RAY_OBJ_BNS))
#	----------------------------------

#**
# **	--> parr_bonus
#**
PATH_PARS_BNS		= ./parsing_b/
FILE_PARS_BNS_C		= color_bonus.c color_utile_bonus.c color_utile1_bonus.c compass_bonus.c compass_utile_bonus.c get_next_line_bonus.c get_next_line_utile_bonus.c libft_bonus.c \
					makemap_bonus.c map_pars_bonus.c pars_utile2_bonus.c pars_utils_bonus.c pars_utils1_bonus.c compass_utile1_bonus.c

PATH_PARS_B_BNS		= $(PATH_OBJ_BNS)parsing_b/
FILE_PARS_B_BNS		= $(FILE_PARS_BNS_C:.c=.o)
PARS_OBJ_BNS		= $(addprefix $(PATH_PARS_B_BNS), $(FILE_PARS_B_BNS))
#	----------------------------------

#**
# **	--> MINMAP_bonus
#**
PATH_MNMP	= ./minimap_b/
FILE_MNMP_C	= tools_bonus.c	gridWall_bonus.c	player_bonus.c	minimap_bonus.c	mini_mlx_bonus.c

PATH_MNMP_B	= $(PATH_OBJ_BNS)minimap_b/
FILE_MNMP_B	= $(FILE_MNMP_C:.c=.o)
MNMP_OBJ_B	= $(addprefix $(PATH_MNMP_B), $(FILE_MNMP_B))
#	----------------------------------

#**
# **	--> PROJECTION_bonus
#**
PATH_PROJ_BNS	= ./projection_b/
FILE_PROJ_C_BNS	= 3dwall_bonus.c calcul_text_bonus.c dda_bonus.c

PATH_PROJ_B_BNS	= $(PATH_OBJ_BNS)projection_b/
FILE_PROJ_B_BNS	= $(FILE_PROJ_C_BNS:.c=.o)
PROJ_OBJ_BNS	= $(addprefix $(PATH_PROJ_B_BNS), $(FILE_PROJ_B_BNS))
#	----------------------------------

#**
# **	--> SOURCE_bonus
#**
FILE_SRC_C_BNS	= main_bonus.c ft_mlx_bonus.c draw_bonus.c	hook_bonus.c tools_bonus.c	frees_bonus.c

FILE_SRC_B_BNS	= $(FILE_SRC_C_BNS:.c=.o)
SRC_OBJ_BNS		= $(addprefix $(PATH_OBJ_BNS), $(FILE_SRC_B_BNS))
#	----------------------------------

# ** Global Vars
HEADERS_BNS		= ./source_b/cub3d_bonus.h ./source_b/minimap_b/minimap_bonus.h
ALLOBJ_BNS		= $(RAY_OBJ_BNS) $(MNMP_OBJ_B) $(PROJ_OBJ_BNS) $(SRC_OBJ_BNS) $(PARS_OBJ_BNS)
# **

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(ALLOBJ_BNS) $(HEADERS_BNS)
	$(CC) $(ALLOBJ_BNS) $(GRAPHICS) -o $(NAME_BONUS)

$(PATH_OBJ_BNS)%.o: $(PATH_SRC_BNS)%.c $(HEADERS_BNS)
		@mkdir -p $(PATH_OBJ_BNS)
		@mkdir -p $(PATH_RAY_B_BNS)
		@mkdir -p $(PATH_MNMP_B)
		@mkdir -p $(PATH_PROJ_B_BNS)
		@mkdir -p $(PATH_PARS_B_BNS)
		$(CC) $(FLAG) -c $< -o $@

clean_b :
	@rm -rf $(PATH_OBJ_BNS)

fclean_b : clean_b
		@rm -rf $(NAME_BONUS)

re_b		: fclean bonus
