/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:33:46 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/10 06:50:03 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_INT_H
# define LST_INT_H

typedef struct s_list
{
	int				content;
		int				index;
			struct s_list	*next;
			}	t_list;

			void	ft_lstadd_back(t_list **lst, t_list *new);
			void	ft_lstadd_front(t_list **lst, t_list *new);
			t_list	*ft_lstcopy(t_list *src);
			int		ft_lstempty(t_list *head);
			void	ft_lstfree(t_list **lst);
			int		ft_lst_issorted_as(t_list *lst);
			int		ft_lst_issorted_des(t_list *lst);
			t_list	*ft_lstlast(t_list *lst);
			t_list	*ft_lstnew(int content, int index);
			void	ft_lstprint(t_list *lst);
			int		ft_lstsize(t_list *lst);
			t_list	*ft_lstlargest(t_list *lst);
			t_list	*ft_lstsmallest(t_list *lst);
#endif