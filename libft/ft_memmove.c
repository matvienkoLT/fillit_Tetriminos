/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:56:31 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:22:41 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	if (dest_tmp > src_tmp)
	{
		dest_tmp = dest_tmp + len - 1;
		src_tmp = src_tmp + len - 1;
		while (len--)
			*dest_tmp-- = *src_tmp--;
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
