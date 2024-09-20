/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:46:15 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/18 06:30:50 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_north_texture(const char *line)
{
	return (ft_starts_with(line, "NO"));
}

bool	is_east_texture(const char *line)
{
	return (ft_starts_with(line, "EA"));
}

bool	is_south_texture(const char *line)
{
	return (ft_starts_with(line, "SO"));
}

bool	is_west_texture(const char *line)
{
	return (ft_starts_with(line, "WE"));
}

bool	is_sprite_texture(const char *line)
{
	return (ft_starts_with(line, "S"));
}
