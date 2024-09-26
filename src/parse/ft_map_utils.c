/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:14:00 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/26 16:13:21 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/**
 * @brief Check if the character is zero
 * @param c The character to check
 * @return true if the character is zero, false otherwise
*/
inline bool	is_zero(const char c)
{
	return (c == '0');
}

/**
 * @brief Check if the character is one
 * @param c The character to check
 * @return true if the character is one, false otherwise
*/
inline bool	is_wall(const char c)
{
	return (c == '1');
}

/**
 * @brief Check if the character is a space or one
 * @param c The character to check
 * @return true if the character is space or one, false otherwise
*/
inline bool	is_map(const char c)
{
	return (is_space(c)
			|| is_wall(c));
}

/**
 * @brief Check if the character is part of the player
 * @param c The character to check
 * @return true if the character is player, false otherwise
*/
inline bool	is_player(const char c)
{
	return (is_east(c)
			|| is_north(c)
			|| is_south(c)
			|| is_west(c));
}

/**
 * @brief Check if the character is a valid part of the map
 * @param c The character to check
 * @return true if the character is valid, false otherwise
*/
inline bool	valid_char(const char c)
{
	return (is_zero(c) 
			|| is_wall(c)
			|| is_space(c) 
			|| is_player(c)
			|| is_newline(c));
}
