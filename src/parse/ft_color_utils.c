/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:49:27 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/20 10:51:09 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
	if (ft_starts_with(line, "F ") || ft_starts_with(line, "C "))
		return (true);
	return (false);
}
