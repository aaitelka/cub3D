/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:24:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/17 17:08:55 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_duplicate_color(char *color)
{
	if (color[0] == 'C')
		return (ft_error(color, "ceiling already exists"));
	else if (color[0] == 'F')
		return (ft_error(color, "floor already exists"));
	return (SUCCESS);
}

static int len(char *str)
{
	int			index;
	int			size;

	size = 0;
	index = -1;
	while (str[++index])
	{
			if (!is_space(str[index]) && str[index] != '\t' && str[index])
					size++;
	}
	return (size);
}

static int	get_color(char **colors)
{
	int				rgb;
	int				r;
	int				g;
	int				b;

	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (!is_valid_color(r))
		return (ft_error(colors[0], "color has range [0, 255]"));
	else if (!is_valid_color(g))
		return (ft_error(colors[1], "color has range [0, 255]"));
	else if (!is_valid_color(b))
		return (ft_error(colors[2], "color has range [0, 255]"));
	rgb = get_rgb(r, g, b, 0);
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
		if (ft_isdigit(color[index]) || (is_space(color[index])) || (color[index] == '\t'))
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
int	ft_parse_color(t_cube *cube, char *line)
{
	char			**clrs;
	char			*color;
	size_t			size;
	bool			valid;

	color = ft_strtrim(line + 1, " \t\n");
	if (!color)
		return (ft_error(line, "failed trim color"));
	valid = is_valid_rgb(color);
	clrs = ft_split(color, ',');
	size = ft_array_size(clrs);
	if (!valid || !clrs || size != 3 || len(clrs[0]) > 3 || len(clrs[1]) > 3 || len(clrs[2]) > 3)
	{
		ft_clear_array(clrs, ft_array_size(clrs));
		return (free(color), ft_error(color, "should be R,G,B format"));
	}
	if (!ft_strncmp(line, "F ", 2) && cube->map.colors[F]  == -1)
		cube->map.colors[F] = get_color(clrs);
	else if (!ft_strncmp(line, "C ", 2) && cube->map.colors[C] == -1)
		cube->map.colors[C] = get_color(clrs);
	else if (check_duplicate_color(line) != SUCCESS)
		return (ft_clear_array(clrs, 3), free(color), FAILED);
	return (ft_clear_array(clrs, ft_array_size(clrs)), free(color), SUCCESS);
}
