/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:46:07 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/21 17:13:13 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

static void	change_direction_of_player(t_game *game, int x)
{
	if (x == 1)
	{
		if (game->player_direction != game->tile.witch_r)
		{
			game->player_direction = game->tile.witch_r;
			mlx_put_image_to_window(game->mlx, game->win,
				game->player_direction,
				game->player.x * TILE, game->player.y * TILE);
		}
	}
	else if (x == -1)
	{
		if (game->player_direction != game->tile.witch_l)
		{
			game->player_direction = game->tile.witch_l;
			mlx_put_image_to_window(game->mlx, game->win,
				game->player_direction,
				game->player.x * TILE, game->player.y * TILE);
		}
	}
}

static void	change_images(t_game game, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.win,
		game.player_direction,
		game.player.x * TILE, game.player.y * TILE);
	mlx_put_image_to_window(game.mlx, game.win,
		game.tile.empty,
		(game.player.x - x) * TILE, (game.player.y - y) * TILE);
}

static void	open_doors(t_game game)
{
	if (game.to_collect == 0)
		mlx_put_image_to_window(game.mlx, game.win,
			game.tile.door_o,
			game.exit.x * TILE, game.exit.y * TILE);
}

static void	move(t_game *game, int x, int y)
{
	char	next;
	t_point	next_pos;

	change_direction_of_player(game, x);
	next_pos = (t_point){game->player.x + x, game->player.y + y};
	next = find_type(*game, next_pos.y, next_pos.x);
	if (next == '1' || (next == 'E' && game->to_collect))
		return ;
	if (next == '0' || next == 'C')
	{
		game->moves++;
		ft_printf("Moves: %i\n", game->moves);
		game->collected += (next == 'C');
		game->to_collect -= (next == 'C');
		game->map.map[game->player.y + y][game->player.x + x] = 'P';
		game->map.map[game->player.y][game->player.x] = '0';
		game->player = find_coordinates(game->map.map, 'P');
		change_images(*game, x, y);
		open_doors(*game);
	}
	if (next == 'E' && game->to_collect == 0)
	{
		ft_printf("You made it\n");
		close_game(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	if (keycode == W || keycode == UP)
		move(game, 0, -1);
	if (keycode == A || keycode == LEFT)
		move(game, -1, 0);
	if (keycode == S || keycode == DOWN)
		move(game, 0, 1);
	if (keycode == D || keycode == RIGHT)
		move(game, 1, 0);
	return (0);
}

// static void	move_up(t_game *game)
// {
// 	char	next;

// 	next = find_type(*game, game->player.y - 1, game->player.x);
// 	if (next == '1' || (next == 'E' && game->to_collect))
// 		return ;
// 	if (next == '0' || next == 'C')
// 	{
// 		game->moves++;
// 		game->collected += (next == 'C');
// 		game->to_collect -= (next == 'C');
// 		game->map.map[game->player.y - 1][game->player.x] = 'P';
// 		game->map.map[game->player.y][game->player.x] = '0';
// 		game->player = (t_point){game->player.x, game->player.y - 1};
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->player_direction,
// 			game->player.x * TILE, game->player.y * TILE);
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->tile.empty,
// 			game->player.x * TILE, (game->player.y + 1) * TILE);
// 		if (game->to_collect == 0)
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				game->tile.door_o,
// 				game->exit.x * TILE, game->exit.y * TILE);
// 	}
// 	if (next == 'E' && game->to_collect == 0)
// 	{
// 		ft_printf("You made it\n");
// 		close_game(game);
// 	}
// }

