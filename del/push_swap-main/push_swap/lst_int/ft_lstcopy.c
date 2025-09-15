/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 06:26:04 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/10 06:36:12 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_int.h"
#include <stdlib.h>

t_list  *ft_lstcopy(t_list *src)
{
	t_list	*new_list;
	t_list	*new_node;

	if (!src)
		return (NULL);
	new_list = NULL;
	while (src)
	{
		new_node = ft_lstnew(src->content, src->index);
		if (!new_node)
			return (ft_lstfree(&new_list), NULL);
		ft_lstadd_back(&new_list, new_node);
		src = src->next;
	}
	return (new_list);
}
