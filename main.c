/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:35:55 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/17 10:11:41 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static int	start_game(char *map_file)
{
	t_cube3d cube3d;

	cube3d.mlx = mlx_init(1920, 1080, "cub3D", false);
	cube3d.map = (t_map){0};

	int fd = ft_open(map_file);
	if (fd == FAILED)
		ft_error("open file", "failed to open file");
	int status = ft_readfile(fd, ft_parse, &cube3d);
	if (status == FAILED)
		printf("failed to read file\n");
	else if (status == EFEMPTY)
		printf("empty file\n");
	else if (status == EMHASTAB)
		printf("file contains tab\n");
	close(fd);

	int ret = textures_initialized(&cube3d.map);
	if (ret == EA)
	{
		ft_error("textures", "east texture missing");
		return (FAILED);
	}
	else if (ret == SO)
	{
		ft_error("textures", "south texture missing");
		return (FAILED);
	}
	else if (ret == WE)
	{
		ft_error("textures", "west texture missing");
		return (FAILED);
	}
	else if (ret == NO)
	{
		ft_error("textures", "north texture missing");
		return (FAILED);
	}
	
	//! check if colors are initialized
	// if (colors_initialized(&cube3d.map) != COLORS_SIZE)
	// {
	// 	ft_error("colors", "missing colors");
	// 	return (FAILED);
	// }

	mlx_new_image(cube3d.mlx, 1920, 1080);
	int index = 0;
	int position = 0;
	while (index < TEXTURES_SIZE)
	{
		if (cube3d.map.textures[index] != NULL)
		{
			mlx_image_to_window(cube3d.mlx, cube3d.map.textures[index], 0, position);
			position += 120;
		} else {
			printf("texture[%d] is NULL\n", index);
		}
		index++;
	}
	mlx_loop(cube3d.mlx);
	index = 0;
	while (index < TEXTURES_SIZE)
	{
		if (cube3d.map.textures[index] != NULL)
			mlx_delete_image(cube3d.mlx, cube3d.map.textures[index]);
		index++;
	}
	mlx_terminate(cube3d.mlx);
	return (SUCCESS);
}

void leak(){system("leaks cub3D");}
int main(int argc, char **argv)
{
// 	atexit(leak);
	if (argc == 2 && ft_is_valid_ext(argv[argc - 1], ".cub"))
		start_game(argv[argc - 1]);
	else
		ft_error("map", "missing [map].cub");
	return 0;
}
