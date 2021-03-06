/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 20:49:55 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/11 20:56:14 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprime(int n)
{
	int i;

	i = 2;
	if ((n > 1) && (n % n == 0))
	{
		while (i < n)
		{
			if (n % i == 0)
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}
