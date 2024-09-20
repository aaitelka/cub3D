/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:34:21 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/19 14:32:15 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	check_duplicate_texture(const char *str)
{
	if (is_north_texture(str))
		ft_error("NO", "texture already exists");
	else if (is_east_texture(str))
		ft_error("EA", "texture already exists");
	else if (is_south_texture(str))
		ft_error("SO", "texture already exists");
	else if (is_west_texture(str))
		ft_error("WE", "texture already exists");
	exit(EXIT_FAILURE);
}

static mlx_image_t	*ft_load_image(mlx_t *mlx, const char *str)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(str);
	if (texture == NULL)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	if (image == NULL)
		exit(EXIT_FAILURE);
	mlx_delete_texture(texture);
	return (image);
}

void	ft_parse_texture(t_cub3d *cube, char *line)
{
	char			*texture;
	mlx_image_t		*image;

	texture = ft_strtrim(line + 2, " \t\n");
	image = ft_load_image(cube->mlx, texture);
	if (image == NULL)
	{
		ft_error(texture, "failed to load image");
		exit(EXIT_FAILURE);
	}
	if (is_north_texture(line) && cube->map.textures[NO] == NULL)
		cube->map.textures[NO] = image;
	else if (is_east_texture(line) && cube->map.textures[EA] == NULL)
		cube->map.textures[EA] = image;
	else if (is_south_texture(line) && cube->map.textures[SO] == NULL)
		cube->map.textures[SO] = image;
	else if (is_west_texture(line) && cube->map.textures[WE] == NULL)
		cube->map.textures[WE] = image;
	else
		(free(texture), check_duplicate_texture(line));
	free(texture);
}
