/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 15:56:48 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/10 16:54:00 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(t_color *c, double percent)
{
	int		r;
	int		g;
	int		b;

	r = linear_grad(percent, (c->from >> 24) & 0xFF, (c->to >> 24) & 0xFF);
	g = linear_grad(percent, (c->from >> 16) & 0xFF, (c->to >> 16) & 0xFF);
	b = linear_grad(percent, (c->from >> 8) & 0xFF, (c->to >> 8) & 0xFF);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

int	get_color2(t_point fst, t_point sec, double ratio)
{
	int		r;
	int		g;
	int		b;

	r = linear_grad(ratio, (sec.color >> 24) & 0xFF, (fst.color >> 24) & 0xFF);
	g = linear_grad(ratio, (sec.color >> 16) & 0xFF, (fst.color >> 16) & 0xFF);
	b = linear_grad(ratio, (sec.color >> 8) & 0xFF, (fst.color >> 8) & 0xFF);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

int	linear_grad(double percent, int from_color, int to_color)
{
	return ((percent * from_color) + ((1 - percent) * to_color));
}

double	percent(int curx, int cury, t_point *fst, t_point *sec)
{
	int		dx;
	int		dy;
	double	p_color;

	dx = ((*sec).x - (*fst).x);
	dy = ((*sec).y - (*fst).y);
	p_color = (*fst).ratio;
	if ((*fst).ratio == (*sec).ratio)
		return ((*fst).ratio);
	if (dx > dy)
		p_color = (double)(curx - (*fst).x) / ((*sec).x - (*fst).x);
	else if (dx != 0 || dy != 0)
		p_color = (double)(cury - (*fst).y) / (((*sec).y - (*fst).y));
	return (p_color);
}
