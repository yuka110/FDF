/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_fdf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 15:32:01 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/03 14:56:13 by yitoh         ########   odam.nl         */
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
	tmp = read_split(fd, map);
	if (!tmp)
		exit(0);
	map_tmp = ft_2dcalloc(map, tmp);
	if (!map_tmp)
		exit(0);
	map = input_arr(map, tmp, map_tmp);
	close(fd);
	return (map);
}

t_map	*init_null(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(0);
	map->cod = NULL;
	map->map = NULL;
	map->x = 0;
	map->y = 0;
	map->iso = 1;
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
	arr_2d = ft_split(tmp, '\n');
	if (!arr_2d)
		exit(0);
	return (free(tmp), arr_2d);
}

int	**ft_2dcalloc(t_map *map, char **tmp)
{
	int	i;
	int	j;
	int	**arr;

	i = 0;
	j = 0;
	while (tmp[0][i])
	{
		if (tmp[0][i] != ' ' && tmp[0][i] != '-')
			++j;
		++i;
	}
	map->x = j;
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

t_map	*input_arr(t_map *map, char **tmp, int **map_tmp)
{
	char	**one_line;
	int		i;
	int		j;

	i = 0;
	while (tmp[i])
	{
		one_line = ft_split(tmp[i], ' ');
		if (!one_line)
			exit(0);
		j = 0;
		while (j < map->x)
		{
			map_tmp[i][j] = ft_atoi(one_line[j]);
			j++;
		}
		ft_free(one_line);
		++i;
	}
	map->map = map_tmp;
	return (ft_free(tmp), map);
}

