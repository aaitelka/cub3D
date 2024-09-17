/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:24:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/17 10:04:31 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	check_duplicate_color(const char *str)
{
	if (is_floor_color(str))
		ft_error("F", "color already exists");
	else if (is_ceiling_color(str))
		ft_error("C", "color already exists");
	exit(EXIT_FAILURE);
}

static int	get_color(t_cube3d *cube, char *str)
{
	int				r;
	int				g;
	int				b;
	int				rgb;
	char			**colors;

	colors = ft_split(str, ',');
	if (colors == NULL)
	{
		free(str);
		ft_error(str, "failed to split colors");
		return (FAILED);
	}
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_clear(colors, 3);
		ft_error(str, "color has to be in the range [0, 255]");
		return (FAILED);
	}
	rgb = get_rgb(r, g, b);
	ft_clear(colors, 3);
	return (rgb);
}

static void	check_color(char *color)
{
	int				i;
	int				comma;
	bool			is_valid;

	comma = 0;
	i = 0;
	is_valid = true;
	if (ft_starts_with(color, ",") || ft_ends_with(color, ","))
		is_valid = false;
	while (is_valid && color[i])
	{
		if (ft_isdigit(color[i]) || (color[i] == 32 || (color[i] == 9)))
			;
		else if (color[i] == ',')
			comma++;
		else
			is_valid = false;
		i++;
	}
	if (!is_valid || comma != 2)
	{
		ft_error(color, "color has to be in the format: R,G,B");
		exit(EXIT_FAILURE);
	}
}

void	ft_add_color(t_cube3d *cube, char *str)
{
	char			*color;

	color = ft_strtrim(str + 1, " ");
	check_color(color);
	if (is_floor_color(str) && cube->map.colors[F] == 0)
		cube->map.colors[F] = get_color(cube, color);
	else if (is_ceiling_color(str) && cube->map.colors[C] == 0)
		cube->map.colors[C] = get_color(cube, color);
	else
		check_duplicate_color(str);
	free(color);
}
