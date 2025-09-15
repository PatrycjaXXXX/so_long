/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:47:32 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/15 13:11:19 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

#endif