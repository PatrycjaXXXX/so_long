/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:57:25 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/10 08:46:57 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lst_int.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*curr;

	if (!lst)
	{
		ft_printf("[NULL]\n");
		return ;
	}
	ft_printf("[head]");
	curr = lst;
	while (curr)
	{
		ft_printf(" -> ");
		ft_printf("{%b}%i(%i)", curr->content, curr->content, curr->index);
		curr = curr->next;
	}
	ft_printf("\n");
}
