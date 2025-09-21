# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 12:46:53 by psmolich          #+#    #+#              #
#    Updated: 2025/09/21 18:31:04 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all basic bonus clean fclean re
.DEFAULT_GOAL:= basic

CC := cc
CFLAGS := -Wall -Wextra -Werror
MLXFLAGS := -lXext -lX11 -lm

NAME := so_long
NAME_BONUS := so_long_bonus

LIB =  $(LIBFT) $(MLX)
LIBFT := libft/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX_DIR := minilibx-linux
MLX_REPO := https://github.com/42Paris/minilibx-linux.git

SRCS = so_long.c error.c free_game.c find.c key_press.c $(MAP_UTILS)

SRCS_BONUS = so_long.c error.c free_game.c find.c key_press_bonus.c \
				print_moves_bonus.c $(MAP_UTILS_BONUS)

MAP_UTILS := map_utils/get_map.c \
				map_utils/check_map.c \
				map_utils/map_flood.c \
				map_utils/create_map.c \
				map_utils/map_parse.c \
				map_utils/generate_map.c

MAP_UTILS_BONUS := map_utils/get_map.c \
				map_utils/check_map.c \
				map_utils/map_flood.c \
				map_utils/create_map.c \
				map_utils/map_parse.c \
				map_utils/generate_map_bonus.c

all: $(NAME) $(NAME_BONUS)

basic: $(NAME)

$(NAME): $(LIB)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(SRCS) $(LIB)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIB)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME_BONUS) $(SRCS_BONUS) $(LIB)

$(LIBFT):
	make -C libft/

$(MLX): | $(MLX_DIR)
	make -C minilibx-linux/

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)

clean:
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C libft/
	rm -rf $(MLX_DIR)

re: fclean all
