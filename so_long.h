/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:08:38 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/16 15:36:02 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FAIL -1
# define SUCCESS 1

# define MAP_CHARS "01CEP"

int		check_map(char *map_path);
void	ft_error(int code);
#endif