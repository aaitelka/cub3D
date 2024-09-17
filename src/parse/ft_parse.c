/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:04 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/17 10:04:31 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	ft_parse(t_cube3d *cube, char *line)
{
	static int		i = 1;
	char			*str;

	str = ft_strtrim(line, "\t \n");
	free(line);
	if (is_null(str))
		return (free(str));
	if (is_texture(str))
		ft_add_texture(cube, str);
	else if (is_color(str))
		ft_add_color(cube, str);
	else if (is_map(str))
		ft_add_map(cube, str);
	else
	{
		ft_error(str, "invalid line");
		free(str);
		exit(EXIT_FAILURE);
	}
	free(str);
}
