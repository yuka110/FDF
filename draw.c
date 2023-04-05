/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 15:15:07 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/05 20:26:59 by yitoh         ########   odam.nl         */
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
			plot_line(map->cod[-i][j], map->cod[-i][j + 1], map->img);
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
			plot_line(map->cod[i][j], map->cod[i + 1][j], map->img);
			i++;
		}
		j++;
	}
}

void	plot_line(t_point fst, t_point sec, mlx_image_t *img)
{
	//2,3,6,7 octant
	if (abs(sec.y - fst.y) < abs(sec.x - fst.x))
	{
		if (fst.x < sec.x)
			low_line(fst, sec, img);
		else
			low_line(sec, fst, img);
	}
	else
	{
		if (fst.y < sec.y)
			high_line(fst, sec, img);
		else
			high_line(sec, fst, img);
	}
}

void	high_line(t_point fst, t_point sec, mlx_image_t *img)
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
		if (i <= (int)img->width && j <= (int)img->height)
			mlx_put_pixel(img, i, j, 0xFF0000FF);
	}
}

void	low_line(t_point fst, t_point sec, mlx_image_t *img)
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
		if (i <= (int)img->width && j <= (int)img->height)
			mlx_put_pixel(img, i, j, 0xFF0000FF);
	}
}

//if new points are beyond the screen size, do not put pixel


// void	bresenham_test(mlx_image_t *img, t_map *map)
// {
// 	plot_line(new_point(0, 0, map, 30), new_point(200, 0, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(-200, 0, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(0, 200, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(0, -200, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(100, 50, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(50, 100, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(200, -50, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(50, -200, map, 30), img);	
// 	plot_line(new_point(0, 0, map, 30), new_point(-200, -50, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(-50, -200, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(-100, 50, map, 30), img);
// 	plot_line(new_point(0, 0, map, 30), new_point(-50, 100, map, 30), img);
// }
