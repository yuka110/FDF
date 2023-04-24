/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_points.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:18:47 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/24 15:59:24 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**cod_2dcalloc(t_map *map)
{
	int		i;
	t_point	**arr;

	i = 0;
	arr = ft_calloc(map->y + 1, sizeof(t_point *));
	if (!arr)
		exit(0);
	while (i < map->y)
	{
		arr[i] = ft_calloc(map->x + 1, sizeof(t_point));
		if (!arr[i])
			exit(0);
		++i;
	}
	return (arr);
}

t_point	calculate_cod(int x, int y, int z, t_map *map)
{
	t_point	p;
	float	a;
	int		xoffset;
	int		yoffset;

	xoffset = (map->img->width - (map->x * map->zoom)) / 2 + map->xp;
	yoffset = (map->img->height - (map->y * map->zoom)) / 2 + map->yp;
	if (map->iso == 1)
	{
		// // map->xaxis = 
		// map->zaxis = 45 * (M_PI / 180);//0.615479709;
		// map->xaxis = (90-35.264) * (M_PI / 180);//0.75049;
		a = 0.523599;
		p.z = -(map->zoom) * z;
		p.x = 2 * map->zoom * (x * cos(a) - y * sin(a)) + xoffset;
		p.y = map->zoom * (x * sin(a) + y * cos(a)) + yoffset + p.z;
	}
	else
	{
		p.x = x_rotation(map, x, y, z);
		p.y = y_rotation(map, x, y, z);
		p.z = z_rotation(map, x, y, z);
		p.x = p.x + xoffset;
		p.y = p.y + yoffset - p.z;
	}
	return (p);
}

int	x_rotation(t_map *map, int x, int y, int z)
{	
	float	xx;
	float	xy;
	float	xz;
	double	zoom;

	zoom = map->zoom;
	xx = cos(map->zaxis) * cos(map->xaxis) * zoom;
	xy = (cos(map->zaxis) * sin(map->xaxis) * sin(map->yaxis) * zoom
			- sin(map->zaxis) * cos(map->yaxis) * zoom);
	xz = (cos(map->zaxis) * sin(map->xaxis) * cos(map->yaxis) * zoom
			+ sin(map->zaxis) * sin(map->yaxis) * zoom);
	return ((int)xx * x + xy * y + xz * z);
}

int	y_rotation(t_map *map, int x, int y, int z)
{	
	float	yx;
	float	yy;
	float	yz;
	double	zoom;

	zoom = map->zoom;
	yx = sin(map->zaxis) * cos(map->xaxis) * zoom;
	yy = (sin(map->zaxis) * sin(map->xaxis) * sin(map->yaxis) * zoom
			+ cos(map->zaxis) * cos(map->yaxis) * zoom);
	yz = (sin(map->zaxis) * sin(map->xaxis) * cos(map->yaxis) * zoom
			- sin(map->zaxis) * sin(map->yaxis) * zoom);
	return ((int)yx * x + yy * y + yz * z);
}

int	z_rotation(t_map *map, int x, int y, int z)
{	
	float	zx;
	float	zy;
	float	zz;
	double	zoom;

	zoom = map->zoom;
	zx = -sin(map->xaxis) * zoom;
	zy = cos(map->xaxis) * sin(map->yaxis) * zoom;
	zz = cos(map->xaxis) * cos(map->yaxis) * zoom;
	return ((int)zx * x + zy * y + zz * z);
}


t_point	**find_cod(t_map *map)
{
	t_point	**new_cod;
	int		i;
	int		j;

	new_cod = cod_2dcalloc(map);
	if (!new_cod)
		return (NULL);
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			new_cod[i][j] = calculate_cod(j, i, map->map[i][j], map);
			j++;
		}
		i++;
	}
	return (new_cod);
}
