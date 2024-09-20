/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:51:42 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/18 06:30:50 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_error(char *where, char *msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd("cube3D: ", STDERR_FILENO);
	ft_putstr_fd(where, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}
