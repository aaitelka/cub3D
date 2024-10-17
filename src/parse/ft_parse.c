/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:04 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/17 17:10:20 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	materials_inited(t_map *map)
{
	return (textures_inited(map) == TXTRS_SZ && colors_inited(map) == CLRS_SZ);
}

int	ft_parse(t_cube *cube, char *line)
{
	static int		i = 1;
	char			*str;

	if (i <= 6)
		str = ft_strtrim(line, " \t");
	if (is_texture(str) && i++)
		return (ft_parse_texture(cube, str));
	else if (is_color(str) && i++)
		return (free(str), ft_parse_color(cube, str));
	else if (is_map(*str) && i > 6)
	{
		if (cube->map.longest < (int)ft_strlen(str))
			cube->map.longest = ft_strlen(str);
		cube->map.size++;
		cube->ismap = true;
		cube->map.content = ft_strdup(line);
	}
	else
		return (ft_error(str, "invalid line"));
	return (free(str), SUCCESS);
}
