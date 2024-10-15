/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:40:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/15 14:48:43 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	check_valid_chars(t_point *point, const char *line)
{
	char			*alien;
	int				index; 
	int				player;

	alien = NULL;
	index = 0;
	player = 0;
	while (line[index])
	{
		if (is_player(line[index]))
			player++;
		if (line[ft_strlen(line) - 1] == '\n')
		{
			ft_error("\\n", "map has new line");
			return ;
		}
		if (!valid_char(line[index]))
		{
			alien = ft_substr(line, index, 1);
			if (ft_strcmp(alien, "\t") == 0)
			{
				ft_error("\\t", "map contains tab");
				return ;
			}
			ft_error(alien, "invalid character in map");
			free(alien);
			return ;
		}
		index++;
	}
	if (player == 0)
		ft_error("player", "player not found");
	else if (player > 1)
		ft_error("player", "multiple players found");
}

bool	in_bounds(t_map *map, int row, int col)
{
	return (!col || col == map->longest - 1 || !row || row == map->size - 1);
}

bool	inside_space(t_map *map, int row, int col)
{
	return (is_space(map->_2d[row + 1][col])
			||	is_space(map->_2d[row - 1][col])
			||	is_space(map->_2d[row][col + 1])
			||	is_space(map->_2d[row][col - 1]));
}

static void	check_map(t_map *map)
{
	int				row;
	int				col;

	if (!map->_2d)
	{
		ft_error("map", "failed to split map");
		return ;
	}
	row = -1;
	while (map->_2d[++row])
	{
		col = -1;
		while (++col < map->longest)
		{
			if (is_zero(map->_2d[row][col]) || is_player(map->_2d[row][col]))
			{
				if (in_bounds(map, row, col) || inside_space(map, row, col))
				{
					set_error(&map->point, row, col, 1);
					break ;
				}
			}
		}
	}
}

int	ft_parse_map(t_cub3d *cube)
{
	if (!cube->map.content)
		return ft_error("map", "no map found hh");
	if (is_blank(cube->map.content))
		return ft_error("map", "has only spaces");
	if (cube->map.size < 3 || cube->map.longest < 3)
		return ft_error(cube->map.content, "ma map ma ta l3ba hadi\n");
	check_valid_chars(&cube->map.point, cube->map.content);
	cube->map._2d = ft_split(cube->map.content, '\n');
	if (cube->map._2d == NULL)
		return ft_error("map", "failed to split map");
	square_it(&cube->map);
	check_map(&cube->map);
	if (cube->map.point.err)
		printf("error in row[%d] col[%d] error code: %d\n", \
		cube->map.point.row, cube->map.point.col, cube->map.point.err );
	return 0;
}
