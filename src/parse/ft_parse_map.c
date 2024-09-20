/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:40:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/20 08:37:10 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	check_valid_chars(t_point point, const char *line)
{
	char			*alien;
	int				index; 

	alien = NULL;
	index = 0;
	while (line[index])
	{
		if (line[ft_strlen(line) - 1] == '\n')
		{
			ft_error("\\n", "map has new line");
			printf("\t^  ~~~~~~~~~~~~~~~~~~~~~~~\n");
			exit(EMHASNL);
		}
		if (!valid_char(line[index]))
		{
			alien = ft_substr(line, index, 1);
			if (ft_strcmp(alien, "\t") == 0)
			{
				ft_error("\\t", "map contains tab");
			printf("\t^  ~~~~~~~~~~~~~~~~~~~~~~~\n");
				return ;
			}
			ft_error(alien, "invalid character in map");
			printf("\t^  ~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("in row[%d] column[%d] charachter %c not recognized\n", \
					point.y, index + 1, line[index]);
			free(alien);
			exit(EXIT_FAILURE);
		}
		index++;
	}
}

// bool	is_all_spaces(char **map2d)
// {
// 	int				index;
// 	int				j;

// 	index = 0;
// 	while (map2d[index])
// 	{
// 		j = 0;
// 		while (map2d[index][j])
// 		{
// 			if (map2d[index][j] != ' ' || map2d[index][j] != '\n')
// 				return (false);
// 			j++;
// 		}
// 		index++;
// 	}
// 	return (true);
// }

static char	*ft_fill_row(t_map *map, int *row)
{
	char			*line;
	int				col;

	col = 0;
	line = ft_calloc(map->longest + 1, sizeof(char));
	ft_memset(line, ' ', map->longest);
	while (map->_2d[*row][col])
	{
		if (line[col])
			line[col] = map->_2d[*row][col];
		col++;
	}
	return (line);
}

static void	ft_square_it(t_map *map)
{
	char			**squared;
	int				row;

	row = 0;
	squared = ft_calloc(map->size + 1, sizeof(char *));
	squared[map->size] = NULL;
	while (row < map->size)
	{
		squared[row] = ft_fill_row(map, &row);
		free(map->_2d[row]);
		printf("|%s\n", squared[row]);
		row++;
	}
	free(map->_2d);
	map->_2d = squared;
}

bool	is_mapopen(t_map *map)
{
	int				row;
	int				col;
	char			*line;

	row = 0;
	while (map->_2d[row])
	{
		col = 0;
		while (map->_2d[row][col])
		{
			if (col + 1 < map->longest && (is_zero(map->_2d[row][col + 1]) && is_space(map->_2d[row][col]) || is_space(map->_2d[row][col + 1]) && is_zero(map->_2d[row][col])))
			{
				printf("map is not closed in row[%d] column[%d]\n", row+1, col+1);
				// ft_error("map", "map is not closed");
				exit(EXIT_FAILURE);
			}
			if (row + 1 < map->size && (is_zero(map->_2d[row + 1][col]) && is_space(map->_2d[row][col]) || is_space(map->_2d[row + 1][col]) && is_zero(map->_2d[row][col])))
			{
				printf("map is not closed in row[%d] column[%d]\n", row+1, col+1);
				// ft_error("map", "map is not closed");
				exit(EXIT_FAILURE);
			}
			if (col + 1 < map->longest && (is_player(map->_2d[row][col + 1]) && is_space(map->_2d[row][col]) || is_space(map->_2d[row][col + 1]) && is_player(map->_2d[row][col])))
			{
				printf("map is not closed in row[%d] column[%d]\n", row+1, col+1);
				// ft_error("map", "map is not closed");
				exit(EXIT_FAILURE);
			}
			if (row + 1 < map->size && (is_player(map->_2d[row + 1][col]) && is_space(map->_2d[row][col]) || is_space(map->_2d[row + 1][col]) && is_player(map->_2d[row][col])))
			{
				printf("map is not closed in row[%d] column[%d]\n", row+1, col+1);
				// ft_error("map", "map is not closed");
				exit(EXIT_FAILURE);
			}
			col++;
		}
		row++;
	}
	return (true);
}


bool	is_blank(const char *line)
{
	int				index;

	index = 0;
	while (line[index])
	{
		if (line[index] != ' ' && line[index] != '\n')
			return (false);
		index++;
	}
	return (true);
}

void	ft_parse_map(t_cub3d *cube)
{
	if (!cube->map.content)
	{
		ft_error("map", "no map found");
		exit(EXIT_FAILURE);
	}
	if (is_blank(cube->map.content))
	{
		ft_error("map", "has only spaces");
		exit(EXIT_FAILURE);
	}
	check_valid_chars(cube->map.point, cube->map.content);
	
	if (cube->map.size < 3 || cube->map.longest < 3)
		ft_error("map", "ma map ma ta l3ba hadi\n");
	
	 cube->map._2d = ft_split(cube->map.content, '\n');
	if (cube->map._2d == NULL)
	{
		ft_error("map", "failed to split map");
		exit(EXIT_FAILURE);
	}
	ft_square_it(&cube->map);
	is_mapopen(&cube->map);
}
