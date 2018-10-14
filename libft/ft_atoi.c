/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:54:34 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/04/09 15:59:52 by mzhovnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long int	num;
	int					is_negative;

	i = 0;
	num = 0;
	is_negative = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		is_negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if ((num > 922337203685477580 || (num == 922337203685477580
				&& (str[i] - '0') > 7)) && is_negative == 1)
			return (-1);
		else if ((num > 922337203685477580 || (num == 922337203685477580
				&& (str[i] - '0') > 8)) && is_negative == -1)
			return (0);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * is_negative);
}
