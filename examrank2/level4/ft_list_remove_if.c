#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void	*data;
}	t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*cur;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	cur = *begin_list;
	while (cur && cur->next)
	{
		if (cmp(cur->next->data, data_ref) == 0)
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			free(tmp);
		}
		else
			cur = cur->next;
	}
}

int cmp(void *a, void *b)
{
	return strcmp((char *)a, (char *)b);
}

t_list *new_node(char *s)
{
	t_list *n = malloc(sizeof(t_list));
	n->data = s;
	n->next = NULL;
	return n;
}

int main(void)
{
	t_list *list = new_node("hello");
	list->next = new_node("42");
	list->next->next = new_node("school");
	list->next->next->next = new_node("42");
	list->next->next->next->next = new_node("test");

	ft_list_remove_if(&list, "42", cmp);

	while (list)
	{
		printf("%s\n", (char *)list->data);
		list = list->next;
	}
}

// void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
// {
// 	t_list	*tmp;

// 	if (!begin_list || !*begin_list)
// 		return ;
// 	if (cmp((*begin_list)->data, data_ref) == 0)
// 	{
// 		tmp = *begin_list;
// 		*begin_list = (*begin_list)->next;
// 		free(tmp);
// 		ft_list_remove_if(begin_list, data_ref, cmp);
// 	}
// 	else
// 		ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
// }