/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:31:20 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/03/28 19:56:56 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *str_to_find)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(str_to_find);
	if (!(*str_to_find))
		return ((char *)src);
	while (src[i] != '\0')
	{
		while (src[i + j] == str_to_find[j])
		{
			if (j == (len - 1))
				return ((char *)src + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
