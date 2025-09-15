/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 05:26:09 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 05:29:08 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	ft_error(int code)
{
	char	*err_msg[10];

	err_msg[0] = ""
	ft_printf("Error\n%s\n", err_msg[code]);
}