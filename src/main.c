/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:35:55 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/26 16:50:31 by aaitelka         ###   ########.fr       */
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

void colorize(t_cub3d *cube)
{
	mlx_image_t* img = mlx_new_image(cube->mlx, 256, 256);
	// memset(img->pixels, 16711680, img->width * img->height * sizeof(int32_t));
	if (!img || (mlx_image_to_window(cube->mlx, img, 540, 540) < 0))
	{
		ft_error("mlx_image", "failed to create or display image");
		mlx_terminate(cube->mlx);
		exit(EXIT_FAILURE);
	}
	unsigned int color = 0xFFFFFFFF;
	int index = -1;
	while (++index < 256)
	{
		int index2 = -1;
		while (++index2 < 256)
		{
			mlx_put_pixel(img, index, index2, color);
		}
	}
		// mlx_put_pixel(img, index, index, 0xFFFFFFFF);
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


	cube3d.mlx = mlx_init(1920, 1080, "cub3D", false);
	cube3d.map = (t_map){0};
	int fd = ft_open(map_file);
	if (fd == FAILED)
	{
		ft_error(map_file, NULL);
	}
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
	
	//! check if colors are initialized
	// if (colors_initialized(&cube3d.map) != COLORS_SIZE)
	// {
	// 	ft_error("colors", "missing colors");
	// 	return (FAILED);
	// }

	// mlx_new_image(cube3d.mlx, 1920, 1080);
	// int index = 0;
	// int position = 0;
	// while (index < TEXTURES_SIZE)
	// {
	// 	if (cube3d.map.textures[index] != NULL)
	// 	{
	// 		mlx_image_to_window(cube3d.mlx, cube3d.map.textures[index], 0, position);
	// 		position += 120;
	// 	} else {
	// 		printf("texture[%d] is NULL\n", index);
	// 	}
	// 	index++;
	// }
	// mlx_loop_hook(cube3d.mlx, key_listener, cube3d.mlx);
	// mlx_loop(cube3d.mlx);
	// index = 0;
	// while (index < TEXTURES_SIZE)
	// {
	// 	if (cube3d.map.textures[index] != NULL)
	// 		mlx_delete_image(cube3d.mlx, cube3d.map.textures[index]);
	// 	index++;
	// }
	destroty_game(&cube3d);
	// mlx_terminate(cube3d.mlx);
	return (SUCCESS);
}

void leak(){system("leaks cub3D");}
int main(int argc, char **argv)
{
	// atexit(leak);
	if (argc == 2 && ft_ends_with(argv[argc - 1], ".cub"))
		start_game(argv[argc - 1]);
	else
		ft_error("map", "missing [map].cub");
	return 0;
}
