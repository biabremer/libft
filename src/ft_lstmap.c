/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 13:17:28 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *new;
	t_list *temp;

	if (lst == NULL || f == NULL)
		return (0);
	fresh = f(lst);
	new = ft_lstnew(fresh->content, fresh->content_size);
	if (new)
	{
		temp = new;
		lst = lst->next;
		while (lst != NULL)
		{
			fresh = f(lst);
			temp->next = ft_lstnew(fresh->content, fresh->content_size);
			if (temp->next == NULL)
				return (0);
			temp = temp->next;
			lst = lst->next;
		}
	}
	return (new);
}
