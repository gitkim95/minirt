CC := cc
CFLAGS := -Wall -Wextra -Werror -g

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

MINILIBX_DIR := minilibx
MINILIBX := $(MINILIBX_DIR)/libmlx.a

INCLUDES := -Iinclude -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

SYSLIB_FLG := -lXext -lX11 -lm

SRC_DIRS := error	mlx_hook
OBJ_DIR = obj

SRCS :=	minirt.c	rt_error.c	rt_mlx_hook.c
OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

MEN_SRCS := 
MEN_OBJS := $(addprefix $(OBJ_DIR)/,$(MEN_SRCS:%.c=%.o))

BON_SRCS := 
BON_OBJS := $(addprefix $(OBJ_DIR)/,$(BON_SRCS:%.c=%.o))

vpath %.c $(SRC_DIRS)

ifdef BONUS
	OBJS += $(BON_OBJS)
else
	OBJS += $(MEN_OBJS)
endif

NAME := miniRT

.PHONY: clean fclean re all bonus check_dir

all: $(NAME)

bonus:
	@$(MAKE) --no-print-directory BONUS=1 $(NAME)

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
