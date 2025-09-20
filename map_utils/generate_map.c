/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:38:34 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/20 19:41:08 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

static int	load_img(t_game *game)
{
	int	tmp;

	tmp = TILE;
	game->tile.trees = mlx_xpm_file_to_image(game->mlx, TREES, &tmp, &tmp);
	if (!game->tile.trees)
		return (ft_error(15), FAIL);
	game->tile.empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &tmp, &tmp);
	if (!game->tile.empty)
		return (ft_error(15), FAIL);
	game->tile.witch_l = mlx_xpm_file_to_image(game->mlx, WITCH_L, &tmp, &tmp);
	if (!game->tile.witch_l)
		return (ft_error(15), FAIL);
	game->tile.witch_r = mlx_xpm_file_to_image(game->mlx, WITCH_R, &tmp, &tmp);
	if (!game->tile.witch_r)
		return (ft_error(15), FAIL);
	game->tile.cat = mlx_xpm_file_to_image(game->mlx, CAT, &tmp, &tmp);
	if (!game->tile.cat)
		return (ft_error(15), FAIL);
	game->tile.door_c = mlx_xpm_file_to_image(game->mlx, DOOR_C, &tmp, &tmp);
	if (!game->tile.door_c)
		return (ft_error(15), FAIL);
	game->tile.door_o = mlx_xpm_file_to_image(game->mlx, DOOR_O, &tmp, &tmp);
	if (!game->tile.door_o)
		return (ft_error(15), FAIL);
	return (SUCCESS);
}

int	generate_map(t_game *game)
{
	t_point	parse;
	void	*tile;

	if (load_img(game) == FAIL)
		return (FAIL);
	parse.y = -1;
	while (++parse.y < game->map.size.y && game->map.map[parse.y])
	{
		parse.x = -1;
		while (++parse.x < game->map.size.x && game->map.map[parse.y][parse.x])
		{
			if (game->map.map[parse.y][parse.x] == '0')
				tile = game->tile.empty;
			else if (game->map.map[parse.y][parse.x] == '1')
				tile = game->tile.trees;
			else if (game->map.map[parse.y][parse.x] == 'C')
				tile = game->tile.cat;
			else if (game->map.map[parse.y][parse.x] == 'E')
				tile = game->tile.door_c;
			else
				tile = game->tile.witch_r;
			mlx_put_image_to_window(game->mlx, game->win,
				tile, parse.x * TILE, parse.y * TILE);
		}
	}
	return (SUCCESS);
}
