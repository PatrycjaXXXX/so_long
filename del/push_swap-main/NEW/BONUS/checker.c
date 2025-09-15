/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:44:33 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/08 05:31:31 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/libft.h"
#include "../MANDATORY/push_wap.h"
#include <unistd.h>

void	ft_lstfree(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

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
	if (ft_lst_issorted_as(stack_a) == SUCCESS && (stack_b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup(&stack_a, &stack_b);
	return (0);
}
