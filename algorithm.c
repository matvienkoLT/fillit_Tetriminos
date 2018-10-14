/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:24:49 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/04 16:41:04 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_backtrack_check(t_arr k, int *index_r, int *elem, int *cord_n)
{
	if (elem[4] >= 1)
	{
		ft_memset(cord_n, 0, 4 * sizeof(int));
		if ((ft_backtracking(k, index_r, elem, cord_n)))
			return (1);
		else
		{
			elem[5]++;
			while (elem[5] < elem[4])
			{
				ft_memset(cord_n, 0, 4 * sizeof(int));
				if ((ft_backtracking(k, index_r, elem, cord_n)))
					return (1);
				elem[5]++;
			}
			free(elem);
			free(index_r);
			return (0);
		}
	}
	return (0);
}

int		***putting_on_figur_tpart(t_arr k, int *elem, int *pk)
{
	int	*index_r;

	while (elem[0] > 0)
	{
		elem[1]--;
		elem[0]--;
		elem[4] = elem[2] - elem[0];
		index_r = cr_index_elem(elem[4], elem[1]);
		if (put_new_position_fig(k.area, k.maps, elem, pk))
			return (k.maps);
		if (elem[4] > 1)
		{
			elem[5]++;
			while (elem[5] < elem[4])
			{
				if ((ft_backtracking(k, index_r, elem, pk)))
					return (k.maps);
				elem[5]++;
			}
		}
		elem[5] = 0;
	}
	free_memory_all(k.maps, elem[2] + 2, elem[3]);
	free_memory_all(k.area, elem[2] + 1, elem[3]);
	return (NULL);
}

int		***putting_on_figur(int ***area, int size_tab, int num_fig, int *pk)
{
	int		el[6];
	int		***maps;
	t_arr	k;

	initialization(el, size_tab, num_fig);
	maps = (int ***)malloc(sizeof(int **) * (num_fig + 2));
	maps[el[0]] = area[0];
	k.maps = maps;
	k.area = area;
	while (el[1] <= num_fig)
	{
		if (!(maps[el[1]] = putfig(area[el[1]], maps[el[0]], size_tab, pk)))
		{
			maps = putting_on_figur_tpart(k, el, pk);
			break ;
		}
		ft_memset(pk, 0, (sizeof(int) * 4));
		el[0]++;
		el[1]++;
	}
	return (maps);
}

int		ft_backtracking(t_arr k, int *i_a, int *parameters, int *cord)
{
	int	*index_r;
	int	*el;
	int	cord_n[4];
	int	*p;

	ft_memset(cord_n, 0, 4 * sizeof(int));
	p = cp_parameters(cord, 4);
	el = cp_parameters(parameters, 6);
	if ((k.maps[el[1]] = putfig(k.area[i_a[el[5]]], k.maps[el[0]], el[3], p)))
	{
		if (el[1] == el[2])
			return (1);
		index_r = cr_index_without_elem(i_a, --el[4], i_a[el[5]]);
		el[5] = 0;
		el[0]++;
		el[1]++;
		return (ft_backtrack_check(k, index_r, el, cord_n));
	}
	free(el);
	return (0);
}

void	initialization(int *elem, int size_tab, int num_fig)
{
	elem[0] = 0;
	elem[1] = 1;
	elem[2] = num_fig;
	elem[3] = size_tab;
	elem[4] = 0;
	elem[5] = 0;
}
