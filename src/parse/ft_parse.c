/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:04 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/26 18:41:03 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// static void	ft_readmap(t_cub3d *cube, char *line)
// {
// 	char			*joined;

// 	joined = NULL;
// 	if (line[0] == '\n')
// 	{
// 		ft_error("\\n", "has new linee");
// 		printf("\t^  ~~~~~~~~~~~~~~~~~~~~~~~\n");
// 		exit(EMHASNL);
// 	}
// 	cube->map.size++;
// 	joined = ft_strjoin(cube->map.content, line);
// 	free(cube->map.content);
// 	cube->map.content = joined;
// 	free(line);
// }

bool	materials_inited(t_map *map)
{
	return (textures_initialized(map) == TEXTURES_SIZE
			&& colors_initialized(map) == COLORS_SIZE);
}

void	ft_parse(t_cub3d *cube, char *line)
{
	static int		i = 1;
	char			*str;

	if (i <= 6)
	{
		str = ft_strtrim(line, "\t ");
		free(line);
	}
	if (is_null(*str) || is_newline(*str))
		return (free(str));
	if (is_texture(str) && i++)
		ft_parse_texture(cube, str);
	else if (is_color(str) && i++)
		ft_parse_color(cube, str);
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
		free(str);
		exit(EXIT_FAILURE);
	}
	free(str);
}
