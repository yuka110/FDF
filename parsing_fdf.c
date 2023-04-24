/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_fdf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 15:32:01 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/24 16:46:37 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*open_parse(char **argv)
{
	t_map	*map;
	char	**tmp;
	int		**map_tmp;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(0);
	map = init_null();
	if (!map)
		exit(0);
	color_setup(&(map->light), map);
	tmp = read_split(fd, map);
	if (!tmp)
		exit(0);
	map_tmp = ft_2dcalloc(map, tmp);
	if (!map_tmp)
		exit(0);
	input_arr(&map, tmp, map_tmp);
	close(fd);
	return (map);
}

t_map	*init_null(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(0);
	map->win = NULL;
	map->img = NULL;
	map->map = NULL;
	map->cod = NULL;
	map->light = NULL;
	map->x = 0;
	map->y = 0;
	map->iso = 0;
	map->zoom = 5;
	map->xaxis = 0;
	map->yaxis = 0;
	map->zaxis = 0.523599;
	map->xp = 0;
	map->yp = 0;
	return (map);
}

char	**read_split(int fd, t_map *map)
{
	char	*line;
	char	*tmp;
	char	**arr_2d;
	int		i;

	line = NULL;
	tmp = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = gnl_strjoin(tmp, line);
		if (!tmp)
			exit(0);
		++i;
		free(line);
	}
	map->y = i;
	map->light->cod_dif = max_z(tmp) - min_z(tmp);
	arr_2d = ft_split(tmp, '\n');
	if (!arr_2d)
		exit(0);
	return (free(tmp), arr_2d);
}

int	**ft_2dcalloc(t_map *map, char **tmp)
{
	int	i;
	int	**arr;

	i = 0;
	while (tmp[0][i])
	{
		if (tmp[0][i] != ' ' && tmp[0][i] != '-'
			&& (tmp[0][i + 1] == ' ' || tmp[0][i + 1] == '\0'))
			map->x++;
		++i;
	}
	arr = ft_calloc(map->y + 1, sizeof(int *));
	if (!arr)
		exit(0);
	i = 0;
	while (i < map->y)
	{
		arr[i] = ft_calloc(map->x + 1, sizeof(int));
		if (!arr[i])
			exit(0);
		++i;
	}
	printf("map.x = %d, map.y = %d\n", map->x, map->y);
	return (arr);
}

void	input_arr(t_map **m, char **tmp, int **map_tmp)
{
	char	**one_line;
	t_map	*map;
	int		i;
	int		j;

	map = *m;
	i = 0;
	while (tmp[i])
	{
		one_line = ft_split(tmp[i], ' ');
		if (!one_line)
			exit(0);
		j = 0;
		while (j < map->x && one_line[j])
		{
			map_tmp[i][j] = ft_atoi(one_line[j]);
			j++;
		}
		ft_free(one_line);
		++i;
	}
	map->map = map_tmp;
	return (ft_free(tmp));
}

