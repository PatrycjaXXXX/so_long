/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissorted_as.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:12:25 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/05 11:59:56 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_int.h"
#define FAIL -1
#define SUCCESS 1

int	ft_lst_issorted_as(t_list *lst)
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
