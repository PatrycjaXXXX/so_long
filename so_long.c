/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:10:01 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/16 20:29:28 by psmolich         ###   ########.fr       */
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

static char	**create_map(char *map_path)
{
	char	**map;
	int		fd;
	int		rows;
	int		i;

	rows = count_rows(map_path);
	if (rows == FAIL)
		return (NULL);
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

int	main(int ac, char **av)
{
	char	**map;
	char	*map_path;

	if (ac != 2)
		return (ft_error(0), FAIL);
	map_path = av[1];
	if (check_format(map_path) == FAIL)
		return (FAIL);
	map = create_map(map_path);
	if (!map)
		return (FAIL);
	if (check_map(map) == FAIL)
		return (FAIL);
	
	// ft_free_arr(map);
}
