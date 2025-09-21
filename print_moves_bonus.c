/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:19:36 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/21 18:25:06 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

void	print_moves(t_game *game)
{
	char	*move;
	char	*join;

	move = ft_itoa(game->moves);
	if (!move)
	{
		ft_error(13);
		close_game(game);
	}
	join = ft_strjoin("Moves: ", move);
	free(move);
	if (!join)
	{
		ft_error(13);
		close_game(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->tile.trees, 0, 0);
	mlx_string_put(game->mlx, game->win, 8, 41, 0xFFFFFF, join);
	free(join);
}
