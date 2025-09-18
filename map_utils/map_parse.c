/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:18:39 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/18 08:32:43 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

static void	print_parse_errors(t_map_count map_count)
{
	if (map_count.player_parse < 1)
		ft_error(7);
	if (map_count.exit_parse < 1)
		ft_error(8);
	if (map_count.collectible_parse < 1)
		ft_error(9);
	if (map_count.player_parse > 1)
		ft_error(10);
	if (map_count.exit_parse > 1)
		ft_error(11);
}

int	map_parse(char **map, t_point size, t_map_count *map_count)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		if ((int)ft_strlen(map[y]) != size.x)
			return (ft_error(4), FAIL);
		while (map[y][++x])
		{
			if ((y == 0 || x == 0 || y == (size.y - 1) || x == (size.x - 1))
				&& map[y][x] != '1')
				return (ft_error(5), FAIL);
			if (!ft_strchr(MAP_CHARS, map[y][x]))
				return (ft_error(6), FAIL);
			map_count->collectible_parse += (map[y][x] == 'C');
			map_count->exit_parse += (map[y][x] == 'E');
			map_count->player_parse += (map[y][x] == 'P');
		}
	}
	if (map_count->collectible_parse < 1
		|| map_count->player_parse != 1 || map_count->exit_parse != 1)
		return (print_parse_errors(*map_count), FAIL);
	return (SUCCESS);
}
