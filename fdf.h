/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:17 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/24 16:46:54 by yitoh         ########   odam.nl         */
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
	int	x;
	int	y;
	int	z;
	int	color;
}					t_point;

typedef struct s_color
{
	int		*rgba;
	// int		min_z;
	// int		max_z;
	int		cod_dif;
	int		from;
	int		to;
}					t_color;

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

//persing_fdf.c
t_map	*open_parse(char **argv);
t_map	*init_null(void);
char	**read_split(int fd, t_map *map);
int		**ft_2dcalloc(t_map *map, char **tmp);
void	input_arr(t_map **m, char **tmp, int **map_tmp);
// t_map	*input_arr(t_map *map, char **tmp, int **map_tmp);

//draw.c
void	draw_line(void *m);
void	plot_line(t_point fst, t_point sec, t_map *map);
void	high_line(t_point fst, t_point sec, t_map *map);
void	low_line(t_point fst, t_point sec, t_map *map);

//find_points.c
t_point	**cod_2dcalloc(t_map *map);
t_point	calculate_cod(int x, int y, int z, t_map *map);
t_point	**find_cod(t_map *map);
int		x_rotation(t_map *map, int x, int y, int z);
int		y_rotation(t_map *map, int x, int y, int z);
int		z_rotation(t_map *map, int x, int y, int z);


//fdf.c
void	set_background(void *map);
void	print_map(t_map *map);
void	ft_free(char **s);

//key_hook.c
void	zoom(double xdelta, double ydelta, void *m);
void	key_input(mlx_key_data_t keydata, void *map);
void	transition(mlx_key_data_t keydata, void *map);
void	rotation(mlx_key_data_t keydata, void *map);

//get_color.c
void	color_setup(t_color **c, t_map *map);
int		*set_rgba(void);
int		min_z(char *line);
int		max_z(char *line);



#endif
