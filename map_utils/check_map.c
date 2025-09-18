/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:07:46 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/18 08:30:36 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

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
