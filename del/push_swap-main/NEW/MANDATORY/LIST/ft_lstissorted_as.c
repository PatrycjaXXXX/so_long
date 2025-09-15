/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissorted_as.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:56:37 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/30 16:55:13 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstissorted_as(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (FAIL);
	curr = lst;
	while (curr && curr->next)
	{
		if (curr->content > curr->next->content)
			return (FAIL);
		curr = curr->next;
	}
	return (SUCCESS);
}
