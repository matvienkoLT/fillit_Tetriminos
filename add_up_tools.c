/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_up_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:04:49 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/04 16:13:59 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*check_overflow_massive(int *cord, int size_tab, int pos_slice)
{
	if (pos_slice < size_tab)
		cord[1]++;
	else if (pos_slice >= size_tab)
	{
		cord[1] = 0;
		cord[0]++;
	}
	return (cord);
}

int	last_element(int ***maps)
{
	int index;

	index = 0;
	while (maps[index] != 0)
		index++;
	return (index + 1);
}

int	**putfig(int **area, int **maps, int size_tab, int *cord)
{
	int	**ptr_map;

	ptr_map = check_next_element(maps, area, size_tab, cord);
	return (ptr_map);
}

int	put_new_position_fig(int ***area, int ***maps, int *elem, int *par)
{
	int		*pk;
	int		*index_r;
	t_arr	k;

	k.area = area;
	k.maps = maps;
	pk = cp_parameters(par, 4);
	ft_memset(pk, 0, 4);
	index_r = cr_index_elem(elem[4], elem[1]);
	maps[elem[1]] = putfig(area[elem[1]], maps[elem[0]], elem[3], pk);
	while (1)
	{
		if ((maps[elem[1]] = new_position_fig(maps, area, elem, pk)))
		{
			if ((ft_backtracking(k, index_r, elem, pk)))
				return (1);
		}
		else
			break ;
	}
	return (0);
}
