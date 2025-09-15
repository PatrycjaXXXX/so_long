/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:03:07 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/11 05:11:14 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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