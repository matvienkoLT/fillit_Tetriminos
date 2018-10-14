/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:20:44 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:47:02 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *str_to_find, size_t len)
{
	size_t i;
	size_t j;
	size_t str_len;

	i = 0;
	j = 0;
	str_len = ft_strlen(str_to_find);
	if (!(*str_to_find))
		return ((char *)src);
	while (src[i] != '\0' && i < len)
	{
		while ((src[i + j] == str_to_find[j]) && (i + j) < len)
		{
			if (j == (str_len - 1))
				return ((char *)src + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
