/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starts_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:27:37 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/20 09:25:44 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/**
 * @brief Check if the string starts with the prefix
 * @param str The string to check
 * @param prefix The prefix to check
 * @return true if the string starts with the prefix, false otherwise
*/
bool	ft_starts_with(const char *str, const char *prefix)
{
	size_t	str_len;
	size_t	prefix_len;

	if (!str || ! prefix)
		return (false);
	str_len = ft_strlen(str);
	prefix_len = ft_strlen(prefix);
	if (str_len < prefix_len)
		return (false);
	return (ft_strncmp(str, prefix, prefix_len) == 0);
}
