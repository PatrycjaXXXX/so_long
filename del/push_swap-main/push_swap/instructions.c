/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:19:06 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/05 13:28:18 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_int/lst_int.h"
#include "libft/libft.h"
#define FAIL -1
#define SUCCESS 1

static int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack)
		return (FAIL);
	if (!*stack || !(*stack)->next)
		return (SUCCESS);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (SUCCESS);
}

static int	push(t_list **from, t_list **to)
{
	t_list	*second_from;

	if (!from || !to)
		return (FAIL);
	if (!*from)
		return (SUCCESS);
	second_from = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = second_from;
	return (SUCCESS);
}

static int	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!stack)
		return (FAIL);
	if (!*stack || !(*stack)->next)
		return (SUCCESS);
	first = *stack;
	second = first->next;
	last = ft_lstlast(*stack);
	first->next = NULL;
	last->next = first;
	*stack = second;
	return (SUCCESS);
}

static int	reverse_rotate(t_list **stack)
{
	t_list	*second_to_last;
	t_list	*last;

	if (!stack)
		return (FAIL);
	if (!*stack || !(*stack)->next)
		return (SUCCESS);
	second_to_last = *stack;
	while (second_to_last->next && second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = second_to_last->next;
	second_to_last->next = NULL;
	ft_lstadd_front(stack, last);
	return (SUCCESS);
}

int	apply_instr(char *instr, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(instr, "sa\n")))
		return (swap(stack_a));
	else if (!(ft_strcmp(instr, "sb\n")))
		return (swap(stack_b));
	else if (!(ft_strcmp(instr, "ss\n")))
		return ((swap(stack_a) == FAIL || swap(stack_b) == FAIL) * FAIL);
	else if (!(ft_strcmp(instr, "pa\n")))
		return (push(stack_b, stack_a));
	else if (!(ft_strcmp(instr, "pb\n")))
		return (push(stack_a, stack_b));
	else if (!(ft_strcmp(instr, "ra\n")))
		return (rotate(stack_a));
	else if (!(ft_strcmp(instr, "rb\n")))
		return (rotate(stack_b));
	else if (!(ft_strcmp(instr, "rr\n")))
		return ((rotate(stack_a) == FAIL || rotate(stack_b) == FAIL) * FAIL);
	else if (!(ft_strcmp(instr, "rra\n")))
		return (reverse_rotate(stack_a));
	else if (!(ft_strcmp(instr, "rrb\n")))
		return (reverse_rotate(stack_b));
	else if (!(ft_strcmp(instr, "rrr\n")))
		return ((reverse_rotate(stack_a) == FAIL
				|| reverse_rotate(stack_b) == FAIL) * FAIL);
	return (FAIL);
}
