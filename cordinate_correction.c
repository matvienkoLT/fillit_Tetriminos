/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinate_correction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:24:55 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/04 14:02:24 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	**ft_cpymemtable(int **table, int size)
{
	int **new_table;
	int i;
	int j;

	i = 0;
	j = 0;
	new_table = define_memory_area(size);
	while (i < size)
	{
		while (j < size)
		{
			new_table[i][j] = table[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (new_table);
}

int	position_slice_x(int n, char **elem)
{
	int i;
	int j;
	int	x;

	i = 0;
	j = 0;
	x = n;
	while (i < n)
	{
		while (j < n)
		{
			if (elem[i][j] == '#')
			{
				if (j < x)
					x = j;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (x);
}

int	position_slice_y(int n, char **elem)
{
	int i;
	int j;
	int	y;

	i = 0;
	j = 0;
	y = 0;
	while (i < n)
	{
		while (j < n)
		{
			if (elem[i][j] == '#')
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (y);
}

int	empty_case_begin(int *ptr_table)
{
	int i;

	i = 0;
	while (*(ptr_table++) == 0)
		i++;
	if (i == 0)
		return (0);
	else
		return (i);
}

int	check_empty_case(int **table, int size_tab, int *x, int *y)
{
	int i;
	int j;

	i = *y;
	j = *x;
	while (i < size_tab)
	{
		while (j < size_tab)
		{
			if (table[i][j] == 0)
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
