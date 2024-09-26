/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_it.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:56:01 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/26 15:28:11 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/**
 * @brief Fill the row with spaces and the map content
 * @param map The map to fill
 * @param row The row to fill
 * @return The filled row
*/
static char	*fill_row(char *row, int size)
{
	char			*filled;
	int				index;

	if (!row)
		return (NULL);
	index = -1;
	filled = ft_calloc(size, sizeof(char));
	if (filled == NULL)
		return (NULL);
	ft_memset(filled, '_', size - 1);
	while (row[++index])
	{
		if (filled[index])
			filled[index] = row[index];
	}
	return (filled);
}

/**
 * @brief Square the map
 * @param map The map to square
*/
void	square_it(t_map *map)
{
	char			**squared;
	int				row;

	row = 0;
	squared = ft_calloc(map->size + 1, sizeof(char *));
	if (squared == NULL)
	{
		ft_error("malloc", "failed to allocate memory");
		return ;
	}
	while (row < map->size)
	{
		squared[row] = fill_row(map->_2d[row], map->longest);
		if (squared[row] == NULL)
			break ;
		printf("\n%s", squared[row]);
		free(map->_2d[row]);
		row++;
	}
	free(map->_2d);
	squared[map->size] = NULL;
	map->_2d = squared;
}
