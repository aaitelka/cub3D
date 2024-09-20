/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 07:01:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/19 07:51:34 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_clear(char **array, int size)
{
	int				index;

	index = 0;
	while (index < size)
	{
		if (array[index] != NULL)
			free(array[index]);
		index++;
	}
	free(array);
}

void	ft_destroy(t_cub3d *cube)
{
	printf("destroying cube\n");
}
