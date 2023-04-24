/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 15:56:48 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/24 16:45:56 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_setup(t_color **c, t_map *map)
{
	*c = malloc(sizeof(t_color));
	if (!(*c))
		exit(0);
	(*c)->rgba = set_rgba();
	(*c)->from = (*c)->rgba[3];
	(*c)->to = (*c)->rgba[1];
}

int	*set_rgba(void)
{
	int	basic_color[4];
	//0=r, 1=g, 2=b, 3=a
	basic_color[0] = 4278190080;
	basic_color[1] = 16711680;
	basic_color[2] = 65280;
	basic_color[3] = 255;
	basic_color[4] = '\0';
	return (basic_color);
}

int	max_z(char *line)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (line[i + j])
	{
		if (line[i] > line[i + j])
		{
			max = line[i];
			j++;
		}
		else
		{
			max = line[i + j];
			i = i + j;
			j = 1;
		}
	}
	return (max);
}

int	min_z(char *line)
{
	int	min;
	int	i;
	int	j;

	i = 0;
	j = 1;
	min = 0;
	while (line[i + j])
	{
		if (line[i] < line[i + j])
		{
			min = line[i];
			j++;
		}
		else
		{
			min = line[i + j];
			i = i + j;
			j = 1;
		}
	}
	return (min);
}


/*
1. calculate the distance between the bottom and the top of the map (z value)
2. calculate the difeerence of the color that you want to make gradient
3. divide 1 by 2 to determine the color


*/