/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:17 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/07 14:34:21 by yitoh         ########   odam.nl         */
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
}					t_point;

typedef struct s_map
{
	mlx_t		*win;
	mlx_image_t	*img;
	int			**map;
	t_point		**cod;
	int			x;
	int			y;
	int			iso;
	double		zoom;
	float		angle;
	int			ori;
}					t_map;

//persing_fdf.c
t_map	*open_parse(char **argv);
t_map	*init_null(void);
char	**read_split(int fd, t_map *map);
int		**ft_2dcalloc(t_map *map, char **tmp);
t_map	*input_arr(t_map *map, char **tmp, int **map_tmp);

//draw.c
void	draw_line(void *m);
void	plot_line(t_point fst, t_point sec, t_map *map);
void	high_line(t_point fst, t_point sec, t_map *map);
void	low_line(t_point fst, t_point sec, t_map *map);

//find_points.c
t_point	**cod_2dcalloc(t_map *map);
t_point	calculate_cod(int x, int y, t_map *map, float angle);
t_point	**find_cod(t_map *map);

//fdf.c
void	set_background(void *map);
void	print_map(t_map *map);
void	ft_free(char **s);

//key_hook.c
void	zoom_transit(double xdelta, double ydelta, void *m);
void	key_input(mlx_key_data_t keydata, void *win);



#endif
