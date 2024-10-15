/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:46:15 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/07 08:58:07 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_north_texture(const char *line)
{
	return (ft_strncmp(line, "NO", 2) == SUCCESS);
}

bool	is_east_texture(const char *line)
{
	return (ft_strncmp(line, "EA", 2) == SUCCESS);
}

bool	is_south_texture(const char *line)
{
	return (ft_strncmp(line, "SO", 2) == SUCCESS);
}

bool	is_west_texture(const char *line)
{
	return (ft_strncmp(line, "WE", 2) == SUCCESS);
}
