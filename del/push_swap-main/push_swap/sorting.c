/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sorting.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/08/05 13:27:41 by psmolich		  #+#	#+#			 */
/*   Updated: 2025/08/06 11:36:53 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"
#define FAIL -1
#define SUCCESS 1

static int	move_lst(char *move, t_list **stack_a, t_list **stack_b)
{
	ft_printf("%s", move);
	return (apply_instr(move, stack_a, stack_b));
}

int	des_to_as(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	moves;

	if (size_a == 2)
		return (move_lst("sa\n", stack_a, stack_b));
	moves = size_a - 3;
	while (moves--)
	{
		move_lst("rra\n", stack_a, stack_b);
		move_lst("pb\n", stack_a, stack_b);
	}
	move_lst("ra\n", stack_a, stack_b);
	move_lst("sa\n", stack_a, stack_b);
	while (*stack_b)
		move_lst("pa\n", stack_a, stack_b);
	return (ft_lst_issorted_as(*stack_a));
}

static void	ft_sort3(t_list **stack_a, t_list **stack_b)
{
	while (1)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			move_lst("sa\n", stack_a, stack_b);
		if (ft_lst_issorted_as(*stack_a) == SUCCESS)
			break ;
		move_lst("rra\n", stack_a, stack_b);
	}
}

int	ft_selectionsort(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	moves;
	int	min;

	moves = size_a - 3;
	while (moves--)
	{
		min = ft_lstsmallest(*stack_a)->content;
		while ((*stack_a)->content != min)
			move_lst("ra\n", stack_a, stack_b);
		move_lst("pb\n", stack_a, stack_b);
	}
	ft_sort3(stack_a, stack_b);
	while (*stack_b)
		move_lst("pa\n", stack_a, stack_b);
	return (SUCCESS);
}

int	ft_bubblesort(t_list **stack_a, t_list **stack_b)
{
	int	moves;

	while (ft_lst_issorted_as(*stack_a) == FAIL)
	{
		moves = ft_lstsize(*stack_a) - 1;
		while (moves--)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
				move_lst("sa\n", stack_a, stack_b);
			move_lst("pb\n", stack_a, stack_b);
		}
		while (*stack_b)
			move_lst("pa\n", stack_a, stack_b);
	}
	return (SUCCESS);
}
