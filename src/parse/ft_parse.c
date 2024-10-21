/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:03:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/21 21:33:04 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_file_status(char *filename, int status)
{
	if (status == EISDIR)
		return (ft_error(filename, strerror(EISDIR)));
	if (status == ENOENT)
		return (ft_error(filename, strerror(ENOENT)));
	if (status == EFEMPTY)
		return (ft_error(filename, "File is empty"));
	if (status == EMHASTAB)
		return (ft_error(filename, "Map has tab"));
	return (SUCCESS);
}

int	ft_readfile(int fd, int parse(t_cube *, char *), t_cube *cube)
{
	char			*line;
	bool			status;

	line = NULL;
	status = false;
	cube->map.point = (t_point){0};
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (status == false)
				return (EFEMPTY);
			break ;
		}
		cube->map.point.row++;
		if (parse(cube, line) != SUCCESS)
			return (free(line), FAILED);
		free(line);
		status = true;
	}
	if (!materials_inited(&cube->map))
		return (ft_error("materials", "missed material"));
	return (ft_parse_map(cube));
}

int	parse_file(t_cube *cube, char *filename)
{
	int				fd;
	int				status;

	fd = open(filename, O_RDONLY);
	if (fd == FAILED)
		return (ft_error(filename, NULL));
	status = ft_readfile(fd, ft_parse, cube);
	return (close(fd), check_file_status(filename, status));
}
