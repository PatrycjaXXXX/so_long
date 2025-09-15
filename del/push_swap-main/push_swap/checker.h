/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:34:02 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/21 14:47:22 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "lst_int/lst_int.h"

int	record_arg(int ac, char **av, t_list **stack_a);
int	apply_instr(char *instr, t_list **stack_a, t_list **stack_b);
#endif