/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:08:38 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/18 08:46:13 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FAIL -1
# define SUCCESS 1

# define MAP_CHARS "01CEP"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map_count
{
	int	collectible_parse;
	int	exit_parse;
	int	player_parse;
	int	collectible_flood;
	int	exit_flood;
	int	player_flood;
}	t_map_count;

typedef struct s_map
{
	char		*map_path;
	char		**map;
	t_point		size;
	t_map_count	*map_count;
}	t_map;

void	ft_error(int code);

char	**create_map(char *map_path);
int		check_map(t_map *map);
int		map_parse(char **map, t_point size, t_map_count *map_count);
int		map_flood(t_map *map);

#endif