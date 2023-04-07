/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 19:09:01 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/07 14:58:34 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_transit(double xdelta, double ydelta, void *m)
{
	// Simple up or down detection.
	t_map	*map;
	
	map = (t_map *)m;
	if (ydelta > 0)
	{
		map->zoom++;
	}
	else if (ydelta < 0)
		map->zoom--;
	if (xdelta > 0)
		map->ori += 10;
	else if (xdelta < 0)
		map->ori -= 10;
	set_background(map);
	draw_line(map);
	return ;
}

void	key_input(mlx_key_data_t keydata, void *map)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(((t_map *)map)->win);
		exit (0);
	}
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		((t_map *)map)->iso = 1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
	{
		((t_map *)map)->iso = 0;
		((t_map *)map)->angle += 5 * (M_PI/180);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
	{
		((t_map *)map)->iso = 0;
		((t_map *)map)->angle -= 5 * (M_PI/180);
	}
	set_background(map);
	draw_line(map);
	return ;
}
