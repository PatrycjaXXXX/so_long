/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 05:26:09 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/18 18:09:23 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <errno.h>
#include <string.h>

void	ft_error(int code)
{
	char	*err_msg[17];

	err_msg[0] = "Wrong number of arguments";
	err_msg[1] = "Map error: invalid file extension (must be .ber)";
	err_msg[2] = "Map error: file not found or cannot be opened";
	err_msg[3] = "Map error: file is empty";
	err_msg[4] = "Map error: map not rectangular";
	err_msg[5] = "Map error: map not surrounded by walls";
	err_msg[6] = "Map error: invalid character in map";
	err_msg[7] = "Map error: no player position found";
	err_msg[8] = "Map error: no exit found";
	err_msg[9] = "Map error: no collectibles found";
	err_msg[10] = "Map error: more than one player";
	err_msg[11] = "Map error: more than one exit";
	err_msg[12] = "Map error: not all collectibles or exit are reachable";
	err_msg[13] = "General error: memory allocation failed";
	err_msg[14] = "MLX error: initialization failed";
	err_msg[15] = "MLX error: failed to load image/texture";
	err_msg[16] = "MLX error: window creation failed";
	if (code == -1)
		ft_printf("Error\n%s\n", strerror(errno));
	else
		ft_printf("Error\n%s\n", err_msg[code]);
}
