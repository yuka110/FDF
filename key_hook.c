/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 19:09:01 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/05 20:25:32 by yitoh         ########   odam.nl         */
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
