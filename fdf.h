/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:17 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/06 15:38:04 by yitoh         ########   odam.nl         */
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
# include "./Libft/libft.h"

typedef struct fdf_list
{
	int			**map;
	int			x;
	int			y;
	int			z;
}					t_fdf;

t_fdf	*open_parse(char **argv);
t_fdf	*init_null(void);
char	**read_split(int fd, t_fdf *map);
int	**ft_2dcalloc(t_fdf *map, char **tmp);
t_fdf	*input_arr(t_fdf *map, char **tmp, int **map_tmp);
void	print_map(t_fdf *map);
void	ft_free(char **s);

#endif
