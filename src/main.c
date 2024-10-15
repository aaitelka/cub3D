/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:35:55 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/07 10:49:51 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	destroty_game(t_cub3d *cube)
{
	if (cube->map.content)
		free(cube->map.content);
	if (cube->map._2d)
		ft_clear_array((char **)cube->map._2d, cube->map.size);
	ft_destroy(cube);
}

void	check_file_status(char *filename, int status)
{
	if (status == EISDIR)
	{
		ft_error(filename, strerror(EISDIR));
		exit(EISDIR);
	}
	else if (status == ENOENT)
	{
		ft_error(filename, strerror(ENOENT));
		exit(ENOENT);
	}
	else if (status == EFEMPTY)
	{
		ft_error(filename, "File is empty");
		exit(EXIT_FAILURE);
	}
	else if (status == EMHASTAB)
	{
		ft_error(filename, "Map has tab");
		exit(EXIT_FAILURE);
	}
}

static void key_listener(void *param)
{
	mlx_t *mlx;

	mlx = (mlx_t *)param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_terminate(param);
		exit(SUCCESS);	
	}
}

static int	start_game(char *map_file)
{
	t_cub3d cube3d;

	cube3d.mlx = mlx_init(1920, 1080, "cub3D", true);
	cube3d.map = (t_map){0};
	int fd = ft_open(map_file);
	if (fd == FAILED)
		ft_error(map_file, NULL);
	int status = ft_readfile(fd, ft_parse, &cube3d);
	check_file_status(map_file, status);
	close(fd);
	// colorize(&cube3d);
	// int ret = textures_initialized(&cube3d.map);
	// if (ret == EA)
	// {
	// 	ft_error("textures", "east texture missing");
	// 	return (FAILED);
	// }
	// else if (ret == SO)
	// {
	// 	ft_error("textures", "south texture missing");
	// 	return (FAILED);
	// }
	// else if (ret == WE)
	// {
	// 	ft_error("textures", "west texture missing");
	// 	return (FAILED);
	// }
	// else if (ret == NO)
	// {
	// 	ft_error("textures", "north texture missing");
	// 	return (FAILED);
	// }
	
	destroty_game(&cube3d);
	return (SUCCESS);
}
static inline bool is_valid_ext(char *p)
{
	return (ft_strncmp(p + ft_strlen(p) - 4, ".cub", 4) == 0);
}

void leak(){system("leaks cub3D");}
int main(int argc, char **argv)
{
	atexit(leak);
	if (argc == 2 && is_valid_ext(argv[argc - 1]))
		start_game(argv[argc - 1]);
	else
		ft_error("map", "missing [map].cub");
	return 0;
}
