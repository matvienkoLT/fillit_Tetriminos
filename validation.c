/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:47:28 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/05/04 18:37:04 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid_symbols(char *str)
{
	while (*str && ((*str == '.') || (*str == '#') || (*str == '\n')))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int		ft_check_endline(char *str, int i)
{
	int		counter;

	counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '.' || str[i] == '#')
		{
			counter++;
			i++;
		}
		if (str[i] == '\n')
		{
			counter++;
			if ((counter % 5) == 0 || (counter % 21) == 0)
				i++;
			else if ((counter % 5) != 0 || (counter % 21) != 0)
				return (0);
			if (counter == 21)
				counter = 0;
		}
	}
	return (1);
}

int		ft_valid_symbols_number(char *str)
{
	int		tetriminos;

	tetriminos = ft_tetri_counter(str);
	if ((ft_chrcnt(str, '.') == (tetriminos * 12)) &&
		(ft_chrcnt(str, '#') == (tetriminos * 4)) &&
		(ft_chrcnt(str, '\n') == ((tetriminos * 4) + (tetriminos - 1))))
		return (1);
	return (0);
}

int		ft_connect(char *str, int connect, int i)
{
	if (str[i - 5] == '#' && (i % 21) > 3)
		connect++;
	if (str[i + 1] == '#')
		connect++;
	if (str[i + 5] == '#' && (i % 21) < 16)
		connect++;
	if (str[i - 1] == '#')
		connect++;
	return (connect);
}

int		ft_tetri_checker(char *str, int i, int connect, int cnt)
{
	while (str[i] != '\0')
	{
		while (((i + 1) % 21 != 0) && (str[i] == '.' || str[i] == '\n'))
			i++;
		if (((i + 1) % 21 != 0) && str[i] == '#' && cnt++ != 4)
			connect = ft_connect(str, connect, i);
		if ((i + 1) % 21 == 0)
		{
			if ((cnt == 4) && (connect != 6 && connect != 8))
				return (0);
			else if ((cnt == 4) && (connect == 6 || connect == 8))
			{
				i++;
				if (!(ft_tetri_checker(str, i, 0, 0)))
					return (0);
			}
		}
		i++;
	}
	return (1);
}
