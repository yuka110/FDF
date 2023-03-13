/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:17 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/13 23:03:47 by yitoh         ########   odam.nl         */
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

typedef struct s_map
{
	int			**map;
	int			x;
	int			y;
}					t_map;

//persing_fdf.c
t_map	*open_parse(char **argv);
t_map	*init_null(void);
char	**read_split(int fd, t_map *map);
int	**ft_2dcalloc(t_map *map, char **tmp);
t_map	*input_arr(t_map *map, char **tmp, int **map_tmp);

//fdf.c
void	straight_line(t_map *map, mlx_t	*win);
void	print_map(t_map *map);
void	ft_free(char **s);
void	brassenham_line(int x0, int y0, int x1, int y1, mlx_t *win);
//static void ft_hook(void* param);

#endif
