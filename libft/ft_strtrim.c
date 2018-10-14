/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:39:40 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:16:23 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;

	if (s == NULL)
		return (0);
	i = 0;
	len = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (s[i] == '\0')
		return (ft_strsub(s, i, len - i + 1));
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len > i)
		len--;
	return (ft_strsub(s, i, len - i + 1));
}
