/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:55:15 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/21 18:34:53 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

inline bool	is_null(const char c)
{
	return (c == '\0');
}

inline bool	is_space(const char c)
{
	return (c == ' ');
}

inline bool	is_newline(const char c)
{
	return (c == '\n');
}

inline bool	is_blank(const char *line)
{
	int				index;

	index = -1;
	while (line[++index])
	{
		if (!is_space(line[index]) && !is_newline(line[index]))
			return (false);
	}
	return (true);
}

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
