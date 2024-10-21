/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:04 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/21 20:14:21 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	ft_readmap(t_cube *cube, char *line)
{
	char			*joined;
	char			*newline;

	joined = NULL;
	if (is_newline(*line) && !cube->map.content)
		return (SUCCESS);
	if (is_newline(*line))
		return (ft_error("map", EMAPHNL));
	if (cube->map.longest < (int)ft_strlen(line))
		cube->map.longest = ft_strlen(line);
	cube->map.size++;
	joined = ft_strjoin(cube->map.content, line);
	if (!joined)
		return (ft_error("join", "maybe malloc failled in ft_strjoin"));
	free(cube->map.content);
	cube->map.content = joined;
	return (SUCCESS);
}

int	ft_parse(t_cube *cube, char *line)
{
	if (!materials_inited(&cube->map) && (is_newline(*line) || is_blank(line)))
		return (SUCCESS);
	if (is_texture(line))
		return (ft_parse_texture(cube, line));
	if (is_color(line))
		return (ft_parse_color(cube, line));
	if (materials_inited(&cube->map))
		return (ft_readmap(cube, line));
	return (ft_error(line, "invalid line"));
}
