/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:10:01 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/18 08:38:04 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	check_format(char *map_path)
{
	char	*dot;

	dot = ft_strrchr(map_path, '.');
	if (!dot || ft_strcmp(dot, ".ber"))
		return (ft_error(1), FAIL);
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

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (ft_error(0), FAIL);
	if (check_format(av[1]) == FAIL)
		return (FAIL);
	map.map_path = av[1];
	map.map = create_map(map.map_path);
	if (!map.map)
		return (FAIL);
	map.size = get_size(map.map);
	map.map_count = (t_map_count *)ft_calloc(1, sizeof(t_map_count));
	if (!map.map_count)
		return (ft_free_tab(map.map), ft_error(13), FAIL);
	if (check_map(&map) == FAIL)
		return (FAIL);

	return (0);
}
