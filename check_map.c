/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:07:46 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/18 07:50:34 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

static t_point	find_player(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return ((t_point){x, y});
			x++;
		}
		y++;
	}
	return ((t_point){-1, -1});
}

static void	flood_check(char	**map, t_point size, t_point position,
	t_map_count *map_count)
{
	if (position.y < 0 || position.x < 0
		|| position.y >= size.y || position.x >= size.x)
		return ;
	if (map[position.y][position.x] == '1' || map[position.y][position.x] == 'V')
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

	player = find_player(map->map);
	if (player.x == -1 && player.y == -1)
		return (ft_error(7), FAIL);
	map_copy = create_map(map->map_path);
	if (!map_copy)
		return (ft_error(13), FAIL);
	flood_check(map_copy, map->size, player, map->map_count);
	ft_free_tab(map_copy);
	return (SUCCESS);
}

static int	compare_results(t_map_count map_count)
{
	if (map_count.collectible_parse == map_count.collectible_flood
		&& map_count.exit_parse == map_count.exit_flood
		&& map_count.player_parse == map_count.player_flood)
		return (SUCCESS);
	return (ft_error(12), FAIL);
}

int	check_map(t_map *map)
{
	if (map_parse(map->map, map->size, map->map_count) == FAIL)
		return (free(map->map_count), ft_free_tab(map->map), FAIL);
	if (map_flood(map) == FAIL)
		return (free(map->map_count), ft_free_tab(map->map), FAIL);
	if (compare_results(*(map->map_count)) == FAIL)
		return (free(map->map_count), ft_free_tab(map->map), FAIL);
	else
		ft_printf("playable\n");
	free(map->map_count);
	ft_free_tab(map->map);
	return (SUCCESS);
}
