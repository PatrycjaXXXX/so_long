/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:46:07 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/21 16:05:41 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

static void	move_up(t_game *game)
{
	char	next;

	next = find_type(*game, game->player.y - 1, game->player.x);
	ft_printf("%c\n", next);
	if (next == '1' || (next == 'E' && game->to_collect))
		return ;
	if (next == '0' || next == 'C')
	{
		game->moves++;
		game->collected += (next == 'C');
		game->to_collect -= (next == 'C');
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_direction,
			game->player.x * TILE, (game->player.y - 1) * TILE);
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile.empty,
			game->player.x * TILE, game->player.y * TILE);
		if (game->to_collect == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->tile.door_o,
				game->exit.x * TILE, game->exit.y * TILE);
		game->map.map[game->player.y - 1][game->player.x] = 'P';
		game->map.map[game->player.y][game->player.x] = '0';
		game->player = (t_point){game->player.x, game->player.y - 1};
	}
	
}
close_game(game);
static void	move_down(t_game *game)
{
	ft_printf("down\n");
	close_game(game);
}

static void	move_left(t_game *game)
{
	ft_printf("left\n");
	close_game(game);
}

static void	move_right(t_game *game)
{
	ft_printf("right\n");
	close_game(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	if (keycode == W || keycode == UP)
		move_up(game);
	if (keycode == A || keycode == LEFT)
		move_left(game);
	if (keycode == S || keycode == DOWN)
		move_down(game);
	if (keycode == D || keycode == RIGHT)
		move_right(game);
	return (0);
}
