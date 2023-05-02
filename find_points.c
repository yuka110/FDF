/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_points.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:18:47 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/02 17:18:26 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**find_cod(t_map *map)
{
	t_point	**new_cod;
	int		i;
	int		j;

	new_cod = cod_2dcalloc(map);
	if (!new_cod)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			new_cod[i][j] = calculate_cod(j, i, map->map[i][j], map);
			color_per_unit(i, j, &(new_cod[i][j]), map);
			j++;
		}
		i++;
	}
	return (new_cod);
}

t_point	**cod_2dcalloc(t_map *map)
{
	int		i;
	t_point	**arr;

	i = 0;
	arr = ft_calloc(map->y + 1, sizeof(t_point *));
	if (!arr)
		exit(EXIT_FAILURE);
	while (i < map->y)
	{
		arr[i] = ft_calloc(map->x + 1, sizeof(t_point));
		if (!arr[i])
			exit(EXIT_FAILURE);
		++i;
	}
	return (arr);
}

t_point	calculate_cod(int x, int y, int z, t_map *map)
{
	t_point	p;
	int		xoff;
	int		yoff;

	xoff = (map->img->width - (map->x * map->zoom)) / 2 + map->xp;
	yoff = (map->img->height - (map->y * map->zoom)) / 2 + map->yp;
	if (map->iso == 1)
	{
		p.z = -(map->zoom) * z;
		p.x = 2 * map->zoom * (x * cos(0.523599) - y * sin(0.523599)) + xoff;
		p.y = map->zoom * (x * sin(0.523599) + y * cos(0.523599)) + yoff + p.z;
		// map->xaxis = 0 * (M_PI / 180);
		// map->yaxis = 15 * (M_PI / 180);//0.615479709;
		// map->zaxis = 35.264 * (M_PI / 180);//0.75049;
	}
	else
	{
		p.x = x_rotation(map, x, y, z) + xoff;
		p.y = y_rotation(map, x, y, z) + yoff;
		p.z = z_rotation(map, x, y, z);
		p.y = p.y - (p.z / 2);
	}
	return (p);
}

		// map->xaxis = 0;

void	color_per_unit(int i, int j, t_point *cod, t_map *map)
{
	t_color	*c;

	c = map->light;
	if (map->map[i][j] == c->min_z)
		(*cod).ratio = 1.0;
	else if (map->map[i][j] == c->max_z)
		(*cod).ratio = 0;
	else
		(*cod).ratio = (double)(map->map[i][j] - c->min_z)
			/ (c->max_z - c->min_z);
}

