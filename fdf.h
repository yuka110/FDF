/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:17 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/10 17:02:04 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <math.h>
# include "./Libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	double	ratio;
}					t_point;

typedef struct s_color
{
	long	*rgba;
	int		min_z;
	int		max_z;
	int		from;
	int		to;
}					t_color;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	i;
	int	j;
	int	step;
}					t_bresenham;

typedef struct s_map
{
	mlx_t		*win;
	mlx_image_t	*img;
	int			**map;
	t_point		**cod;
	t_color		*light;
	int			x;
	int			y;
	int			iso;
	double		zoom;
	int			xp;
	int			yp;
	float		xaxis;
	float		yaxis;
	float		zaxis;

}					t_map;

//fdf.c
void	set_background(void *map);
void	set_menu(mlx_t *win);
// void	print_map(t_map *map);

//persing_fdf.c
t_map	*open_parse(char **argv);
t_map	*init_null(void);
char	**read_split(int fd, t_map *map);
int		**ft_2dcalloc(t_map *map, char **tmp);
void	input_arr(t_map **m, char **tmp, int **map_tmp);

//persing_utils_fdf.c
int		locate_strchr(const char *s, int c);
void	comma_check(char ***str);
void	ft_free(char **s);
void	ft_freet_point(t_point **s);

//draw.c
void	draw_line(void *m);
void	plot_line(t_point fst, t_point sec, t_map *map);
void	high_line(t_point fst, t_point sec, t_map *map);
void	low_line(t_point fst, t_point sec, t_map *map);
t_bresenham	bresenham_setup(t_point fst, t_point sec);

//find_points.c
t_point	**cod_2dcalloc(t_map *map);
t_point	calculate_cod(int x, int y, int z, t_map *map);
t_point	**find_cod(t_map *map);
void	color_per_unit(int i, int j, t_point *cod, t_map *map);

//rotation_equation.c
int		x_rotation(t_map *map, int x, int y, int z);
int		y_rotation(t_map *map, int x, int y, int z);
int		z_rotation(t_map *map, int x, int y, int z);

//key_hook.c
void	zoom(double xdelta, double ydelta, void *m);
void	new_key_hook(void *map);
void	new_transition(void *map);
void	new_rotation(void *map);

//get_color.c
int		get_color(t_color *c, double percent);
int		get_color2(t_point fst, t_point sec, double percent);
int		linear_grad(double percent, int from_color, int to_color);
double	percent(int curx, int cury, t_point *fst, t_point *sec);

//color_init.c
void	color_setup(t_color **c, t_map *map);
long	*set_color(void);
int		max_zvalue(int **s, t_map *map);
int		min_zvalue(int **s, t_map *map);

#endif
