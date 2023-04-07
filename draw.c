/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 15:15:07 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/07 14:57:28 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(void *m)
{
	int		i;
	int		j;
	t_map	*map;

	map = (t_map *)m;
	map->cod = find_cod(map);
	if (!map->cod)
		exit (0);
	//drawing (horizontal and vertical)
	i = 0;
	while (i > -(map->y))
	{
		j = 0;
		while (j < map->x - 1)
		{
			plot_line(map->cod[-i][j], map->cod[-i][j + 1], map);
			j++;
		}
		i--;
	}
	j = 0;
	while (j < map->x)
	{
		i = 0;
		while (i < map->y - 1)
		{
			plot_line(map->cod[i][j], map->cod[i + 1][j], map);
			i++;
		}
		j++;
	}
}

void	plot_line(t_point fst, t_point sec, t_map *map)
{
	//2,3,6,7 octant
	if (abs(sec.y - fst.y) < abs(sec.x - fst.x))
	{
		if (fst.x < sec.x)
			low_line(fst, sec, map);
		else
			low_line(sec, fst, map);
	}
	else
	{
		if (fst.y < sec.y)
			high_line(fst, sec, map);
		else
			high_line(sec, fst, map);
	}
}

void	high_line(t_point fst, t_point sec, t_map *map)
{
	int	dx;
	int	dy;
	int fraction;
	int i;
	int j;
	int	xstep;

	i = fst.x;
	j = fst.y;
	dx = (sec.x - fst.x);
	dy = (sec.y - fst.y);
	xstep = 1;
	if (dx < 0)
	{
		xstep = -1;
		dx = -dx;
	}
	fraction = 2 * dx - dy;
	while (j <= sec.y)
	{
		if (fraction >= 0)
		{
			i += xstep;
			fraction -= 2 * dy;
		}
		j++;
		fraction += 2 * dx;
		if (i > 0 && (int )map->img->width > i && j > 0 && (int )map->img->height > j)
			mlx_put_pixel(map->img, i, j, 0xFF0000FF);
	}
}

void	low_line(t_point fst, t_point sec, t_map *map)
{
	int	dx;
	int	dy;
	int fraction;
	int i;
	int j;
	int	ystep;

	i = fst.x;
	j = fst.y;
	dx = (sec.x - fst.x);
	dy = (sec.y - fst.y);
	ystep = 1;
	if (dy < 0)
	{
		ystep = -1;
		dy = -dy;
	}
	fraction = 2 * dy - dx;
	while (i <= sec.x)
	{
		if (fraction > 0)
		{
			j += ystep;
			fraction -= 2 * dx;
		}
		i++;
		fraction += 2 * dy;
		if (i > 0 && (int )map->img->width > i && j > 0 && (int )map->img->height > j)
			mlx_put_pixel(map->img, i, j, 0xFF0000FF);
	}
}
