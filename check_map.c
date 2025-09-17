/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:07:46 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/17 20:13:01 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

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
	map[position.y][position.x] = 'V';
	map_count->collectible_flood += (map[position.y][position.x] == 'C');
	map_count->exit_flood += (map[position.y][position.x] == 'E');
	map_count->player_flood += (map[position.y][position.x] == 'P');
	flood_check(map, size, (t_point){position.x - 1, position.y}, map_count);
	flood_check(map, size, (t_point){position.x + 1, position.y}, map_count);
	flood_check(map, size, (t_point){position.x, position.y - 1}, map_count);
	flood_check(map, size, (t_point){position.x, position.y + 1}, map_count);
}

int	map_flood(char	**map, t_map_count *map_count, t_point size)
{
	t_point	player;
	char	**map_copy;

	player = find_player(map);
	if (player.x == -1 && player.y == -1)
		return (ft_error(7), FAIL);
	map_copy = create_map("maps/valid1.ber");
	if (!map_copy)
		return (ft_error(13), FAIL);
	flood_check(map_copy, size, player, map_count);
	ft_free_arr(map_copy);
	return (SUCCESS);
}

int	check_map(char **map, t_point size)
{
	t_map_count	*map_count;

	map_count = (t_map_count *)ft_calloc(1, sizeof(t_map_count));
	if (map_parse(map, map_count, size) == FAIL)
		return (free(map_count), ft_free_arr(map), FAIL);
	if (map_flood(map, map_count, size) == FAIL)
		return (free(map_count), ft_free_arr(map), FAIL);
	free(map_count);
	ft_free_arr(map);
	return (SUCCESS);
}
