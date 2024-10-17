/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:34:21 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/17 09:09:25 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_duplicate_texture(const char *line)
{
	if (ft_strncmp(line, "NO", 2) == SUCCESS)
		return (ft_error("NO", "texture already exists"));
	else if (ft_strncmp(line, "EA", 2) == SUCCESS)
		return (ft_error("EA", "texture already exists"));
	else if (ft_strncmp(line, "SO", 2) == SUCCESS)
		return (ft_error("SO", "texture already exists"));
	else if (ft_strncmp(line, "WE", 2) == SUCCESS)
		return (ft_error("WE", "texture already exists"));
	return (SUCCESS);
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
		return (NULL);
	mlx_delete_texture(texture);
	return (image);
}

int	ft_parse_texture(t_cube *cube, char *line)
{
	char			*texture;
	mlx_image_t		*image;

	texture = ft_strtrim(line + 2, " \t\n");
	if (!texture)
		return (free(line), ft_error(line, "failed trim line"));
	image = ft_load_image(cube->mlx, texture);
	if (!image)
		return (free(texture), free(line), ft_error(texture, "failed to load image"));
	if (!ft_strncmp(line, "NO", 2) && !cube->map.textures[NO])
		cube->map.textures[NO] = image;
	else if (!ft_strncmp(line, "EA", 2) && !cube->map.textures[EA])
		cube->map.textures[EA] = image;
	else if (!ft_strncmp(line, "SO", 2) && !cube->map.textures[SO])
		cube->map.textures[SO] = image;
	else if (!ft_strncmp(line, "WE", 2) && !cube->map.textures[WE])
		cube->map.textures[WE] = image;
	else if (check_duplicate_texture(line) != SUCCESS)
		return (free(texture), free(line), FAILED);
	return (free(texture), free(line), SUCCESS);
}
