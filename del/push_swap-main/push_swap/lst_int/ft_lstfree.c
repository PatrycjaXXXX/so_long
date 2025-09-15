/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:57:01 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/10 04:59:55 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_int.h"
#include <stdlib.h>

void	ft_lstfree(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
