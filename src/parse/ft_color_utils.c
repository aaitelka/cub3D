/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:49:27 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/17 08:33:57 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	get_rgb(int r, int g, int b, int a)
{
	    return (a << 24 | r << 16 | g << 8 | b);
}

/**
 * @brief Check if the color is valid
 * @param c The color to check
 * @return true if the color is valid, false otherwise
*/
inline bool	is_valid_color(const int c)
{
	return (c >= 0 && c <= UCHAR_MAX);
}

/**
 * @brief Check if the line is a color
 * @param line The line to check
 * @return true if the line is a color, false otherwise
*/
inline bool	is_color(const char *line)
{
	if (!ft_strncmp(line, "C ", 1) || !ft_strncmp(line, "F ", 1) )
		return (true);
	return (false);
}
