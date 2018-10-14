/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:38:58 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/05/04 17:36:54 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill_array(char *str, char ***array)
{
	int		i[4];

	ft_memset(i, 0, (sizeof(int) * 4));
	while (str[i[0]] != '\0')
	{
		if (str[i[0]] != '\n')
		{
			array[i[1]][i[2]][i[3]] = str[i[0]];
			i[3]++;
		}
		else if (str[i[0]] == '\n')
		{
			i[3] = 0;
			if (i[2] < 4)
				i[2]++;
			else
			{
				i[2] = 0;
				i[3] = 0;
				i[1]++;
			}
		}
		i[0]++;
	}
}

char	***ft_str_to_array(char *str, int tetri_number)
{
	int		i;
	int		j;
	char	***array;

	i = 0;
	j = 0;
	if (!(array = (char ***)malloc(sizeof(char **) * tetri_number)))
		return (NULL);
	while (i < tetri_number)
	{
		if (!(array[i] = (char **)malloc(sizeof(char *) * 4)))
			return (NULL);
		while (j < 4)
		{
			if (!(array[i][j] = (char *)malloc(sizeof(char) * 4)))
				return (NULL);
			j++;
		}
		j = 0;
		i++;
	}
	ft_fill_array(str, array);
	return (array);
}

int		ft_research(char ***figures, int size_mass, int num_fig, int *pk)
{
	int ***area;
	int ***maps;

	if (!(area = areas_create(figures, size_mass, num_fig)))
		return (0);
	if ((maps = putting_on_figur(area, size_mass, num_fig, pk)))
	{
		print_table(maps[num_fig], size_mass);
		return (1);
	}
	return (0);
}
