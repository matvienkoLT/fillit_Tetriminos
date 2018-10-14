/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 21:24:29 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:32:21 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(dest + i) && i < size)
		i++;
	while (*(src + j) && (i + j + 1) < size)
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	if (i < size)
		*(dest + i + j) = 0;
	return (i + ft_strlen(src));
}
