/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:33:59 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/28 17:23:50 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft/libft.h"
#include <unistd.h>
#define FAIL -1
#define SUCCESS 1

static void	cleanup(t_list **stack_a, t_list **stack_b)
{
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
}

static int	get_instr(t_list **stack_a, t_list **stack_b)
{
	char		*instr;

	instr = get_next_line(0);
	while (instr != NULL)
	{
		if (apply_instr(instr, stack_a, stack_b) == FAIL)
			return (free(instr), cleanup(stack_a, stack_b), FAIL);
		free(instr);
		instr = get_next_line(0);
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (FAIL);
	stack_a = NULL;
	if (record_arg(ac, av, &stack_a) == FAIL)
		return (ft_lstfree(&stack_a), write(2, "Error\n", 6), FAIL);
	stack_b = NULL;
	if (get_instr(&stack_a, &stack_b) == FAIL)
		return (write(2, "Error\n", 6), FAIL);
	if (ft_lst_issorted_as(stack_a) == SUCCESS && ft_lstempty(stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup(&stack_a, &stack_b);
	return (0);
}
