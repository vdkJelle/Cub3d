/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 14:09:30 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/06/11 11:19:26 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "./ft_printf/printf.h"
#include "./minilibx-master/mlx.h"
#include "./minilibx-master/mlx_int.h"
#include <stdlib.h>

typedef struct		s_map
{
	int		begin;
	int		end;
	int		width;
	int		height;
	char	**array;
	char	*tmp;
}					t_map;

typedef struct		s_error
{
	int		seen_r;
	int		seen_no;
	int		seen_so;
	int		seen_we;
	int		seen_ea;
	int		seen_s;
	int		seen_c;
	int		seen_f;
}					t_error;

typedef struct		s_parser
{
	int		res_width;
	int		res_height;
	char	no_wall[50];
	char	so_wall[50];
	char	we_wall[50];
	char	ea_wall[50];
	char	obj_sprite[50];
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	t_error	error;
	t_map	map;
}					t_parser;

typedef struct		s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_data;

/*parser.c*/
int		parser(void);

/*initialize_struct.c*/
void	initialize_parser(t_parser *parser);

/*parser_utils.c*/
int		fill_parser(char *line, t_parser *parser);

/*error_handling.c*/
void	check_encounters(char *line, int i, t_parser *parser);
int		check_validity(t_parser *parser);
int		print_error(char *str);

/*map_handling.c*/
void	strjoin_map(char *line, t_parser *parser);
void	make_array_map(t_map *map);

/*floodfill.c*/
int		check_map(t_map *map);

/*my_mlx_pixel_put.c*/
void	my_mlx_pixel_put(t_data *data, int x, int u, int color);

#endif
