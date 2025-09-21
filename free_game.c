/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:34:21 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/21 16:16:55 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

static void	destroy_img(t_game *game)
{
	if (game->tile.trees)
		mlx_destroy_image(game->mlx, game->tile.trees);
	if (game->tile.empty)
		mlx_destroy_image(game->mlx, game->tile.empty);
	if (game->tile.witch_l)
		mlx_destroy_image(game->mlx, game->tile.witch_l);
	if (game->tile.witch_r)
		mlx_destroy_image(game->mlx, game->tile.witch_r);
	if (game->tile.cat)
		mlx_destroy_image(game->mlx, game->tile.cat);
	if (game->tile.door_c)
		mlx_destroy_image(game->mlx, game->tile.door_c);
	if (game->tile.door_o)
		mlx_destroy_image(game->mlx, game->tile.door_o);
}

void	free_game(t_game *game)
{
	if (game->map.map_count)
		free(game->map.map_count);
	if (game->map.map)
		ft_free_tab(game->map.map);
	destroy_img(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}
