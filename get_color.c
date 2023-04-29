/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 15:56:48 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/29 18:05:37 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	get_color(t_color *c, t_map *map)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	percent = map->light->ratio;
	red = linear_grad(percent, (c->from >> 24) & 0xFF, (c->to >> 24) & 0xFF);
	green = linear_grad(percent, (c->from >> 16) & 0xFF, (c->to >> 16) & 0xFF);
	blue = linear_grad(percent, (c->from >> 8) & 0xFF, (c->to >> 8) & 0xFF);
	return ((red << 24) | (green << 16) | (blue << 8) | 255);
}

int	linear_grad(double percent, int from_color, int to_color)
{
	return ((1 - percent) * from_color + (percent * to_color));
}

double	percent(int curx, int cury, t_point fst, t_point sec)
{
	int		dx;
	int		dy;
	double	ratio;

	dx = (sec.x - fst.x);
	dy = (sec.y - fst.y);
	ratio = 1.0;
	// printf("dx: %d, dy: %d\n", dx, dy);
	// why in this way?
	if (dx > dy)
		ratio = (double)(curx - fst.x) / (sec.x - fst.x);
	else if (dx != 0 && dy != 0)
		ratio = (double)(cury - fst.y) / ((sec.y - fst.y));
	// printf("curx: %d, fstx: %d, secx: %d, cury: %d, fsty: %d, secy: %d, \n", curx, fst.x, sec.x, cury, fst.y, sec.y);
	// printf("percent %f\n", ratio);
	return (ratio);
}

void	color_setup(t_color **c, t_map *map)
{
	*c = malloc(sizeof(t_color));
	if (!(*c))
		exit(0);
	(*c)->rgba = set_color();
	(*c)->from = (*c)->rgba[0];
	(*c)->to = (*c)->rgba[1];
	(*c)->height = max_zvalue(map->map) - min_zvalue(map->map);
	(*c)->cod_dif = (double)((*c)->from - (*c)->to) / (*c)->height;
}
	
//0=pink, 1=blue, 2=mint, 3=yellow
long	*set_color(void)
{
	long	*basic_color;

	basic_color = malloc(5 * sizeof(long));
	basic_color[0] = 0xFF99CCFF;
	basic_color[1] = 0x3333FFFF;
	basic_color[2] = 0x99FFCCFF;
	basic_color[3] = 0xFFFF99FF;
	basic_color[4] = '\0';
	return (basic_color);
}

//counter for color in the map
//when parsing, split based on comma as well
// before bressenham divide the color difference by the height
// //
// 		if (fst.z == map->light->min_z || sec.z == map->light->min_z)
// 			map->light->ratio = 0.0;
// 		else if (fst.z == map->light->min_z || sec.z == map->light->min_z)
// 			map->light->ratio = 1.0;