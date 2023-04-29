/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_gradient.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/29 17:39:02 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/29 18:04:13 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	max_zvalue(int **s)
{
	int	max;
	int	height;
	int	i;
	int	j;

	height = 0;
	while (s[height])
	{
		i = 0;
		j = 1;
		while (s[height][i + j])
		{
			if (s[height][i] > s[height][i + j])
				max = s[i];
			else
			{
				max = s[i + j];
				i = i + j;
				j = i;
			}
			j++;
		}
		height++;
	}
	printf("max=%d, ", max);
	return (max);
}

int	min_zvalue(int **s)
{
	int	min;
	int	height;
	int	i;
	int	j;

	height = 0;
	while (s[height])
	{
		i = 0;
		j = 1;
		while (s[height][i + j])
		{
			if (s[height][i] < s[height][i + j])
				min = s[i];
			else
			{
				min = s[i + j];
				i = i + j;
				j = i;
			}
			j++;
		}
		height++;
	}
	printf("min=%d\n", min);
	return (min);
}