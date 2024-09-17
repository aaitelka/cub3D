/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 07:01:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/17 10:04:31 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

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
