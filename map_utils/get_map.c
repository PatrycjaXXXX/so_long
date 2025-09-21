/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:37:14 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/21 15:54:58 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

static int	check_format(char *file_path, t_game *game)
{
	char	*dot;

	dot = ft_strrchr(file_path, '.');
	if (!dot || ft_strcmp(dot, ".ber"))
		return (ft_error(1), FAIL);
	game->map.map_path = file_path;
	return (SUCCESS);
}

static t_point	get_size(char **map)
{
	int	x;
	int	y;

	x = ft_strlen(map[0]);
	y = 0;
	while (map[y])
		y++;
	return ((t_point){x, y});
}

int	get_map(t_game *game, char *file_path)
{
	if (check_format(file_path, game) == FAIL)
		return (FAIL);
	game->map.map = create_map(game->map.map_path);
	if (!game->map.map)
		return (FAIL);
	game->map.size = get_size(game->map.map);
	game->map.map_count = (t_map_count *)ft_calloc(1, sizeof(t_map_count));
	if (!game->map.map_count)
		return (ft_free_tab(game->map.map), ft_error(13), FAIL);
	if (check_map(&game->map) == FAIL)
		return (FAIL);
	game->player = find_coordinates(game->map.map, 'P');
	game->player_direction = game->tile.witch_r;
	game->exit = find_coordinates(game->map.map, 'E');
	game->to_collect = game->map.map_count->collectible_parse;
	return (SUCCESS);
}
