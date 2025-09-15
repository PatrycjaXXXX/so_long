/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissorted_des.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:09:04 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/05 15:06:00 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lst_int.h"
#define FAIL -1
#define SUCCESS 1

int	ft_lst_issorted_des(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (FAIL);
	curr = lst;
	while (curr && curr->next)
	{
		if (curr->content < curr->next->content)
			return (FAIL);
		curr = curr->next;
	}
	return (SUCCESS);
}
