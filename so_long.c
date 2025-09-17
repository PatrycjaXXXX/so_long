/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:10:01 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/17 20:10:15 by psmolich         ###   ########.fr       */
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
	char	**map;
	char	*map_path;
	t_point	size;

	if (ac != 2)
		return (ft_error(0), FAIL);
	map_path = av[1];
	if (check_format(map_path) == FAIL)
		return (FAIL);
	map = create_map(map_path);
	if (!map)
		return (ft_error(13), FAIL);
	size = get_size(map);
	if (check_map(map, size) == FAIL)
		return (FAIL);
	// ft_free_arr(map);
	return (0);
}
