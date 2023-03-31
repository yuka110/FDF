/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 15:15:07 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/31 10:04:38 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	new_point(int x, int y, t_map *map, int angle)
{
	t_point	p;
	int		offset;
	int		zoom;

	offset = 200;
	zoom = 3;
	p.x = zoom * (x * cos(angle) - y * sin(angle)) + 400;
	p.y = zoom * (x * sin(angle) + y * cos(angle)) + 200;
	p.z = map->y - map->y * angle * zoom; //need to adjust
	return (p);
}

void	draw_line(mlx_image_t *img, t_map *map)
{
	int i;
	int j;

	i = 0;
	printf("test\n");
	while (i > -(map->y))
	{
		j = 0;
		while (j < map->x - 1)
		{
			printf("i: %d, j: %d\n", 2 *(i + j), j - i);
			plot_line(new_point(2 *(i + j), (j - i), map, 0), new_point(2 *(i + j + 1), (j - i + 1), map, 0), img);
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
			plot_line(new_point(2* (j - i), (i + j), map, 0), new_point(2*(j - i - 1), (i + j + 1), map, 0), img);
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
	mlx_put_pixel(img, i, j, 0xFF0000FF);
	while (j <= sec.y)
	{
		if (fraction >= 0)
		{
			i += xstep;
			fraction -= 2 * dy;
		}
		j++;
		fraction += 2 * dx;
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
	mlx_put_pixel(img, i, j, 0xFF0000FF);
	while (i <= sec.x)
	{
		if (fraction > 0)
		{
			j += ystep;
			fraction -= 2 * dx;
		}
		i++;
		fraction += 2 * dy;
		mlx_put_pixel(img, i, j, 0xFF0000FF);
	}

}

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
