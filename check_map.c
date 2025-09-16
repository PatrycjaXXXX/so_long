/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:07:46 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/16 20:54:23 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>

static t_map_count	map_parse(char	**map)
{
	t_map_count	map_parse;
	int			i;

	map_parse.collectible = 0;
	map_parse.exit = 0;
	map_parse.player = 0;
	i = 0;
}

int	check_map(char **map)
{
	t_map_count	map_parse;
	t_map_count	map_flood;

	map_parse = map_parse(map);
	ft_free_arr(map);
	return (SUCCESS);
}
