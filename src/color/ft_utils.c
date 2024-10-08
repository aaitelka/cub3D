/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:48:22 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/24 12:24:18 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_ceiling_color(const char *line)
{
	return (ft_starts_with(line, "C"));
}

bool	is_floor_color(const char *line)
{
	return (ft_starts_with(line, "F"));
}

int	get_rgb(int r, int g, int b, int a)
{
	    return (a << 24 | r << 16 | g << 8 | b);
}
