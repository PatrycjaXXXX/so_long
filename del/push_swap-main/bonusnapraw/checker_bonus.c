/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:17:39 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/13 19:32:26 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft/libft.h"
#include <unistd.h>

static void	cleanup(t_list **stack_a, t_list **stack_b)
{
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
}

static void	get_instr(char **instr)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		r_bytes;

	while (1)
	{
		r_bytes = read(0, buf, BUFFER_SIZE);
		if (r_bytes < 0)
			return ;
		if (r_bytes == 0)
			break ;
		buf[r_bytes] = '\0';
		if (!*instr)
			temp = ft_strjoin("", buf);
		else
			temp = ft_strjoin(*instr, buf);
		if (!temp)
			return ;
		free(*instr);
		*instr = temp;
		if (ft_strchr(*instr, '\n'))
			break ;
	}
}

static int	check_instr(t_list **stack_a, t_list **stack_b)
{
	char	*instr;

	while (1)
	{
		instr = NULL;
		get_instr(&instr);
		if (instr == NULL)
			break ;
		if (apply_instr(instr, stack_a, stack_b) == FAIL)
		{
			free(instr);
			cleanup(stack_a, stack_b);
			return (FAIL);
		}
		free(instr);
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
	if (check_instr(&stack_a, &stack_b) == FAIL)
		return (write(2, "Error\n", 6), FAIL);
	if (ft_lstissorted_as(stack_a) == SUCCESS && (stack_b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup(&stack_a, &stack_b);
	return (0);
}
