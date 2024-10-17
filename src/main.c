/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:35:55 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/17 17:12:29 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	destroty_game(t_cube *cube)
{
	if (cube->map.content)
		free(cube->map.content);
	if (cube->map._2d)
		ft_clear_array((char **)cube->map._2d, cube->map.size);
	ft_destroy(cube);
}

int	check_file_status(char *filename, int status)
{
	if (status == EISDIR)
		return (ft_error(filename, strerror(EISDIR)));
	else if (status == ENOENT)
		return (ft_error(filename, strerror(ENOENT)));
	else if (status == EFEMPTY)
		return (ft_error(filename, "File is empty"));
	else if (status == EMHASTAB)
		return (ft_error(filename, "Map has tab"));
	return (SUCCESS);
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
	t_cube cube;

	cube.mlx = mlx_init(1920, 1080, "cub3D", true);
	cube.map = (t_map){0};
	cube.map.colors[C] = -1;
	cube.map.colors[F] = -1;
	int fd = ft_open(map_file);
	if (fd == FAILED)
		ft_error(map_file, NULL);
	int status = ft_readfile(fd, ft_parse, &cube);
	check_file_status(map_file, status);
	close(fd);
	// colorize(&cube);
	// int ret = textures_initialized(&cube.map);
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
	
	destroty_game(&cube);
	return (SUCCESS);
}
static inline bool is_valid_ext(char *p)
{
	return (ft_strncmp(p + ft_strlen(p) - 4, ".cub", 4) == 0);
}

void leak(){system("leaks cub3D");}
int main(int argc, char **argv)
{
	// atexit(leak);
	if (argc == 2 && is_valid_ext(argv[argc - 1]))
		start_game(argv[argc - 1]);
	else
		ft_error("map", "missing [map].cub");
	return 0;
}
