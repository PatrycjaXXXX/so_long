/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:02:36 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/11 09:14:44 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static t_list	*find_best_end(t_list **a)
{
	t_list	*best_end;
	t_list	*i;
	t_list	*j;

	best_end = *a;
	i = *a;
	while (i)
	{
		j = *a;
		while (j != i)
		{
			if (j->content < i->content && j->lis_len + 1 > i->lis_len)
			{
				i->lis_len = j->lis_len + 1;
				i->lis_prev = j;
			}
			j = j->next;
		}
		if (i->lis_len > best_end->lis_len)
			best_end = i;
		i = i->next;
	}
	return (best_end);
}

static void	mark_keep(t_list **a)
{
	t_list	*best_end;

	best_end = find_best_end(a);
	while (best_end)
	{
		best_end->lis_keep = 1;
		best_end = best_end->lis_prev;
	}
}

static int	there_is_still_non_keep_in_a(t_list *a)
{
	while (a)
	{
		if (a->lis_keep == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

void	push_non_keep_to_b(t_list **a, t_list **b)
{
	int	median;

	mark_keep(a);
	median = ft_lstsize(*a) / 2;
	while (there_is_still_non_keep_in_a(*a))
	{
		if ((*a)->lis_keep == 0)
		{
			ft_move("pb\n", a, b);
			if ((*b)->content < median)
			{
				if ((*a)->lis_keep == 1 && there_is_still_non_keep_in_a(*a))
					ft_move("rr\n", a, b);
				else
					ft_move("rb\n", a, b);
			}
		}
		else
			ft_move("ra\n", a, b);
	}
}
