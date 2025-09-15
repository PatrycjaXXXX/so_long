/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:56:44 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/06 22:02:05 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_list	*ft_lstnew(int content, int index)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
	lstnew->index = index;
	lstnew->lis_len = 1;
	lstnew->lis_keep = 0;
	lstnew->lis_prev = NULL;
	lstnew->next_in_a = NULL;
	lstnew->move_cost = 0;
	lstnew->next = NULL;
	return (lstnew);
}
