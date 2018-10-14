/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:58:16 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/03/26 18:40:55 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int symbol, size_t len)
{
	size_t			i;
	unsigned char	*str_tmp;
	unsigned char	smbl;

	i = 0;
	smbl = (unsigned char)symbol;
	str_tmp = (unsigned char *)str;
	while (i < len)
	{
		str_tmp[i] = smbl;
		i++;
	}
	return (str_tmp);
}
