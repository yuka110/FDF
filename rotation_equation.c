/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_equation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 10:59:05 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/30 10:59:35 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
