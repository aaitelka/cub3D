/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:28:11 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/17 10:08:59 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <libft.h>
# include <MLX42.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define FAILED 	-1
# define SUCCESS 	0
# define FAILURE 	1

//* FILE ERRORS
# define EFEMPTY	50
# define EFINVALID	51
//* MAP ERRORS
# define EMHASTAB	60

typedef enum e_directions
{
	NO,
	EA,
	SO,
	WE,
	TEXTURES_SIZE
}	t_directions;

typedef enum e_colors
{
	F,
	C,
	COLORS_SIZE
}	t_colors;

typedef struct s_map
{
	mlx_image_t		*textures[TEXTURES_SIZE];
	int				colors[COLORS_SIZE];
}	t_map;

typedef struct s_cube3d
{
	char			*map_path;
	char			*content;
	mlx_t			*mlx;
	t_map			map;
}	t_cube3d;

/*		STR		*/
bool			ft_starts_with(const char *str, const char *prefix);
bool			ft_ends_with(const char *str, const char *prefix);

//* FILE
int				ft_open(char *file);
int				ft_readfile(int fd, void f(t_cube3d *, char *), t_cube3d *cube);
bool			ft_is_valid_ext(char *file_name, char *ext);

//* PARSE
void			ft_parse(t_cube3d *cube, char *line);
void			ft_add_map(t_cube3d *cube, char *str);
void			ft_add_color(t_cube3d *cube, char *str);
void			ft_add_texture(t_cube3d *cube, char *str);

t_colors		colors_initialized(t_map *map);
t_directions	textures_initialized(t_map *map);

/** Cardinal	*/
bool			is_east_texture(const char *line);
bool			is_west_texture(const char *line);
bool			is_north_texture(const char *line);
bool			is_south_texture(const char *line);

/** Colors	*/
bool			is_ceiling_color(const char *line);
bool			is_floor_color(const char *line);
int				get_rgb(int r, int g, int b);

//* UTILS
bool			is_map(const char *line);
bool			is_color(const char *line);
bool			is_texture(const char *line);
bool			is_null(char *str);

//* CLEAN
void			ft_clear(char **array, int size);

//* ERROR
void			ft_error(char *where, char *msg);

#endif