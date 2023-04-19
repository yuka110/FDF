/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_fdf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 19:09:01 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/19 15:26:11 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(double xdelta, double ydelta, void *map)
{
	xdelta = 0;
	if (ydelta > 0)
	{
		((t_map *)map)->zoom++;
	}
	else if (ydelta < 0)
		((t_map *)map)->zoom--;
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
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		((t_map *)map)->iso = 0;
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		((t_map *)map)->iso = 1;
	transition(keydata, map);
	rotation(keydata, map);
	set_background(map);
	draw_line(map);
	return ;
}

void	transition(mlx_key_data_t keydata, void *map)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		((t_map *)map)->xp += 5;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		((t_map *)map)->xp -= 5;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
		((t_map *)map)->yp -= 5;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
		((t_map *)map)->yp += 5;
	set_background(map);
	draw_line(map);
	return ;
}

void	rotation(mlx_key_data_t keydata, void *map)
{
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_REPEAT)
		((t_map *)map)->xaxis -= 3 * (M_PI / 180);
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_REPEAT)
		((t_map *)map)->xaxis += 3 * (M_PI / 180);
	if (keydata.key == MLX_KEY_4 && keydata.action == MLX_REPEAT)
		((t_map *)map)->yaxis -= 3 * (M_PI / 180);
	if (keydata.key == MLX_KEY_5 && keydata.action == MLX_REPEAT)
		((t_map *)map)->yaxis += 3 * (M_PI / 180);
	if (keydata.key == MLX_KEY_6 && keydata.action == MLX_REPEAT)
		((t_map *)map)->zaxis -= 3 * (M_PI / 180);
	if (keydata.key == MLX_KEY_7 && keydata.action == MLX_REPEAT)
		((t_map *)map)->zaxis += 3 * (M_PI / 180);
	set_background(map);
	draw_line(map);
	return ;
}
