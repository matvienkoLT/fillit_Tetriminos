/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:17:41 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:26:01 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst_tmp;
	t_list	*lst_new;

	if (!(lst) || !(*f))
		return (NULL);
	lst_new = NULL;
	lst_tmp = NULL;
	if ((lst_new = (t_list *)malloc(ft_lstlen(lst) * sizeof(t_list))))
	{
		lst_new = f(ft_lstnew(lst->content, lst->content_size));
		lst_tmp = lst_new;
		lst = lst->next;
		while (lst)
		{
			lst_tmp->next = f(ft_lstnew(lst->content, lst->content_size));
			lst_tmp = lst_tmp->next;
			lst = lst->next;
		}
	}
	return (lst_new);
}
