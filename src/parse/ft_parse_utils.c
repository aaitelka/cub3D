/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:55:15 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/26 13:57:38 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/**
 * @brief Check if the character is '\0'
 * @param c The character to check
 * @return true if the character is zero, false otherwise
*/
inline bool	is_null(const char c)
{
	return (c == '\0');
}

/**
 * @brief Check if the character is a space
 * @param c The character to check
 * @return true if the character is space, false otherwise
*/
inline bool	is_space(const char c)
{
	return (c == ' ');
}

/**
 * @brief Check if the character is a newline
 * @param c The character to check
 * @return true if the character is newline, false otherwise
*/
inline bool	is_newline(const char c)
{
	return (c == '\n');
}

/**
 * @brief Check if the line is blank
 * @param line The line to check
 * @return true if the line is blank, false otherwise
*/
inline bool	is_blank(const char *line)
{
	int				index;

	if (!line)
		return (true);
	index = -1;
	while (line[++index])
	{
		if (!is_space(line[index]) && !is_newline(line[index]))
			return (false);
	}
	return (true);
}

/**
 * @brief Check if the line has only set of c characters
 * @param line The line to check
 * @param c The character to check
 * @return true if the line has only set of c characters, false otherwise
*/
inline bool	is_only(const char *line, const char c)
{
	int				index;

	if (!line || !c)
		return (true);
	index = -1;
	while (line[++index])
	{
		if (line[index] != c)
			return (false);
	}
	return (true);
}
