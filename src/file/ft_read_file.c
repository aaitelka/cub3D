/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:03:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/17 10:04:31 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == FAILED)
	{
		perror("open file");
		return (FAILED);
	}
	return (fd);
}

int	ft_readfile(int fd, void parse(t_cube3d *, char *), t_cube3d *cube)
{
	char			*line;
	int				status;

	line = NULL;
	status = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (status == 0)
				return (EFEMPTY);
			else
				break ;
		}
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		parse(cube, line);
		status++;
	}
	return (SUCCESS);
}
