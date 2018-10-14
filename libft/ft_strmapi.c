/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 22:11:21 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:12:03 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str_new;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!(s))
		return (NULL);
	if (!(str_new = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		str_new[i] = f(i, str[i]);
		i++;
	}
	return (str_new);
}
