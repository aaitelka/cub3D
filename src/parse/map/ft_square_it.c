/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_it.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:56:01 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/07 10:18:55 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/**
 * @brief Fill the row with spaces and the map content
 * @param row The row to fill
 * @param size The size of the row
 * @return The filled row
*/
static char	*fill_row(char *row, int size)
{
	char			*filled;
	int				index;

	if (!row)
		return (NULL);
	index = -1;
	filled = ft_calloc(size + 1, sizeof(char));
	if (filled == NULL)
		return (NULL);
	ft_memset(filled, ' ', size - 1);
	while (row[++index])
		filled[index] = row[index];
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

	row = -1;
	squared = ft_calloc(map->size + 1, sizeof(char *));
	if (squared == NULL)
	{
		ft_error("malloc", "failed to allocate memory");
		return ;
	}
	squared[map->size] = NULL;
	printf("\n");
	while (map->_2d[++row])
	{
		squared[row] = fill_row(map->_2d[row], map->longest);
		if (squared[row] == NULL)
			break ;
		printf("%s\n", squared[row]);
		free(map->_2d[row]);
	}
	free(map->_2d);
	map->_2d = NULL;
	map->_2d = squared;
}
