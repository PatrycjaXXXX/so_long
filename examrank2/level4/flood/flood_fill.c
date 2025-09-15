/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:47:38 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/15 13:13:24 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

static int	out_of_border(t_point size, t_point point)
{
	return (point.y < 0 || point.x < 0
			|| point.y >= size.y || point.x >= size.x);
}

static void	fill(char **tab, t_point size, t_point current, char target)
{
	if (out_of_border(size, current))
		return ;
	if (tab[current.y][current.x] == 'F'
		|| tab[current.y][current.x] != target)
		return ;
	tab[current.y][current.x] = 'F';
	fill(tab, size, (t_point){current.x - 1, current.y}, target);
	fill(tab, size, (t_point){current.x + 1, current.y}, target);
	fill(tab, size, (t_point){current.x, current.y - 1}, target);
	fill(tab, size, (t_point){current.x, current.y + 1}, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target = tab[begin.y][begin.x];
	fill(tab, size, begin, target);
}
