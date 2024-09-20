/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:55:09 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/18 06:30:50 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	ft_is_valid_ext(char *file_name, char *ext)
{
	size_t	file_len;
	size_t	ext_len;

	file_len = ft_strlen(file_name);
	ext_len = ft_strlen(ext);
	if (file_len < ext_len)
		return (false);
	return (ft_strncmp(file_name + file_len - ext_len, ext, ext_len) == 0);
}
