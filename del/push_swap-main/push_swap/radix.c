/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   radix.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/08/09 05:43:41 by psmolich		  #+#	#+#			 */
/*   Updated: 2025/08/10 06:16:51 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define FAIL -1
#define SUCCESS 1


static void	optimize_instr(char **instr)
{
	ft_strdel(instr, "pb\npa\n");
	ft_strdel(instr, "pa\npb\n");
	ft_strrep(instr, "sa\nsb\n", "ss\n");
	ft_strrep(instr, "sb\nsa\n", "ss\n");
	ft_strrep(instr, "ra\nrb\n", "rr\n");
	ft_strrep(instr, "rb\nra\n", "rr\n");
	ft_strrep(instr, "rra\nrrb\n", "rrr\n");
	ft_strrep(instr, "rrb\nrra\n", "rrr\n");
}

static int	save_move(char *move, t_list **stack_a, t_list **stack_b, char **instr)
{
	char	*tmp;

	if (!move || !instr)
		return (FAIL);
	tmp = ft_strjoin(*instr, move);
	if (!tmp)
		return (FAIL);
	free(*instr);
	*instr = tmp;
	optimize_instr(instr);
	return (apply_instr(move, stack_a, stack_b));
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

int	ft_radixsort(t_list **stack_a, t_list **stack_b, int size_a)
{
	int		max_bits;
	int		i;
	int		j;
	char	*instr;

	max_bits = ft_bitcount(size_a - 1);
	normalize_data(stack_a, stack_b, size_a);
	instr = ft_strdup("");
	if (!instr)
		return (FAIL);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size_a)
		{
			if ((((*stack_a)->content >> i) & 1) == 0)
				save_move("pb\n", stack_a, stack_b, &instr);
			else
				save_move("ra\n", stack_a, stack_b, &instr);
			j++;
		}
		while (*stack_b)
			save_move("pa\n", stack_a, stack_b, &instr);
		i++;
	}
	// if (ft_lst_issorted_as(*stack_a) == SUCCESS)
	// 	ft_printf("\nposortowana\n");
	
	ft_printf("%s", instr);
	free(instr);
	return (SUCCESS);
}


