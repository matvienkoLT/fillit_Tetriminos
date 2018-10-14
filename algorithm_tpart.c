/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm-tpart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:58:40 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/04 16:15:16 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**check_next_element(int **ptr_table, int **table_n, int size, int *c)
{
	int		**table_des;
	int		i[3];
	t_par	k;

	ft_memset(i, 0, (sizeof(int) * 3));
	table_des = ft_cpymemtable(ptr_table, size);
	i[2] = size;
	c[2] = empty_case_begin(table_n[0]);
	k.table_des = table_des;
	k.ptr_table = ptr_table;
	if (check_empty_case(table_des, size, &c[1], &c[0]))
		return (check_next_elem_frpart(k, c, table_n, i));
	else
	{
		clear_memory(table_des, size);
		return (NULL);
	}
	return (table_des);
}

int		**check_next_elem_frpart(t_par k, int *c, int **tn, int *i)
{
	int j;

	while (i[0] < i[2])
	{
		while (i[1] < i[2])
		{
			if (tn[i[0]][i[1]] > 0)
			{
				j = i[1] + c[1] - c[2];
				if (i[0] + c[0] < i[2] && (j < i[2] && j >= 0))
				{
					if (k.table_des[i[0] + c[0]][i[1] + c[1] - c[2]] > 0)
						return (check_next_elem_spart(k, c, tn, i));
				}
				else
					return (check_next_elem_tpart(k, c, tn, i));
				if (j < i[2] && i[0] + c[0] < i[2])
					k.table_des[i[0] + c[0]][j] = tn[i[0]][i[1]];
			}
			i[1]++;
		}
		i[0]++;
		i[1] = 0;
	}
	return (k.table_des);
}

int		**check_next_elem_spart(t_par k, int *cord, int **tn, int *i)
{
	check_next_elem_fpart(k.table_des, cord, i);
	if (!(k.table_des = check_next_element(k.ptr_table, tn, i[2], cord)))
		return (NULL);
	return (k.table_des);
}

int		**check_next_elem_tpart(t_par k, int *cord, int **tn, int *i)
{
	cord = check_overflow_massive(cord, i[2], i[1] + cord[1] - cord[2]);
	clear_memory(k.table_des, i[2]);
	if (!(k.table_des = check_next_element(k.ptr_table, tn, i[2], cord)))
		return (NULL);
	return (k.table_des);
}

void	check_next_elem_fpart(int **table_des, int *cord, int *i)
{
	cord[3] = i[1] + cord[1] - cord[2];
	cord = check_overflow_massive(cord, i[2], i[1] + cord[1] - cord[2]);
	clear_memory(table_des, i[2]);
}
