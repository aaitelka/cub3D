/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 07:48:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/27 09:30:27 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_draw_circle(t_cub3d *cube, uint32_t width, uint32_t height)
{
	mlx_image_t	*img;

	img = mlx_new_image(cube->mlx, width, height);
	if (!img || (mlx_image_to_window(cube->mlx, img, 0, 0) < 0))
	{
		ft_error("mlx_image", "failed to create or display image");
		mlx_terminate(cube->mlx);
		exit(EXIT_FAILURE);
	}
	
	int index = 1920 / 2;
	while (++index < 1920 - 100)
	{
		int index2 = 1080 / 2;
		while (++index2 < 1080 - 100)
		{
			mlx_put_pixel(img, index, index2, 0xFEE56EFF);
		}
	}

}