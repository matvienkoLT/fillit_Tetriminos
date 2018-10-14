/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:37:40 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/02 19:18:59 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (char)c;
	len = ft_strlen(str);
	while (len != 0 && str[len] != ch)
		len--;
	if (str[len] == ch)
		return (&str[len]);
	return (NULL);
}
