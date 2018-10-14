/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:48:31 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:45:33 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *array, int c, size_t len)
{
	unsigned char *array_tmp;
	unsigned char c_tmp;

	array_tmp = (unsigned char *)array;
	c_tmp = (unsigned char)c;
	while (len--)
	{
		if (*array_tmp == c_tmp)
			return (array_tmp);
		array_tmp++;
	}
	return (NULL);
}
