// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   t_list.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/08/30 14:57:16 by psmolich          #+#    #+#             */
// /*   Updated: 2025/08/30 15:03:39 by psmolich         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "checker.h"
// #include <stdlib.h>

// t_list	*ft_lstnew(int content)
// {
// 	t_list	*lstnew;

// 	lstnew = malloc(sizeof(t_list));
// 	if (!lstnew)
// 		return (NULL);
// 	lstnew->content = content;
// 	lstnew->next = NULL;
// 	return (lstnew);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	if (!lst || !new)
// 		return ;
// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	last = ft_lstlast(*lst);
// 	last->next = new;
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = *lst;
// 	*lst = new;
// }

// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// int	ft_lst_issorted_as(t_list *lst)
// {
// 	t_list	*curr;

// 	if (!lst)
// 		return (FAIL);
// 	curr = lst;
// 	while (curr && curr->next)
// 	{
// 		if (curr->content > curr->next->content)
// 			return (FAIL);
// 		curr = curr->next;
// 	}
// 	return (SUCCESS);
// }
