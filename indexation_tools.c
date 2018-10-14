/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:53:16 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/04 11:40:17 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*create_index_array(int cfig)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc((cfig + 1) * sizeof(int));
	while (i <= cfig)
	{
		array[i] = i;
		i++;
	}
	return (array);
}

int	*cp_parameters(int *elem, int size)
{
	int	*ptr_elem;
	int	i;

	i = 0;
	ptr_elem = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		ptr_elem[i] = elem[i];
		i++;
	}
	return (ptr_elem);
}

int	*cr_index_without_elem(int *src, int size, int elem)
{
	int i;
	int j;
	int *dest;

	i = 0;
	j = 0;
	dest = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		if (src[j] == elem)
			j++;
		else
		{
			dest[i] = src[j];
			j++;
			i++;
		}
	}
	return (dest);
}

int	**new_position_fig(int ***maps, int ***area, int *el, int *cord)
{
	cord = check_overflow_massive(cord, el[3], 0);
	if (!(maps[el[2] + 1] = putfig(area[el[1]], maps[el[0]], el[3], cord)))
		return (NULL);
	return (maps[el[2] + 1]);
}

int	*cr_index_elem(int size, int index)
{
	int i;
	int *dest;

	i = 0;
	if (!(dest = (int *)malloc(size * sizeof(int))))
		return (NULL);
	while (size-- > 0)
	{
		dest[i] = index;
		index++;
		i++;
	}
	return (dest);
}
