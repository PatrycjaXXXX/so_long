/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:07:46 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/16 19:19:53 by psmolich         ###   ########.fr       */
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
		return (FAIL);
	return (SUCCESS);
}

static int	count_rows(char *map_path)
{
	int		rows;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_error(2), FAIL);
	rows = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_error(3), FAIL);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == FAIL)
		return (ft_error(-1), FAIL);
	return (rows);
}

static char	**create_map(char *map_path, int rows)
{
	char	**map;
	int		fd;
	int		i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_error(2), NULL);
	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (ft_error(13), NULL);
	i = 0;
	while (i <= rows)
		map[i++] = get_next_line(fd);
	if (close(fd) == FAIL)
		return (ft_free_arr(map), ft_error(-1), NULL);
	return (map);
}

int	check_map(char *map_path)
{
	char	**map;
	int		fd;
	int		rows;

	if (check_format(map_path) == FAIL)
		return (ft_error(1), FAIL);
	rows = count_rows(map_path);
	if (rows == FAIL)
		return (FAIL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_error(2), FAIL);
	map = create_map(fd, rows);
	if (!map)
		return (FAIL);
	
	ft_free_arr(map);
	return (SUCCESS);
}
