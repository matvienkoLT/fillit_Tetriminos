/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:50:44 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:46:05 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	while (len)
	{
		new_str[i] = s[start];
		i++;
		start++;
		len--;
	}
	new_str[i] = '\0';
	return (new_str);
}
