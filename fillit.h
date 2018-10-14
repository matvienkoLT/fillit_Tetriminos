/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:08:59 by mzhovnir          #+#    #+#             */
/*   Updated: 2018/05/04 16:19:41 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define BUFFER_SIZE	566

typedef	struct	s_par
{
	int	**table_des;
	int	**ptr_table;
}				t_par;

typedef	struct	s_arr
{
	int	***maps;
	int	***area;
}				t_arr;

void			error(void);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			print_table(int **table, int size);
int				ft_chrcnt(const char *str, char c);
int				ft_tetri_counter(char *str);
int				ft_checkmap(char *str);
int				ft_valid_symbols(char *str);
int				ft_check_endline(char *str, int i);
int				ft_valid_symbols_number(char *str);
int				ft_connect(char *str, int connect, int i);
int				ft_tetri_checker(char *str, int i, int connect, int cnt);
void			ft_fill_array(char *str, char ***array);
char			***ft_str_to_array(char *str, int tetri_number);
void			analysing_d(int num_fig, char *str);
int				ft_research(char ***fig, int s_m, int num_fig, int *pk);
int				size_area(int quantity_figure);
int				**define_memory_area(int square_size);
int				***areas_create(char ***fig, int size_mass, int fig_num);
int				**find_elem_on_map(char **elem, int **tb, int size, int cfig);
int				**ft_cpymemtable(int **table, int size);
int				position_slice_y(int n, char **elem);
int				position_slice_x(int n, char **elem);
int				empty_case_begin(int *ptr_table);
int				check_empty_case(int **table, int size_tab, int *x, int *y);
int				*create_index_array(int cfig);
int				*cp_parameters(int *elem, int size);
int				*cr_index_without_elem(int *src, int size, int elem);
int				**new_position_fig(int ***maps, int ***area, int *el, int *c);
int				*cr_index_elem(int size, int index);
int				*check_overflow_massive(int *cord, int size_tab, int pos_slice);
int				last_element(int ***maps);
void			clear_memory(int **mass, int size);
int				**putfig(int **area, int **maps, int size_tab, int *cord);
int				ft_backtrack_check(t_arr k, int *index_r, int *elem, int *c_n);
int				ft_backtracking(t_arr k, int *i_a, int *parameters, int *cord);
int				put_new_position_fig(int ***area, int ***maps, int *el, int *p);
void			initialization(int *elem, int size_tab, int num_fig);
int				***putting_on_figur_tpart(t_arr k, int *elem, int *pk);
int				***putting_on_figur(int ***area, int s_t, int num_fig, int *pk);
int				**check_next_element(int **p_t, int **t_n, int size, int *c);
int				**check_next_elem_frpart(t_par k, int *c, int **tn, int *i);
int				**check_next_elem_spart(t_par k, int *cord, int **tn, int *i);
int				**check_next_elem_tpart(t_par k, int *cord, int **tn, int *i);
void			check_next_elem_fpart(int **table_des, int *cord, int *i);
void			free_memory_all(int ***memory, int size, int size_mass);
void			*ft_memset(void *str, int c, size_t n);
#endif
