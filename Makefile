CC := cc
CFLAGS := -Wall -Wextra -Werror -g

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

MINILIBX_DIR := minilibx
MINILIBX := $(MINILIBX_DIR)/libmlx.a

INCLUDES := -Iinclude -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
SYSLIB_FLG := -lXext -lX11 -lm

ENV_SRC := rt_env.c

ERROR_SRC := error.c

ERROR_SRC :=	rt_error.c

FIGURE_SRC :=	rt_figure.c		rt_figure_cylinder.c	rt_figure_plane.c	\
				rt_figure_sphere.c	rt_figure_utils.c

RAY_SRC :=		rt_ray.c

RT_MLX_SRC :=	rt_mlx_hook.c	rt_mlx_utils.c

UTILS_SRC :=	rt_utils_mem.c	rt_utils_str.c

VECTOR_SRC :=	rt_vec_op_arithmetic.c	rt_vec_op_product.c	rt_vec_utils.c

SRC_DIRS :=	env		error	figure	ray	\
			rt_mlx	utils	vector
SRCS :=	$(ENV_SRC)		$(ERROR_SRC)	$(FIGURE_SRC)	$(RAY_SRC)	\
		$(RT_MLX_SRC)	$(UTILS_SRC)	$(VECTOR_SRC)	minirt.c 

OBJ_DIR = obj
OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

vpath %.c $(SRC_DIRS)

NAME := miniRT

.PHONY: clean fclean re all check_dir

all: $(NAME)

check_dir:
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(SYSLIB_FLG) -o $@

$(OBJ_DIR)/%.o: %.c | check_dir
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
