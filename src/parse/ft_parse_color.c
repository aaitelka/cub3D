/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:24:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/15 14:47:39 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	get_color(char **colors)
{
	int				rgb;
	int				r;
	int				g;
	int				b;

	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (!is_valid_color(r) || !is_valid_color(g) || !is_valid_color(b))
	{
		ft_clear_array(colors, ft_array_size(colors));
		ft_error("color", "color has to be in the range [0, 255]");
		return (-1);
	}
	rgb = get_rgb(r, g, b, 0);
	ft_clear_array(colors, ft_array_size(colors));
	return (rgb);
}

static bool	is_valid_rgb(char *color)
{
	int				index;
	int				comma;
	bool			is_valid;

	if (!color)
		return (false);
	index = 0;
	comma = 0;
	is_valid = true;
	while (color[index])
	{
		if (ft_isdigit(color[index]) || (is_space(color[index]) || (color[index] == '\t')))
			;
		else if (color[index] == ',')
			comma++;
		else
			is_valid = false;
		index++;
	}
	if (!is_valid || comma != 2)
		return (false);
	return (true);
}

/**
 * @brief Parse the color from the line
 * @param cube The game structure
 * @param line The line to parse
 */
int	ft_parse_color(t_cub3d *cube, char *line)
{
	char			**colors;
	char			*color;
	size_t			size;
	bool			valid;

	color = ft_strtrim(line + 1, " \t\n");
	valid = is_valid_rgb(color);
	colors = ft_split(color, ',');
	size = ft_array_size(colors);
	if (!valid || !colors || size != 3)
	{
		free(color);
		ft_clear_array(colors, ft_array_size(colors));
		return ft_error(line, "color has to be in the format: R,G,B");
	}
	if (is_floor(line) && cube->map.colors[F] == 0)
		cube->map.colors[F] = get_color(colors);
	else if (is_ceiling(line) && cube->map.colors[C] == 0)
		cube->map.colors[C] = get_color(colors);
	else
	{
		ft_clear_array(colors, ft_array_size(colors));
		ft_error(line, "color already exists");
	}
	free(color);
	return 0;
}
