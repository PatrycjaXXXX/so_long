/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:44:37 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/08 05:29:49 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define FAIL -1
# define SUCCESS 1

// typedef struct s_list
// {
// 	int				content;
// 	struct s_list	*next;
// }	t_list;

int		apply_instr(char *instr, t_list **stack_a, t_list **stack_b);
int		record_arg(int ac, char **av, t_list **stack_a);

// t_list	*ft_lstnew(int content);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// void	ft_lstadd_front(t_list **lst, t_list *new);
// t_list	*ft_lstlast(t_list *lst);
// int		ft_lst_issorted_as(t_list *lst);

#endif