/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/29 17:39:02 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/10 17:04:34 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_setup(t_color **c, t_map *map)
{
	*c = malloc(sizeof(t_color));
	if (!(*c))
		exit(EXIT_FAILURE);
	(*c)->rgba = set_color();
	(*c)->from = (*c)->rgba[0];
	(*c)->to = (*c)->rgba[1];
	(*c)->max_z = max_zvalue(map->map, map);
	(*c)->min_z = min_zvalue(map->map, map);
}

//0=pink, 1=blue, 2=mint, 3=yellow
long	*set_color(void)
{
	static long	basic_color[5];

	basic_color[0] = 0xFF99CCFF;
	basic_color[1] = 0x3333FFFF;
	basic_color[2] = 0x99FFCCFF;
	basic_color[3] = 0xFFFF99FF;
	basic_color[4] = '\0';
	return (basic_color);
}

int	max_zvalue(int **s, t_map *map)
{
	int	max;
	int	i;
	int	j;

	max = -2147483648;
	j = 0;
	while (s && j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if (s[j][i] > s[j][i + 1] && max < s[j][i])
				max = s[j][i];
			else if (max < s[j][i + 1])
				max = s[j][i + 1];
			i++;
		}
		j++;
	}
	return (max);
}

int	min_zvalue(int **s, t_map *map)
{
	int	min;
	int	i;
	int	j;

	min = 2147483647;
	j = 0;
	while (s && j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if (s[j][i] < s[j][i + 1] && min > s[j][i])
				min = s[j][i];
			else if (min > s[j][i + 1])
				min = s[j][i + 1];
			i++;
		}
		j++;
	}
	return (min);
}
