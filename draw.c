/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 15:15:07 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/14 16:53:09 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// void	draw_line(mlx_t *win, mlx_image_t *img, t_map *map)
// {
// 	int	x0
// }

void	brassenham_line(int x0, int y0, int x1, int y1, mlx_image_t *img)
{
	int	dx;
	int	dy;
	int fraction;
	int i;
	int j;
	int	swap;
	// int	zoom;

	dx = x1 - x0;
	dy = y1 - y0;
	fraction = 2 * dy - dx;
	i = 0;
	j = 0;
	// zoom = 3;
	if (y1 <= y0)
	{
		swap = y0;
		y0 = y1;
		y1 = swap;
	}
	while (i + x0 < x1)
	{
		if (fraction >= 0)
		{
			j++;
			fraction -= 2 * dx;
			mlx_put_pixel(img, i + x0, j + y0, 0xFF0000FF);
		}
		++i;
		fraction += 2 * dy;
		mlx_put_pixel(img, i + x0, j + y0, 0xFF0000FF);
	}
}
