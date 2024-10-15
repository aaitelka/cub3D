/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:35:11 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/15 14:50:46 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_texture(const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == SUCCESS
		|| ft_strncmp(line, "EA ", 3) == SUCCESS
		|| ft_strncmp(line, "SO ", 3) == SUCCESS
		|| ft_strncmp(line, "WE ", 3) == SUCCESS)
		return (true);
	return (false);
}

t_colors	colors_inited(t_map *map)
{
	if (map->colors[F] < 0)
		return (F);
	else if (map->colors[C] < 0)
		return (C);
	return (CLRS_SZ);
}

t_directions	textures_inited(t_map *map)
{
	if (map->textures[NO] == NULL)
		return (NO);
	else if (map->textures[EA] == NULL)
		return (EA);
	else if (map->textures[SO] == NULL)
		return (SO);
	else if (map->textures[WE] == NULL)
		return (WE);
	return (TXTRS_SZ);
}
