/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:02:48 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/10 12:35:13 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_selectionsort(t_list **a, t_list **b, int size_a)
{
	int		moves;
	t_list	*min;

	moves = size_a - 3;
	while (moves--)
	{
		min = ft_lstsmallest(*a);
		ft_movetop(a, b, min, NULL);
		if (ft_lstissorted_as(*a) == FAIL)
			ft_move("pb\n", a, b);
	}
	while (1)
	{
		if ((*a)->content > (*a)->next->content)
			ft_move("sa\n", a, b);
		if (ft_lstissorted_as(*a) == SUCCESS)
			break ;
		ft_move("rra\n", a, b);
	}
	while (*b)
		ft_move("pa\n", a, b);
}

static t_list	*find_next_in_a(t_list *a, t_list *node_b)
{
	t_list	*min;
	t_list	*max;
	t_list	*head;

	min = ft_lstsmallest(a);
	max = ft_lstlargest(a);
	if (node_b->content < min->content)
		return (min);
	if (node_b->content > max->content)
		return (max->next);
	head = a;
	while (a && a->next)
	{
		if (a->content < node_b->content && node_b->content < a->next->content)
			return (a->next);
		a = a->next;
	}
	return (head);
}

static int	totalcost(t_list *a, t_list *b, t_list *node_a, t_list *node_b)
{
	int	a_steps;
	int	b_steps;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	a_steps = steps_to_top(ft_lstindex(a, node_a), size_a);
	b_steps = steps_to_top(ft_lstindex(b, node_b), size_b);
	if (a_steps * b_steps < 0)
		adjuststeps(&a_steps, &b_steps, size_a, size_b);
	return ((int)(ft_abs(a_steps) + ft_abs(b_steps)));
}

void	ft_longest_increasing_subsequence_sort(t_list **a, t_list **b)
{
	t_list	*iter;
	t_list	*cheapest;

	push_non_keep_to_b(a, b);
	while (*b)
	{
		iter = *b;
		cheapest = *b;
		while (iter)
		{
			iter->next_in_a = find_next_in_a(*a, iter);
			iter->move_cost = totalcost(*a, *b, iter->next_in_a, iter)
				+ (iter->next_in_a == NULL);
			if (cheapest->move_cost > iter->move_cost)
				cheapest = iter;
			iter = iter->next;
		}
		ft_movetop(a, b, cheapest->next_in_a, cheapest);
		ft_move("pa\n", a, b);
		if ((*a)->next_in_a == NULL)
			ft_move("ra\n", a, b);
	}
	ft_movetop(a, b, ft_lstsmallest(*a), NULL);
}
