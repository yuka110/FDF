/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 15:15:07 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/16 16:01:59 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	draw_line(mlx_image_t *img, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			brassenham_line(i, map->map[i][j], i, map->map[i][j+1], img);
			j++;
		}
		i++;
	}
}

void	brassenham_line(int x0, int y0, int x1, int y1, mlx_image_t *img)
{
	int	dx;
	int	dy;
	int fraction;
	int i;
	int j;
	int	ystep;

	i = 0;
	j = 0;
	// zoom = 3;
	ystep = 1;
	printf("start(%d, %d) end(%d, %d)\n", x0, y0, x1, y1);
	//swap coordinates when slope > 1
	if ((y1 - y0) > (x1 - x0))
		swap_cod(&x0, &y0, &x1, &y1);
	// decrement when the line is right-side-up
	if (y0 > y1 && x0 < x1)
		ystep = -1;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	fraction = 2 * dy - dx;
	printf("dx:%d, dy:%d, initial:%d\n", dx, dy, fraction);
	while (i + x0 < x1)
	{
		if (fraction >= dx)
		{
			mlx_put_pixel(img, i + x0, j + y0, 0xFF0000FF);
			j += ystep;
			fraction -= 2 * dx;
		}
		i++;
		fraction += 2 * dy;
		mlx_put_pixel(img, i + x0, j + y0, 0xFF0000FF);
	}
}

void	swap_cod(int *a, int *b, int *a1, int *b1)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
	swap = *a1;
	*a1 = *b1;
	*b1 = swap;
}
