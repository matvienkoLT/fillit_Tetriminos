/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:07:13 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/03/24 19:02:31 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*str_new;

	len = 0;
	while (str[len])
		len++;
	str_new = (char*)malloc(sizeof(*str_new) * (len + 1));
	if (str_new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
