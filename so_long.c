/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/09/13 20:10:01 by psmolich		  #+#	#+#			 */
/*   Updated: 2025/09/20 17:58:10 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

static void	free_game(t_game *game)
{
	free(game->map.map_count);
	ft_free_tab(game->map.map);
}

static int	load_img(t_game *game)
{
	int	tmp;

	tmp = TILE;
	game->tile.trees = mlx_xpm_file_to_image(game->mlx, TREES, &tmp, &tmp);
	game->tile.empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &tmp, &tmp);
	game->tile.witch_l = mlx_xpm_file_to_image(game->mlx, WITCH_L, &tmp, &tmp);
	game->tile.witch_r = mlx_xpm_file_to_image(game->mlx, WITCH_R, &tmp, &tmp);
	game->tile.cat = mlx_xpm_file_to_image(game->mlx, CAT, &tmp, &tmp);
	game->tile.door_c = mlx_xpm_file_to_image(game->mlx, DOOR_C, &tmp, &tmp);
	game->tile.door_o = mlx_xpm_file_to_image(game->mlx, DOOR_O, &tmp, &tmp);
	if (!game->tile.trees || !game->tile.empty
		|| !game->tile.witch_l || !game->tile.witch_r
		|| !game->tile.cat || !game->tile.door_c || !game->tile.door_o)
		return (ft_error(15), FAIL);
	return (SUCCESS);
}

static int	generate_map(t_game *game)
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

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error(0), FAIL);
	if (get_map(&game, av[1]) == FAIL)
		return (FAIL);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_error(14), FAIL);
	game.win = mlx_new_window(game.mlx,
			game.map.size.x * TILE,
			game.map.size.y * TILE,
			"so_long");
	if (!game.win)
		return (ft_error(16), FAIL);
	if (generate_map(&game) == FAIL)
		return (free_game(&game), FAIL);
	mlx_loop(game.mlx);
	return (0);
}
