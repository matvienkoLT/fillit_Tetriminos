/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:05:55 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/04 16:07:10 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_table(int **table, int size)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (table[i][j] != 0)
			{
				c = table[i][j] + 64;
				ft_putchar(c);
			}
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}
