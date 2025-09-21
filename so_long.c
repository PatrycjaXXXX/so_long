/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/09/13 20:10:01 by psmolich		  #+#	#+#			 */
/*   Updated: 2025/09/20 17:58:10 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error(0), FAIL);
	game = (t_game){0};
	if (get_map(&game, av[1]) == FAIL)
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
	if (generate_map(&game) == FAIL)
		return (free_game(&game), FAIL);
	mlx_hook(game.win, 2, (1L << 0), key_press, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
