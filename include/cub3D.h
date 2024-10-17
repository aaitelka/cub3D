/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:28:11 by aaitelka          #+#    #+#             */
/*   Updated: 2024/10/17 08:20:03 by aaitelka         ###   ########.fr       */
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

# define R3D "\033[31m"
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
	TXTRS_SZ
}	t_directions;

typedef enum e_colors
{
	F,
	C,
	CLRS_SZ
}	t_colors;

typedef struct s_point
{
	int				row;
	int				col;
}	t_point;

typedef struct s_map
{
	char			*content;
	char 			**_2d;
	size_t			longest;
	int				size;
	int				colors[CLRS_SZ];
	mlx_image_t		*textures[TXTRS_SZ];
	t_point			point;
}	t_map;

typedef struct s_cube
{
	int				materials;
	char			*map_path;
	char			*content;
	mlx_image_t		*image;
	mlx_t			*mlx;
	t_map			map;
	bool			ismap;
}	t_cube;

//* FILE
int				ft_open(char *file);
int				ft_readfile(int fd, int f(t_cube *, char *), t_cube *cube);

//* PARSE
int					ft_parse(t_cube *cube, char *line);
int					ft_parse_texture(t_cube *cube, char *line);
int					ft_parse_color(t_cube *cube, char *line);
int					ft_parse_map(t_cube *cube);

t_colors		colors_inited(t_map *map);
t_directions	textures_inited(t_map *map);

//* MAP
void			square_it(t_map *map);

/** Cardinal	*/
bool			is_east_texture(const char *line);
bool			is_west_texture(const char *line);
bool			is_north_texture(const char *line);
bool			is_south_texture(const char *line);

/** Colors	*/
bool			is_ceiling(const char *line);
bool			is_floor(const char *line);
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

//* DRAW
void			ft_draw_circle(t_cube *cube, uint32_t width, uint32_t height);

//* WINDOW
void			ft_fill_window(t_cube *cube);

//* CLEAN
void			ft_destroy(t_cube *cube);

//* ERROR
int					ft_error(char *where, char *msg);

#endif