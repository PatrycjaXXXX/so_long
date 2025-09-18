/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:10:01 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/18 18:40:01 by psmolich         ###   ########.fr       */
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
	t_game	game;

	if (ac != 2)
		return (ft_error(0), FAIL);
	if (check_format(av[1]) == FAIL)
		return (FAIL);
	game = (t_game)ft_calloc(1, sizeof(t_game));
	game.map.map_path = av[1];
	game.map.map = create_map(game.map.map_path);
	if (!game.map.map)
		return (FAIL);
	game.map.size = get_size(game.map.map);
	game.map.map_count = (t_map_count *)ft_calloc(1, sizeof(t_map_count));
	if (!game.map.map_count)
		return (ft_free_tab(game.map.map), ft_error(13), FAIL);
	if (check_map(&game.map) == FAIL)
		return (FAIL);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_error(14), FAIL);
	game.win = mlx_new_window(game.mlx,
			game.map.size.x * TILE,
			game.map.size.y * TILE,
			"so_long");
	if (!game.win)
		return (ft_error(16), FAIL);
	ft_put_images(game)
	mlx_loop(game.mlx);
	return (0);
}

// #include <stdio.h>

// #define IMG_SIZE 64
// #define NUM_IMGS 6

// int main(int ac, char **av)
// {
//     void    *mlx;
//     void    *win;
//     int     w, h;
// 	t_map	map;

// 	if (ac != 2)
// 		return (ft_error(0), FAIL);
// 	if (check_format(av[1]) == FAIL)
// 		return (FAIL);
// 	game.map.map_path = av[1];
// 	game.map.map = create_map(game.map.map_path);
// 	if (!game.map.map)
// 		return (FAIL);
// 	game.map.size = get_size(game.map.map);
// 	game.map.map_count = (t_map_count *)ft_calloc(1, sizeof(t_map_count));
// 	if (!game.map.map_count)
// 		return (ft_free_tab(game.map.map), ft_error(13), FAIL);
// 	if (check_map(&map) == FAIL)
// 		return (FAIL);
//     // Inicjalizacja MLX
//     mlx = mlx_init();
//     if (!mlx)
//     {
//         fprintf(stderr, "mlx_init() failed\n");
//         return (1);
//     }

//     // Tworzymy okno: szerokość = 6 * 64 = 384, wysokość = 64
//     win = mlx_new_window(mlx, NUM_IMGS * IMG_SIZE, IMG_SIZE, "XPM Demo");
//     if (!win)
//     {
//         fprintf(stderr, "mlx_new_window() failed\n");
//         return (1);
//     }

//     // Tablica z nazwami plików
//     char *files[NUM_IMGS] = {
//         "textures/cat.xpm",
//         "textures/closed-doors.xpm",
//         "textures/open-doors.xpm",
//         "textures/trees.xpm",
//         "textures/witch.xpm",
// 		"textures/empty.xpm"
//     };

//     // Ładowanie i wyświetlanie obrazków
//     for (int i = 0; i < NUM_IMGS; i++)
//     {
//         imgs[i] = mlx_xpm_file_to_image(mlx, files[i], &w, &h);
//         if (!imgs[i])
//         {
//             fprintf(stderr, "Failed to load %s\n", files[i]);
//             return (1);
//         }

//         // rysujemy obrazek w oknie obok siebie
//         mlx_put_image_to_window(mlx, win, imgs[i], i * IMG_SIZE, 0);
//     }

//     // Pętla zdarzeń (okno będzie aktywne)
//     mlx_loop(mlx);

//     return (0);
// }
