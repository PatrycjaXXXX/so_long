/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:59:47 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/31 11:16:03 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static int	ft_move(char *move, t_list **a, t_list **b)
{
	ft_printf("A: ");
	if (a)
		ft_lstprint(*a, 'c');
	ft_printf("B: ");
	if (b)
		ft_lstprint(*b, 'c');
	ft_printf("%s", move);
	return (apply_instr(move, a, b));
}

int	des_to_as(t_list **a, t_list **b, int size_a)
{
	int	moves;

	if (size_a == 2)
		return (ft_move("sa\n", a, b));
	moves = size_a - 3;
	while (moves--)
	{
		ft_move("rra\n", a, b);
		ft_move("pb\n", a, b);
	}
	ft_move("ra\n", a, b);
	ft_move("sa\n", a, b);
	while (*b)
		ft_move("pa\n", a, b);
	return (ft_lstissorted_as(*a));
}

static void	ft_sort3(t_list **a, t_list **b)
{
	while (1)
	{
		if ((*a)->content > (*a)->next->content)
			ft_move("sa\n", a, b);
		if (ft_lstissorted_as(*a) == SUCCESS)
			break ;
		ft_move("rra\n", a, b);
	}
}

int	ft_selectionsort(t_list **a, t_list **b, int size_a)
{
	int	moves;
	int	min;

	moves = size_a - 3;
	while (moves--)
	{
		min = ft_lstsmallest(*a)->content;
		while ((*a)->content != min)
			ft_move("ra\n", a, b);
		ft_move("pb\n", a, b);
	}
	ft_sort3(a, b);
	while (*b)
		ft_move("pa\n", a, b);
	return (SUCCESS);
}

static t_list	*ft_brokenchain(t_list *stack_a, int bit)
{
	t_list	*wrong;

	wrong = stack_a;
	while (wrong)
	{
		if (!((wrong->content >> bit) & 1))
			return (wrong);
		wrong = wrong->next;
	}
	return (NULL);
}

static void	ft_moveup(t_list **stack, t_list *newtop)
{
	int		position_r;
	int		position_rr;
	char	*move;

	position_r = ft_lstpos_s(*stack, newtop);
	position_rr = ft_lstpos_e(*stack, newtop);
	ft_printf("%i x ra    %i x rra\n", position_r, position_rr);
	if (position_r < position_rr)
		move = "ra\n";
	else
		move ="rra\n";
	while ((*stack) != newtop)
		ft_move(move, stack, NULL);
}

int	ft_radixsort(t_list **a, t_list **b, int size_a)
{
	int		max_bits;
	int		bit;
	int		i;

	max_bits = ft_bitcount(size_a - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size_a)
		{
			if (ft_brokenchain(*a, bit))
			{
				if ((((*a)->content >> bit) & 0) && need_to_rotate())
					ft_move("pb\n", a, b);
				else
					ft_moveup(a, ft_brokenchain(*a, bit));
			}
			i++;
		}
		while (*b)
			ft_move("pa\n", a, b);
		ft_printf("bit checked: %i\n", bit);
		bit++;
	}
	return (SUCCESS);
}

