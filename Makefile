NAME					:=	miniRT
NAME_NOSIMD				:=	miniRT_nosimd

MAIN					:=	main.c \
							keypress.c \
							keyrelease.c \
							loop.c \
							move_cam.c \
							move_shape.c \
							manual.c \
							render_settings.c \
							modify_shape.c \
							modify_shape_colour.c \
							populate_world.c \
							modify_light.c \
							save.c

PARSING					:=	parsing.c \
							lst_utils.c \
							parsing_utils.c \
							parse_scene.c \
							parse_shape.c \
							populate_scene.c \
							populate_shape.c \
							axis_rotation.c \
							parsing_error.c \
							parse_get.c \
							parsing_utils_ext.c \
							parse_options.c \
							rt_split.c

VECTORS					:=	vect_init.c \
							vect_ops.c \
							vect_utils.c \
							cross_product.c \
							dot_product.c

VECTORS_SIMD			:=	vect_init.c \
							zsimd_vect_ops.c \
							zsimd_vect_utils.c \
							zsimd_cross_product.c \
							zsimd_dot_product.c

MATRICES				:=	matrix_init.c \
							inverse.c \
							cofactor.c \
							matrix_utils.c \
							transformations.c

MATRICES_SIMD			:=	matrix_init.c \
							inverse.c \
							cofactor.c \
							simd_matrix_utils.c \
							transformations.c

RAYS					:=	ray.c \
							ray_trans.c \
							intersection.c \
							intersect_sphere.c \
							intersect_plane.c \
							intersect_cylinder.c \
							intersect_cone.c \
							intersect_cube.c

SCENE					:=	world.c \
							edit_world.c \
							light.c \
							camera.c \
							camera_utils.c \
							reflection.c

SHAPES					:=	shape.c \
							sphere.c \
							plane.c \
							cylinder.c \
							cone.c \
							cube.c \
							material.c \
							normal.c \
							pattern.c \
							pattern_maps.c

IMG						:=	mlx_init.c \
							colours.c \
							colour_ops.c \
							draw.c \
							lerp.c \
							lerp_utils.c

UTILS					:=	free_utils.c \
							maths_utils.c

SRCS					:=	$(addprefix main/, $(MAIN)) \
							$(addprefix vectors/, $(VECTORS)) \
							$(addprefix matrices/, $(MATRICES)) \
							$(addprefix parsing/, $(PARSING)) \
							$(addprefix rays/, $(RAYS)) \
							$(addprefix scene/, $(SCENE)) \
							$(addprefix shapes/, $(SHAPES)) \
							$(addprefix img/, $(IMG)) \
							$(addprefix utils/, $(UTILS))

SRCS_SIMD				:=	$(addprefix main/, $(MAIN)) \
							$(addprefix vectors/, $(VECTORS_SIMD)) \
							$(addprefix matrices/, $(MATRICES_SIMD)) \
							$(addprefix parsing/, $(PARSING)) \
							$(addprefix rays/, $(RAYS)) \
							$(addprefix scene/, $(SCENE)) \
							$(addprefix shapes/, $(SHAPES)) \
							$(addprefix img/, $(IMG)) \
							$(addprefix utils/, $(UTILS))

OBJ_DIR					:=	objs
OBJ						:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJ_SIMD				:=	$(addprefix $(OBJ_DIR)/, $(SRCS_SIMD:.c=.o))

CC						:=	cc

CFLAGS					:=	-Wall -Wextra -Werror -pthread
OPTIMIZATION_FLAGS 		:= -O3 -mavx -flto
LTO_FLAGS				:=  -flto
DIR_LIBFT				:=	libft/
DIR_SRCS				:=	srcs/
DIR_INC					:=	inc/

OS := $(shell uname)
ifeq ($(OS),Linux)
DIR_MLX					:= minilibx_linux/
LIBS					:= -L$(DIR_LIBFT) -lft -L$(DIR_MLX) -lmlx -lX11 -lXext -lm
else
DIR_MLX					:= minilibx_macos/
LIBS					:= -L$(DIR_LIBFT) -lft -L$(DIR_MLX) -lmlx -framework OpenGL -framework Appkit
endif

LIBFT_MLX				:= $(DIR_LIBFT)libft.a $(DIR_MLX)libmlx.a
INC						:= -I$(DIR_INC) -I$(DIR_LIBFT) -I$(DIR_MLX)

all: $(OBJ_DIR) $(LIBFT_MLX) $(NAME)

nosimd: $(OBJ_DIR) $(LIBFT_MLX) $(NAME_NOSIMD)

$(NAME): $(OBJ_SIMD) $(LIBFT_MLX)
	$(CC) $(CFLAGS) $(LTO_FLAGS) $(OBJ_SIMD) $(LIBS) -o $@

$(NAME_NOSIMD): $(OBJ) $(LIBFT_MLX)
	$(CC) $(CFLAGS) $(LTO_FLAGS) $(OBJ) $(LIBS) -o $@

$(OBJ_DIR):
	mkdir -p $@ $(addprefix $(OBJ_DIR)/, main vectors matrices parsing rays scene shapes img utils)

$(OBJ_DIR)/%.o: $(DIR_SRCS)/%.c
	$(CC) $(CFLAGS) $(INC) $(OPTIMIZATION_FLAGS) -c $< -o $@

$(LIBFT_MLX):
	make -C $(DIR_LIBFT)
	make -C $(DIR_MLX)

clean:
	make clean -C $(DIR_LIBFT)
	make clean -C $(DIR_MLX)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	rm -f $(NAME)
	rm -f $(NAME_NOSIMD)

re: fclean all

bonus: all
