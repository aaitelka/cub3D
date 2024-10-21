/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:35:55 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/21 21:25:46 by aaitelka         ###   ########.fr       */
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

static int	start_game(char *filename)
{
	t_cube			cube;

	cube.mlx = mlx_init(1920, 1080, "cub3D", true);
	cube.map = (t_map){0};
	cube.map.colors[C] = -1;
	cube.map.colors[F] = -1;
	parse_file(&cube, filename);
	destroty_game(&cube);
	return (SUCCESS);
}

static inline bool	is_valid_ext(char *path)
{
	return (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4) == 0);
}

// void leak(){system("leaks cub3D");}
// atexit(leak);
int	main(int argc, char **argv)
{
	if (argc == 2 && is_valid_ext(argv[argc - 1]))
		start_game(argv[argc - 1]);
	else
		ft_error("map", "missing [map].cub");
	return (EXIT_SUCCESS);
}
