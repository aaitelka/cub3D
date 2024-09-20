/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:04 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/20 08:30:45 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_parse(t_cub3d *cube, char *line)
{
	static int		i = 1;
	char			*str;

	if (i <= 6)
	{
		str = ft_strtrim(line, "\t ");
		free(line);
	}
	if (is_null(str) || is_newline(str))
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
