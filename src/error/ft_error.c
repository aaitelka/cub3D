/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:51:42 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/15 14:46:13 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	set_error(t_point *point, int row, int col, int err)
{
	point->row = row + 1;
	point->col = col + 1;
	point->err = err;
}

int	ft_error(char *where, char *msg)
{
	ft_putendl_fd(RED "Error" RESET, STDERR_FILENO);
	ft_putstr_fd("cube3D: ", STDERR_FILENO);
	ft_putstr_fd(ORNG, STDERR_FILENO);
	ft_putstr_fd(where, STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	else
		perror("");
	return (FAILED);
}
