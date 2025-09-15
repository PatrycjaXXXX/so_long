/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlargest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:11:15 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/30 16:12:16 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_list	*ft_lstlargest(t_list *lst)
{
	t_list	*curr;
	t_list	*largest;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	curr = lst;
	largest = curr;
	while (curr && curr->next)
	{
		if (largest->content < curr->next->content)
			largest = curr->next;
		curr = curr->next;
	}
	return (largest);
}
