/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:16:44 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/20 09:20:39 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/**
 * @brief Check if the character is 'E'
 * @param c The character to check
 * 		@return true if the character is 'E', false otherwise
*/
inline bool is_east(const char c)
{
	return (c == 'E');
}

/**
 * @brief Check if the character is 'N'
 * @param c The character to check
 * @return true if the character is 'N', false otherwise
*/
inline bool is_north(const char c)
{
	return (c == 'N');
}

/**
 * @brief Check if the character is 'S'
 * @param c The character to check
 * @return true if the character is 'S', false otherwise
*/
inline bool is_south(const char c)
{
	return (c == 'S');
}

/**
 * @brief Check if the character is 'W'
 * @param c The character to check
 * @return true if the character is 'W', false otherwise
*/
inline bool is_west(const char c)
{
	return (c == 'W');
}
