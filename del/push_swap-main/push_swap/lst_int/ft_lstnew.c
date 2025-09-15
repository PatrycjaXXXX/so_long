/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:33:02 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/10 05:36:19 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_int.h"
#include <stdlib.h>

t_list	*ft_lstnew(int content, int index)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
	lstnew->index = index;
	lstnew->next = NULL;
	return (lstnew);
}
