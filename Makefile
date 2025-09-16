# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 12:46:53 by psmolich          #+#    #+#              #
#    Updated: 2025/09/16 13:48:26 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC := cc
CFLAGS := -Wall -Wextra -Werror
MLXFLAGS := -lXext -lX11 -lm

NAME := so_long

LIB =  $(LIBFT) $(MLX)
LIBFT := libft/libft.a
MLX := minilibx-linux/libmlx.a
MLX_DIR := minilibx-linux
MLX_REPO := https://github.com/42Paris/minilibx-linux.git

SRCS := so_long.c

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
	make clean -C minilibx-linux/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/
	rm -rf $(MLX_DIR)

re: fclean all