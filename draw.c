/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 15:15:07 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/10 11:46:05 by yitoh         ########   odam.nl         */
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
	ft_freet_point(map->cod);
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
	t_bresenham	b;
	int			fraction;

	b = bresenham_setup(fst, sec);
	if (b.dx < 0)
	{
		b.step = -1;
		b.dx = -(b.dx);
	}
	fraction = 2 * b.dx - b.dy;
	while (b.j <= sec.y)
	{
		if (fraction >= 0)
		{
			b.i += b.step;
			fraction -= 2 * b.dy;
		}
		b.j++;
		fraction += 2 * b.dx;
		if (b.i > 0 && (int )map->img->width > b.i && b.j > 0
			&& (int )map->img->height > b.j && b.j > 30)
			mlx_put_pixel(map->img, b.i, b.j,
				get_color2(fst, sec, percent(b.i, b.j, &fst, &sec)));
	}
}

void	low_line(t_point fst, t_point sec, t_map *map)
{
	t_bresenham	b;
	int			fraction;

	b = bresenham_setup(fst, sec);
	if (b.dy < 0)
	{
		b.step = -1;
		b.dy = -(b.dy);
	}
	fraction = 2 * b.dy - b.dx;
	while (b.i <= sec.x)
	{
		if (fraction > 0)
		{
			b.j += b.step;
			fraction -= 2 * b.dx;
		}
		b.i++;
		fraction += 2 * b.dy;
		if (b.i > 0 && (int )map->img->width > b.i && b.j > 0
			&& (int )map->img->height > b.j && b.j > 30)
			mlx_put_pixel(map->img, b.i, b.j,
				get_color2(fst, sec, percent(b.i, b.j, &fst, &sec)));
	}
}

t_bresenham	bresenham_setup(t_point fst, t_point sec)
{
	t_bresenham	b;

	b.i = fst.x;
	b.j = fst.y;
	b.dx = (sec.x - fst.x);
	b.dy = (sec.y - fst.y);
	b.step = 1;
	return (b);
}
