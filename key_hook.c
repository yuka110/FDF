/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 19:09:01 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/04 19:29:46 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scroll_zoom(double ydelta, t_map *map)
{
	// Simple up or down detection.
	if (ydelta > 0)
		map->zoom++;
	else if (ydelta < 0)
		map->zoom--;
	return ;
}
