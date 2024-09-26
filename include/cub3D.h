/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:28:11 by aaitelka          #+#    #+#             */
/*   Updated: 2024/09/26 16:50:25 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

# include <libft.h>
# include <MLX42.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>


# define EMFEMPTY "File is empty"

# define RED "\033[31m"
# define ORNG "\033[38;5;208m"
# define RESET "\033[0m"

# define FAILED 	-1
# define SUCCESS 	0
# define FAILURE 	1

//* FILE ERRORS
# define EFEMPTY	30
# define EFINVALID	31

//* TEXTURE ERRORS
# define ETMISSING	40

//* COLOR ERRORS
# define ECMISSING	50

//* MAP ERRORS
# define EMHASTAB	60
# define EMHASNL	61

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

typedef struct s_point
{
	int				row;
	int				col;
	int				err;
}	t_point;

typedef struct s_map
{
	char			*content;
	char 			**_2d;
	size_t			longest;
	int				size;
	int				colors[COLORS_SIZE];
	mlx_image_t		*textures[TEXTURES_SIZE];
	t_point			point;
}	t_map;

typedef struct s_cub3d
{
	char			*map_path;
	char			*content;
	mlx_image_t		*image;
	mlx_t			*mlx;
	t_map			map;
	bool			ismap;
}	t_cub3d;

/*		STR		*/
bool			ft_starts_with(const char *str, const char *prefix);
bool			ft_ends_with(const char *str, const char *prefix);

//* FILE
int				ft_open(char *file);
int				ft_readfile(int fd, void f(t_cub3d *, char *), t_cub3d *cube);
bool			ft_is_valid_ext(char *file_name, char *ext);

//* PARSE
void			ft_parse_map(t_cub3d *cube);
void			ft_parse(t_cub3d *cube, char *line);
void			ft_parse_color(t_cub3d *cube, char *line);
void			ft_parse_texture(t_cub3d *cube, char *line);

t_colors		colors_initialized(t_map *map);
t_directions	textures_initialized(t_map *map);

//* MAP
void			square_it(t_map *map);

/** Cardinal	*/
bool			is_east_texture(const char *line);
bool			is_west_texture(const char *line);
bool			is_north_texture(const char *line);
bool			is_south_texture(const char *line);

/** Colors	*/
bool			is_ceiling_color(const char *line);
bool			is_floor_color(const char *line);
int				get_rgb(int r, int g, int b, int a);

//* UTILS
bool			is_valid_color(const int c);
bool			is_only(const char *line, const char c);
bool			is_blank(const char *line);
bool			is_map(const char c);
bool			is_zero(const char c);
bool			is_null(const char c);
bool			is_space(const char c);
bool			is_player(const char c);
bool			is_newline(const char c);
bool			valid_char(const char c);
bool			is_wall(const char c);

bool			is_east(const char c);
bool			is_north(const char c);
bool			is_south(const char c);
bool			is_west(const char c);

bool			is_color(const char *line);
bool			is_texture(const char *line);

//* ARRAY UTILS
size_t			ft_array_size(char **array);
void			ft_clear_array(char **array, int size);

//* CLEAN
void			ft_destroy(t_cub3d *cube);

//* ERROR
void			set_error(t_point *point, int row, int col, int err);
void			ft_error(char *where, char *msg);

#endif