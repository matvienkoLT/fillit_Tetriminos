/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:26:49 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:46:44 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *array1, const void *array2, size_t len)
{
	unsigned char	*array1_tmp;
	unsigned char	*array2_tmp;

	array1_tmp = (unsigned char *)array1;
	array2_tmp = (unsigned char *)array2;
	while (len--)
	{
		if (*array1_tmp != *array2_tmp)
			return (*array1_tmp - *array2_tmp);
		array1_tmp++;
		array2_tmp++;
	}
	return (0);
}
