/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:20:05 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/06 16:12:25 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		nb_word;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	nb_word = ft_countwords((const char *)s, c);
	arr = (char **)malloc(sizeof(*arr) *
		(ft_countwords((const char *)s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		arr[i] = ft_strsub((const char *)s, 0,
ft_wordlen((const char *)s, c));
		if (arr[i] == NULL)
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
