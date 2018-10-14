/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:54:49 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 19:55:04 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	t_list	*lst_tmp;
	size_t	len;

	lst_tmp = lst;
	len = 0;
	while (lst_tmp)
	{
		len++;
		lst_tmp = lst_tmp->next;
	}
	return (len);
}
