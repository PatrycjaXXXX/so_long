# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 12:46:53 by psmolich          #+#    #+#              #
#    Updated: 2025/09/20 19:40:37 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC := cc
CFLAGS := -Wall -Wextra -Werror
MLXFLAGS := -lXext -lX11 -lm

NAME := so_long

LIB =  $(LIBFT) $(MLX)
LIBFT := libft/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX_DIR := minilibx-linux
MLX_REPO := https://github.com/42Paris/minilibx-linux.git

SRCS = so_long.c error.c free_game.c $(MAP_UTILS)

MAP_UTILS := map_utils/get_map.c \
				map_utils/check_map.c \
				map_utils/map_flood.c \
				map_utils/create_map.c \
				map_utils/map_parse.c \
				map_utils/generate_map.c

all: $(NAME)

$(NAME): $(LIB)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(SRCS) $(LIB)

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
	make fclean -C libft/
	rm -rf $(MLX_DIR)

re: fclean all

res:
	rm -f $(NAME)
	make 