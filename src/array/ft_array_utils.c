/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:31:27 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/17 13:27:47 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/**
 * @brief Get the size of the array
 * @param array The array to get the size of
 * @return The size of the array
 */
size_t	ft_array_size(char **array)
{
	size_t			size;

	if (!array)
		return (0);
	size = -1;
	while (array[++size])
		;
	return (size);
}

/**
 * @brief Clear the array of strings
 * @param array The array to clear
 * @param size The size of the array
*/
void	ft_clear_array(char **array, int size)
{
	int				index;

	index = 0;
	if (!array || !array[index] || size == 0)
		return ;
	while (index < size)
	{
		if (array[index] != NULL)
			free(array[index]);
		index++;
	}
	free(array);
}
