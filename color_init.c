/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/29 17:39:02 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/02 17:28:22 by yitoh         ########   odam.nl         */
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
	(*c)->max_z = max_zvalue(map->map, map, 0);
	(*c)->min_z= min_zvalue(map->map, map, 0);
	(*c)->height = (*c)->max_z - (*c)->min_z;
	(*c)->cod_dif = (double)((*c)->from - (*c)->to) / (*c)->height;
	printf("height = %d, color per 1 cod=%f\n", (*c)->height, (*c)->cod_dif);
}
	
//0=pink, 1=blue, 2=mint, 3=yellow
long	*set_color(void)
{
	static long	basic_color[5];

	// basic_color = malloc(5 * sizeof(long));
	basic_color[0] = 0xFF99CCFF;
	basic_color[1] = 0x3333FFFF;
	basic_color[2] = 0x99FFCCFF;
	basic_color[3] = 0xFFFF99FF;
	basic_color[4] = '\0';
	return (basic_color);
}

int	max_zvalue(int **s, t_map *map, int height)
{
	int	max;
	int	i;
	int	j;

	max = -2147483648;
	while (s && height < map->y)
	{
		i = 0;
		j = 1;
		while (i + j < map->x)
		{
			if (s[height][i] > s[height][i + j] && max < s[height][i])
				max = s[height][i];
			else if (max < s[height][i + j])
			{
				max = s[height][i + j];
				i = i + j;
				j = i;
			}
			j++;
		}
		height++;
	}
	return (max);
}

int	min_zvalue(int **s, t_map *map, int height)
{
	int	min;
	int	i;
	int	j;

	min = 2147483647;
	while (s && height < map->y)
	{
		i = 0;
		j = 1;
		while (i + j < map->x)
		{
			if (s[height][i] < s[height][i + j] && min > s[height][i])
				min = s[height][i];
			else if (min > s[height][i + j])
			{
				min = s[height][i + j];
				i = i + j;
				j = i;
			}
			j++;
		}
		height++;
	}
	return (min);
}
