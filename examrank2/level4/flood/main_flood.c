/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flood.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:48:28 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/18 06:04:30 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"
#include <string.h>

void	ft_free_tab(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return ;
}

char	**ft_make_area(char **zone)
{
	int		height = 0;
	int		i;
	char	**area;

	while (zone[height])
		height++;
	area = (char **)malloc(sizeof(char *) * (height + 1));
	if (!area)
		return (NULL);
	i = 0;
	while (i < height)
	{
		area[i] = strdup(zone[i]);
		i++;
	}
	area[i] = NULL;
	return (area);
}

void ft_print_tab(char **tab)
{
	int i = 0;

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
		NULL
	};
	area = ft_make_area(zone);
	ft_print_tab(area);
	flood_fill(area, size, begin);
	printf("\n");
	ft_print_tab(area);
	ft_free_tab(area);
	return (0);
}
