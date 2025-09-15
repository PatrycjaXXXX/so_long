/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsmallest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:15:55 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/30 16:16:21 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_list	*ft_lstsmallest(t_list *lst)
{
	t_list	*curr;
	t_list	*smallest;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	curr = lst;
	smallest = curr;
	while (curr && curr->next)
	{
		if (smallest->content > curr->next->content)
			smallest = curr->next;
		curr = curr->next;
	}
	return (smallest);
}
