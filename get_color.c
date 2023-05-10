/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 15:56:48 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/10 11:36:13 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(t_color *c, double percent)
{
	int		red;
	int		green;
	int		blue;

	red = linear_grad(percent, (c->from >> 24) & 0xFF, (c->to >> 24) & 0xFF);
	green = linear_grad(percent, (c->from >> 16) & 0xFF, (c->to >> 16) & 0xFF);
	blue = linear_grad(percent, (c->from >> 8) & 0xFF, (c->to >> 8) & 0xFF);
	return ((red << 24) | (green << 16) | (blue << 8) | 255);
}

int	get_color2(t_point fst, t_point sec, double percent)
{
	int		red;
	int		green;
	int		blue;

	red = linear_grad(percent, (fst.color >> 24) & 0xFF, (sec.color >> 24) & 0xFF);
	green = linear_grad(percent, (fst.color >> 16) & 0xFF, (sec.color >> 16) & 0xFF);
	blue = linear_grad(percent, (fst.color >> 8) & 0xFF, (sec.color >> 8) & 0xFF);
	return ((red << 24) | (green << 16) | (blue << 8) | 255);
}


int	linear_grad(double percent, int from_color, int to_color)
{
	return ((1 - percent) * from_color + (percent * to_color));
}

//percentage gets more than 1 whyyyyy
double	percent(int curx, int cury, t_point *fst, t_point *sec)
{
	int		dx;
	int		dy;
	double	p_color;

	dx = ((*sec).x - (*fst).x);
	dy = ((*sec).y - (*fst).y);
	p_color = (*fst).ratio;
	// why in this way?
	if((*fst).ratio == (*sec).ratio)
		return ((*fst).ratio);
	if (dx > dy)
		p_color = (double)(curx - (*fst).x) / ((*sec).x - (*fst).x);
	else if (dx != 0 || dy != 0)
		p_color = (double)(cury - (*fst).y) / (((*sec).y - (*fst).y));
	// printf("final double:%f\n", p_color);
	return (p_color);
}


// before bressenham divide the color difference by the height
