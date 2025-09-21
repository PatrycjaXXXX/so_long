/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 08:04:42 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/21 15:30:23 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

static void	flood_check(char	**map, t_point size, t_point position,
	t_map_count *map_count)
{
	if (position.y < 0 || position.x < 0
		|| position.y >= size.y || position.x >= size.x)
		return ;
	if (map[position.y][position.x] == '1'
		|| map[position.y][position.x] == 'V')
		return ;
	map_count->collectible_flood += (map[position.y][position.x] == 'C');
	map_count->exit_flood += (map[position.y][position.x] == 'E');
	map_count->player_flood += (map[position.y][position.x] == 'P');
	map[position.y][position.x] = 'V';
	flood_check(map, size, (t_point){position.x - 1, position.y}, map_count);
	flood_check(map, size, (t_point){position.x + 1, position.y}, map_count);
	flood_check(map, size, (t_point){position.x, position.y - 1}, map_count);
	flood_check(map, size, (t_point){position.x, position.y + 1}, map_count);
}

int	map_flood(t_map *map)
{
	t_point	player;
	char	**map_copy;

	player = find_coordinates(map->map, 'P');
	if (player.x == -1 && player.y == -1)
		return (ft_error(7), FAIL);
	map_copy = create_map(map->map_path);
	if (!map_copy)
		return (ft_error(13), FAIL);
	flood_check(map_copy, map->size, player, map->map_count);
	ft_free_tab(map_copy);
	return (SUCCESS);
}
