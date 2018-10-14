/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:08:38 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/05/01 16:08:44 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrcnt(const char *str, char c)
{
	int		counter;

	counter = 0;
	if (!(*str) || !c)
		return (0);
	while (*str)
	{
		if (*str == c)
			counter++;
		str++;
	}
	return (counter);
}
