/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlargest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:49:21 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/07 07:53:02 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_int.h"
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
