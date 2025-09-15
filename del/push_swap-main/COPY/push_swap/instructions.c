/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:02:33 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/10 12:16:21 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

static void	push(t_list **from, t_list **to)
{
	t_list	*second_from;

	if (!from || !to || !*from)
		return ;
	second_from = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = second_from;
}

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	last = ft_lstlast(*stack);
	first->next = NULL;
	last->next = first;
	*stack = second;
}

static void	reverse_rotate(t_list **stack)
{
	t_list	*second_to_last;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_to_last = *stack;
	while (second_to_last->next && second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = second_to_last->next;
	second_to_last->next = NULL;
	ft_lstadd_front(stack, last);
}

int	apply_instr(char *instr, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(instr, "sa\n")))
		return (swap(stack_a), SUCCESS);
	else if (!(ft_strcmp(instr, "sb\n")))
		return (swap(stack_b), SUCCESS);
	else if (!(ft_strcmp(instr, "ss\n")))
		return (swap(stack_a), swap(stack_b), SUCCESS);
	else if (!(ft_strcmp(instr, "pa\n")))
		return (push(stack_b, stack_a), SUCCESS);
	else if (!(ft_strcmp(instr, "pb\n")))
		return (push(stack_a, stack_b), SUCCESS);
	else if (!(ft_strcmp(instr, "ra\n")))
		return (rotate(stack_a), SUCCESS);
	else if (!(ft_strcmp(instr, "rb\n")))
		return (rotate(stack_b), SUCCESS);
	else if (!(ft_strcmp(instr, "rr\n")))
		return (rotate(stack_a), rotate(stack_b), SUCCESS);
	else if (!(ft_strcmp(instr, "rra\n")))
		return (reverse_rotate(stack_a), SUCCESS);
	else if (!(ft_strcmp(instr, "rrb\n")))
		return (reverse_rotate(stack_b), SUCCESS);
	else if (!(ft_strcmp(instr, "rrr\n")))
		return (reverse_rotate(stack_a), reverse_rotate(stack_b), SUCCESS);
	return (FAIL);
}
