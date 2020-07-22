/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 12:01:56 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/07/22 14:43:28 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strjoin_cub3d(char *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 2));
	if (!p)
	{
		free(s1);
		return (0);
	}
	while (s1[i])
	{
		p[i] = s1[i];
		i -= -1;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j -= -1;
	}
	free(s1);
	p[i + j] = '\n';
	p[i + j + 1] = '\0';
	return (p);
}

void		strjoin_map(char *line, t_parser *parser)
{
	if (!parser->map.begin)
	{
		parser->map.tmp = malloc(sizeof(char));
		if (!parser->map.tmp)
			return ;
		parser->map.tmp[0] = '\0';
	}
	parser->map.begin = 1;
	parser->map.tmp = ft_strjoin_cub3d(parser->map.tmp, line);
	if (!parser->map.tmp)
		return ;
}

void		make_array_map(t_map *map)
{
	int	i;

	i = 0;
	map->end = 1;
	map->array = ft_split(map->tmp, '\n');
	if (!map->array)
		return ;
	while (map->array[i])
	{
		if (map->width < ft_strlen_gnl(map->array[i]))
			map->width = ft_strlen_gnl(map->array[i]);
		i++;
	}
	map->height = i;
}
