/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:44:56 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/05/04 18:54:11 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		ft_tetri_counter(char *str)
{
	int		tetriminos;
	int		lines_number;

	lines_number = ft_chrcnt(str, '\n');
	tetriminos = (lines_number + 1) / 5;
	if (tetriminos > 26)
		error();
	return (tetriminos);
}

int		ft_checkmap(char *str)
{
	int		lines_number;

	if (!(*str))
		error();
	lines_number = ft_chrcnt(str, '\n');
	if (ft_valid_symbols(str))
		if (ft_check_endline(str, 0))
			if (ft_valid_symbols_number(str))
				if (ft_tetri_checker(str, 0, 0, 0))
					return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		read_bytes;
	char	*buffer;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		exit(1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error();
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if ((read_bytes = read(fd, buffer, BUFFER_SIZE + 1)) < 0)
		error();
	buffer[read_bytes] = '\0';
	if (!(ft_checkmap(buffer)))
		error();
	if (close(fd) != 0)
	{
		error();
		exit(1);
	}
	analysing_d(ft_tetri_counter(buffer), buffer);
	return (0);
}

void	analysing_d(int num_fig, char *str)
{
	char	***figures;
	int		pk[4];
	int		size_mass;
	int		size_corrector;

	size_corrector = 0;
	ft_memset(pk, 0, sizeof(int) * 4);
	figures = ft_str_to_array(str, num_fig);
	size_mass = size_area(num_fig);
	while (1)
	{
		if (ft_research(figures, size_mass + size_corrector, num_fig, pk))
			break ;
		else
		{
			size_corrector++;
			ft_memset(pk, 0, 4 * sizeof(int));
		}
	}
}
