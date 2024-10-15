/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:03:49 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/15 14:54:09 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == FAILED)
	{
		ft_error(file, strerror(errno));
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static void	ft_readmap(t_cub3d *cube, char *line)
{
	char			*joined;
	char			*newline;

	joined = NULL;
	printf("%s", line);
	if (is_newline(*line))
	{
		ft_error("\\n", "has new linee");
		free(line);
		return ;
	}
	if (cube->map.longest < (int)ft_strlen(line))
		cube->map.longest = ft_strlen(line);
	cube->map.size++;
	joined = ft_strjoin(cube->map.content, line);
	free(cube->map.content);
	cube->map.content = joined;
	free(line);
}

int	ft_readfile(int fd, int parse(t_cub3d *, char *), t_cub3d *cube)
{
	char			*line;
	int				status;

	line = NULL;
	status = 0;
	cube->map.point = (t_point){0};
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
		cube->map.point.row++;
		if (parse(cube, line) == FAILED)
			return (FAILED);
		if (cube->ismap)
			ft_readmap(cube, line);
		status++;
	}
	ft_parse_map(cube);
	return (SUCCESS);
}
