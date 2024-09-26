/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ends_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 07:45:07 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/20 09:25:17 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/**
 * @brief Check if the string ends with the suffix
 * @param str The string to check
 * @param suffix The suffix to check
 * @return true if the string ends with the suffix, false otherwise
*/
bool	ft_ends_with(const char *str, const char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;

	if (!str || ! suffix)
		return (false);
	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (str_len < suffix_len)
		return (false);
	return (ft_strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0);
}
