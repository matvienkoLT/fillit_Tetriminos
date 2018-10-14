/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:57:56 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:17:14 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;
	unsigned char	c_tmp;
	size_t			i;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	c_tmp = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		dest_tmp[i] = src_tmp[i];
		if (src_tmp[i] == c_tmp)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
