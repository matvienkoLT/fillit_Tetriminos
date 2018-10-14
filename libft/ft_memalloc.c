/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:57:51 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:04:58 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memory;

	memory = malloc(size);
	if (memory == NULL)
		return (NULL);
	else
		ft_bzero(memory, size);
	return (memory);
}
