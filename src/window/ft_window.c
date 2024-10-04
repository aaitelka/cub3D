/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:31:58 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/27 09:48:44 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_fill_window(t_cub3d *cube)
{
	mlx_image_t	*img;

	int width = 0;
	int height = 0;
	int index = -1;
	while (++index < cube->map.size)
	{
			img = mlx_new_image(cube->mlx, 60, 60);
			if (!img || (mlx_image_to_window(cube->mlx, img, width, height) < 0))
			{
				ft_error("mlx_image", "failed to create or display image");
				mlx_terminate(cube->mlx);
				exit(EXIT_FAILURE);
			}
		int index2 = -1;
		while (++index2 < cube->map.longest)
		{
			if (cube->map._2d[index][index2] == '1')
				mlx_put_pixel(img, index, index2, 0x3d414aff);
			else if (cube->map._2d[index][index2] == ' ')
				mlx_put_pixel(img, index, index2, 0xff6d67ff);
			else if (cube->map._2d[index][index2] == '0')
				mlx_put_pixel(img, index, index2, 0xb8c5cdff);
			height+= 60;
		}
		width += 60;
	}
}