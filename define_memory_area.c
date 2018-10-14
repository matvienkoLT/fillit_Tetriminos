/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_memory_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:50:44 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/04 17:46:13 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	size_area(int quantity_figure)
{
	int	res;
	int square_size;

	if (!quantity_figure)
		return (0);
	square_size = 2;
	res = quantity_figure * 4;
	while (res > square_size * square_size)
		square_size++;
	return (square_size);
}

int	**define_memory_area(int square_size)
{
	int	**mass;
	int	i;

	i = 0;
	mass = (int**)malloc(sizeof(int*) * (size_t)square_size);
	if (!mass)
		return (NULL);
	while (i < square_size)
	{
		mass[i] = (int*)malloc(sizeof(int) * (size_t)square_size);
		if (!mass[i])
		{
			clear_memory(mass, i - 1);
			return (NULL);
		}
		ft_memset(mass[i], 0, sizeof(int) * (size_t)square_size);
		i++;
	}
	return (mass);
}

int	***areas_create(char ***fig, int size_mass, int fig_num)
{
	int ***areas;
	int i;

	i = 0;
	areas = (int ***)malloc(sizeof(int **) * (fig_num + 1));
	areas[i] = define_memory_area(size_mass);
	while (++i <= fig_num)
	{
		if (!(areas[i] = find_elem_on_map(fig[i - 1], areas[0], size_mass, i)))
			return (NULL);
	}
	return (areas);
}

int	**find_elem_on_map(char **elem, int **tb, int size, int num_fig)
{
	int	i[2];
	int pos_slice_x;
	int pos_slice_y;
	int	**ptr_table;

	ptr_table = ft_cpymemtable(tb, size);
	ft_memset(i, 0, (sizeof(int) * 2));
	pos_slice_x = position_slice_x(4, elem);
	pos_slice_y = position_slice_y(4, elem);
	while (i[0] < 4)
	{
		while (i[1] < 4)
		{
			if (elem[i[0]][i[1]] == '#')
			{
				if (i[0] - pos_slice_y >= size || i[1] - pos_slice_x >= size)
					return (NULL);
				ptr_table[i[0] - pos_slice_y][i[1] - pos_slice_x] = num_fig;
			}
			i[1]++;
		}
		i[0]++;
		i[1] = 0;
	}
	return (ptr_table);
}
