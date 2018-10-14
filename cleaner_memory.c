/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:06:02 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/01 18:47:45 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_memory(int **mass, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(mass[i]);
		mass[i] = NULL;
		i++;
	}
	free(mass);
	mass = NULL;
}

void	free_memory_all(int ***memory, int size, int size_mass)
{
	int i;

	i = 0;
	while (i >= size)
	{
		clear_memory(memory[i], size_mass);
		i++;
	}
	free(memory);
	memory = NULL;
}
