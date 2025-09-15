/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:23:56 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/28 18:48:18 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#define FAIL -1
#define SUCCESS 1

static int	ft_sort_lstint(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	if (ft_lst_issorted_des(*stack_a) == SUCCESS)
		return (des_to_as(stack_a, stack_b, size_a));
	else if (size_a <= 10)
		// ft_selectionsort(stack_a, stack_b, size_a);
		ft_bubblesort(stack_a, stack_b);
	else
		ft_radixsort(stack_a, stack_b, size_a);
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
	if (ft_lst_issorted_as(stack_a) == SUCCESS)
		return (ft_lstfree(&stack_a), 0);
	stack_b = NULL;
	if (ft_sort_lstint(&stack_a, &stack_b) == FAIL)
		return (ft_lstfree(&stack_a), ft_lstfree(&stack_b),
			write(2, "Error\n", 6), FAIL);
	ft_lstfree(&stack_a);
	ft_lstfree(&stack_b);
	return (0);
}
