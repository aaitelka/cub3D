/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:34:21 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/21 21:09:40 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_duplicate_texture(const char *line)
{
	if (ft_strncmp(line, "NO", 2) == SUCCESS)
		return (ft_error("NO", ETXAE));
	else if (ft_strncmp(line, "EA", 2) == SUCCESS)
		return (ft_error("EA", ETXAE));
	else if (ft_strncmp(line, "SO", 2) == SUCCESS)
		return (ft_error("SO", ETXAE));
	else if (ft_strncmp(line, "WE", 2) == SUCCESS)
		return (ft_error("WE", ETXAE));
	return (SUCCESS);
}

static int	get_begining(char *line)
{
	int				index;

	index = 0;
	while (line[index])
	{
		if (line[index] != ' ')
			return (index);
		index++;
	}
	return (index);
}

static mlx_image_t	*ft_load_image(mlx_t *mlx, char *str)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	str += get_begining(str);
	str[ft_strlen(str) - 1] = '\0';
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
	mlx_image_t		*image;
	char			*texture;

	texture = line + 3;
	image = ft_load_image(cube->mlx, texture);
	if (!image)
		return (ft_error(line, EIFAIL));
	if (!ft_strncmp(line, "NO", 2) && !cube->map.textures[NO])
		cube->map.textures[NO] = image;
	else if (!ft_strncmp(line, "EA", 2) && !cube->map.textures[EA])
		cube->map.textures[EA] = image;
	else if (!ft_strncmp(line, "SO", 2) && !cube->map.textures[SO])
		cube->map.textures[SO] = image;
	else if (!ft_strncmp(line, "WE", 2) && !cube->map.textures[WE])
		cube->map.textures[WE] = image;
	else if (check_duplicate_texture(line) != SUCCESS)
		return (FAILED);
	return (SUCCESS);
}
