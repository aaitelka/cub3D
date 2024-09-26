/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:35:11 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/23 13:41:48 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_texture(const char *line)
{
	if (ft_starts_with(line, "NO ") || ft_starts_with(line, "EA ")
		|| ft_starts_with(line, "SO ") || ft_starts_with(line, "WE "))
		return (true);
	return (false);
}

t_colors	colors_initialized(t_map *map)
{
	if (map->colors[F] < 0)
		return (F);
	else if (map->colors[C] < 0)
		return (C);
	return (COLORS_SIZE);
}

t_directions	textures_initialized(t_map *map)
{
	if (map->textures[NO] == NULL)
		return (NO);
	else if (map->textures[EA] == NULL)
		return (EA);
	else if (map->textures[SO] == NULL)
		return (SO);
	else if (map->textures[WE] == NULL)
		return (WE);
	return (TEXTURES_SIZE);
}
