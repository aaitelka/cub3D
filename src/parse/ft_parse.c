/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:04 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/15 14:58:46 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	materials_inited(t_map *map)
{
	return (textures_inited(map) == TXTRS_SZ && colors_inited(map) == CLRS_SZ);
}

int	ft_parse(t_cub3d *cube, char *line)
{
	static int		i = 1;
	char			*str;

	if (!materials_inited(&cube->map))
	{
		str = ft_strtrim(line, "\t ");
		free(line);
	}
	if (is_null(*str) || is_newline(*str))
		return (free(str), 0);
	if (is_texture(str) && i++)
		return ft_parse_texture(cube, str);
	else if (is_color(str) && i++)
		return ft_parse_color(cube, str);
	else if (is_map(*str) && i > 6)
	{
		if (cube->map.longest < (int)ft_strlen(str))
			cube->map.longest = ft_strlen(str);
		cube->map.size++;
		cube->ismap = true;
		cube->map.content = ft_strdup(line);
	}
	else
	{
		ft_error(str, "invalid line");
		return -1;
	}
	return 0;
}
