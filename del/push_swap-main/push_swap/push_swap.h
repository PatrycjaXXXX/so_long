/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:23:58 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/28 18:49:01 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "lst_int/lst_int.h"

int	record_arg(int ac, char **av, t_list **stack_a);
int	apply_instr(char *instr, t_list **stack_a, t_list **stack_b);
int	des_to_as(t_list **stack_a, t_list **stack_b, int size_a);
int	ft_selectionsort(t_list **stack_a, t_list **stack_b, int size_a);
int	ft_bubblesort(t_list **stack_a, t_list **stack_b);
int	ft_radixsort(t_list **stack_a, t_list **stack_b, int size_a);
#endif
