# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/12/15 15:33:35 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR := ./sources
INC_DIR := ./includes
INCMLX_DIR := ./fdf_lib/mlx
INCLIBFT_DIR := ./libft/includes
OBJ_DIR := ./objects
LIB_DIR := ./libft

SRC_COMMON := complex.c draw_fractol.c keyhooks_fractol.c fractol_init.c \
		put_legend_fractol.c cycle_fractol1.c cycle_fractol2.c mouse_fractol.c\
		zoom_move_fractol.c init_cl.c init_topcl.c init_cl_load_src.c draw_cl.c

SRC  := main.c $(SRC_COMMON)

HDRS := includes/fractol.h includes/fractol_opcl.h
OBJ  := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJECTS = $(SOURCES:.c=.o)

FDF_SRC_DIR := ./fdf_lib/sources
FDF_HDR_DIR := ./fdf_lib/includes
FDF_OBJ_DIR := ./fdf_lib/objects

FDF_SRC := fdf_color.c fdf_draw_point.c fdf_draw_pixel_line.c fdf_get_proj_point.c \
	fdf_initialize_mlx.c fdf_iso_transform.c fdf_rotation.c \
	fdf_make_map_points.c fdf_keyhook.c draw_surface.c \
	fdf_draw_figures.c fdf_legend.c fdf_draw_figures_box.c \
	fdf_calc_hzoom.c fdf_clear_image.c fdf_rotation_matrix.c \
	fdf_rotation_matrix1.c fdf_draw_image.c

FDF_HDR := ./fdf_lib/includes/fdf.h

FDF_OBJ := $(FDF_SRC:.c=.o)
FDF_OBJ_WITH_PATH := $(addprefix $(FDF_OBJ_DIR)/, $(FDF_OBJ))


CC := gcc
CFLAGS := -O3 -g3 -Wall -Wextra -Werror
MLXPARAMS := -L ./fdf_lib/mlx -lmlx -framework OpenGL -framework AppKit -framework OpenCL
LIBFT_NODEBUG :=

L_FT := libft

include $(L_FT)/libft_base.mk
TMP = $(subst ./, /, $(ALL_LIBFT))
FULL_ALL_LIBFT = $(addprefix $(L_FT),$(TMP))

SRC_LIB = $(addprefix $(L_FT)/,$(LIBFT_SRC))

HEADER_LIB = $(INCLIBFT_DIR)/libft.h

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

test:
	@echo $(FULL_ALL_LIBFT)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(FDF_OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(L_FT) fclean

re: fclean all


$(FDF_OBJ_DIR):
	mkdir -p $(FDF_OBJ_DIR)

$(FDF_OBJ_DIR)/%.o:$(FDF_SRC_DIR)/%.c $(FDF_HDR)
	$(CC) $(CFLAGS) $(LIB_INC) -I $(FDF_HDR_DIR) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(HDRS)
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -I $(FDF_HDR_DIR) -I $(INCMLX_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER_LIB) $(HDRS) $(FULL_ALL_LIBFT) $(FDF_OBJ_DIR) $(FDF_OBJ_WITH_PATH)
	$(MAKE) -C $(L_FT) $(LIBFT_NODEBUG)
	$(CC) $(CFLAGS) $(OBJ) $(FDF_OBJ_WITH_PATH) -o $(NAME) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -L libft -lft $(MLXPARAMS)

nodebug: CFLAGS = -Wall -Wextra -O3 -Werror

nodebug: LIBFT_NODEBUG = nodebug

nodebug: all
