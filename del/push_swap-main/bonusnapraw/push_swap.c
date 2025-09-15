/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:02:44 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/12 10:22:02 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

int	ft_move(char *move, t_list **a, t_list **b)
{
	ft_printf("%s", move);
	return (apply_instr(move, a, b));
}

static void	normalize_data(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	min;
	int	i;

	i = 0;
	while (*stack_a)
	{
		min = ft_lstsmallest(*stack_a)->content;
		while ((*stack_a)->content != min)
			apply_instr("ra\n", stack_a, stack_b);
		apply_instr("pb\n", stack_a, stack_b);
		(*stack_b)->content = i++;
	}
	while (*stack_b)
	{
		size_a--;
		while ((*stack_b)->index != size_a)
			apply_instr("rb\n", stack_a, stack_b);
		apply_instr("pa\n", stack_a, stack_b);
	}
}

static int	ft_sort(t_list **a, t_list **b)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (size_a == 2)
		ft_move("sa\n", a, b);
	else if (size_a <= 10)
		ft_selectionsort(a, b, size_a);
	else
	{
		normalize_data(a, b, size_a);
		ft_longest_increasing_subsequence_sort(a, b);
	}
	return (ft_lstissorted_as(*a));
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (FAIL);
	a = NULL;
	if (record_arg(ac, av, &a) == FAIL)
		return (ft_lstfree(&a), write(2, "Error\n", 6), FAIL);
	if (ft_lstissorted_as(a) == SUCCESS)
		return (ft_lstfree(&a), 0);
	b = NULL;
	if (ft_sort(&a, &b) == FAIL)
		return (ft_lstfree(&a), ft_lstfree(&b),
			write(2, "Error\n", 6), FAIL);
	ft_lstfree(&a);
	ft_lstfree(&b);
	return (0);
}
