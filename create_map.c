/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:01:53 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/17 20:02:49 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

static int	trim_new_line(char **map)
{
	int		i;
	char	*temp;

	i = 0;
	while (map[i])
	{
		if (ft_strrchr(map[i], '\n'))
		{
			temp = ft_strtrim(map[i], "\n");
			if (!temp)
				return (FAIL);
			free(map[i]);
			map[i] = temp;
		}
		i++;
	}
	return (SUCCESS);
}

char	**create_map(char *map_path)
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
	if (trim_new_line(map) == FAIL)
		return (ft_free_arr(map), ft_error(13), NULL);
	if (close(fd) == FAIL)
		return (ft_free_arr(map), ft_error(-1), NULL);
	return (map);
}
