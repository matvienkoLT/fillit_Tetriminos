/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:24:10 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:46:23 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_new;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	str_new = (char *)malloc(sizeof(char) *
(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str_new == NULL)
		return (NULL);
	while (*s1)
	{
		str_new[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		str_new[i++] = *s2;
		s2++;
	}
	str_new[i] = '\0';
	return (str_new);
}
