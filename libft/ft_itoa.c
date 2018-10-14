/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 21:49:55 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 18:41:40 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	len = ft_numlen(n);
	num = n;
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len)
	{
		str[--len] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
