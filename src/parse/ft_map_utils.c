/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:14:00 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/20 08:39:40 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

inline bool	is_zero(const char c)
{
	return (c == '0');
}

inline bool	is_space(const char c)
{
	return (c == ' ');
}

inline bool	is_map(const char c)
{
	return (is_space(c) || c == '1');
}

inline bool	is_player(const char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

inline bool	valid_char(const char c)
{
	return (is_space(c) || is_zero(c) || is_player(c) || c == '1' || c == '\n');
}
