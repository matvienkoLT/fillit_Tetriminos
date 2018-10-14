/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:45:11 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:47:21 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char *dest_tmp;
	unsigned char *src_tmp;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	while (len--)
	{
		*dest_tmp = *src_tmp;
		dest_tmp++;
		src_tmp++;
	}
	return (dest);
}
