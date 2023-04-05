/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_points.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:18:47 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/05 20:25:48 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**cod_2dcalloc(t_map *map)
{
	int	i;
	t_point	**arr;

	i = 0;
	arr = ft_calloc(map->y + 1, sizeof(t_point *));
	if (!arr)
		exit(0);
	while (i < map->y)
	{
		arr[i] = ft_calloc(map->x + 1, sizeof(t_point));
		if (!arr[i])
			exit(0);
		++i;
	}
	return (arr);
}

t_point	calculate_cod(int x, int y, t_map *map, float angle)
{
	t_point	p;

	if (map->iso == 1)
	{
		angle = 0.523599;
		p.x = map->zoom * 2 * (x * cos(angle) - y * sin(angle)) + map->ori;
		p.y = map->zoom * (x * sin(angle) + y * cos(angle)) + map->ori + (-(map->zoom) * map->map[y][x]);
	}
	else
	{
		p.x = map->zoom * (x * cos(angle) - y * sin(angle)) + map->ori;
		p.y = map->zoom * (x * sin(angle) + y * cos(angle)) + map->ori;
	}
	return (p);
}

t_point	**find_cod(t_map *map)
{
	t_point	**new_cod;
	int		i;
	int		j;

	new_cod = cod_2dcalloc(map);
	if (!new_cod)
		return (NULL);
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			new_cod[i][j] = calculate_cod(j, i, map, 0);
			j++;
		}
		// printf("------------------\ni:%d, j:%d, x:%d y:%d\n", i, j - 1, new_cod[i][j - 1].x, new_cod[i][j - 1].y);
		i++;
	}
	return (new_cod);
}
