/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_fdf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 19:09:01 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/10 17:05:09 by yitoh         ########   odam.nl         */
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

void	new_key_hook(void *map)
{
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_ESCAPE))
	{
		mlx_terminate(((t_map *)map)->win);
		exit (EXIT_FAILURE);
	}
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_O))
		(((t_map *)map)->iso) = 0;
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_I))
		((t_map *)map)->iso = 1;
	new_transition(map);
	new_rotation(map);
	set_background(map);
	draw_line(map);
	return ;
}

void	new_transition(void *map)
{
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_RIGHT))
		((t_map *)map)->xp += 5;
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_LEFT))
		((t_map *)map)->xp -= 5;
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_UP))
		((t_map *)map)->yp -= 5;
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_DOWN))
		((t_map *)map)->yp += 5;
	set_background(map);
	draw_line(map);
	return ;
}

void	new_rotation(void *map)
{
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_2))
		((t_map *)map)->xaxis -= 3 * (M_PI / 180);
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_3))
		((t_map *)map)->xaxis += 3 * (M_PI / 180);
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_4))
		((t_map *)map)->yaxis -= 3 * (M_PI / 180);
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_5))
		((t_map *)map)->yaxis += 3 * (M_PI / 180);
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_6))
		((t_map *)map)->zaxis -= 3 * (M_PI / 180);
	if (mlx_is_key_down(((t_map *)map)->win, MLX_KEY_7))
		((t_map *)map)->zaxis += 3 * (M_PI / 180);
	set_background(map);
	draw_line(map);
	return ;
}
