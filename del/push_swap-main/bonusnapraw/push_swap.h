/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:02:27 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/11 06:40:28 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FAIL -1
# define SUCCESS 1

typedef struct s_list
{
	int				content;
	int				index;
	int				lis_len;
	int				lis_keep;
	struct s_list	*lis_prev;
	struct s_list	*next_in_a;
	int				move_cost;
	struct s_list	*next;
}	t_list;

int		apply_instr(char *instr, t_list **stack_a, t_list **stack_b);
int		record_arg(int ac, char **av, t_list **stack_a);

int		ft_move(char *move, t_list **a, t_list **b);
void	ft_movetop(t_list **a, t_list **b, t_list *node_a, t_list *node_b);
int		steps_to_top(int index, int size);
void	adjuststeps(int *a_steps, int *b_steps, int size_a, int size_b);

void	ft_selectionsort(t_list **a, t_list **b, int size_a);

void	ft_longest_increasing_subsequence_sort(t_list **a, t_list **b);
void	push_non_keep_to_b(t_list **a, t_list **b);

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstfree(t_list **lst);
int		ft_lstissorted_as(t_list *lst);
int		ft_lstissorted_des(t_list *lst);
t_list	*ft_lstlargest(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content, int index);
int		ft_lstindex(t_list *lst, t_list *node);
void	ft_lstprint(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstsmallest(t_list *lst);

#endif