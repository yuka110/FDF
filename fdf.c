/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/02 11:50:50 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		exit(0);
	map = open_parse(argv);
	printf("test\n");
	if (!map)
		exit(0);
	ft_free(map);

}

char	**open_parse(char **argv)
{
	char	**map;
	char	*arr;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(0);
	arr = input_arr(fd);
	map = ft_split(arr, '\n');
	if (!map)
		return (ft_free(map), NULL);
	while (map[i])
	{
		ft_printf("%s", map[i]);
		ft_printf("\n");
		++i;
	}
	printf("%c\n", map[2][3]);
	close(fd);
	return (map);
}

char	*input_arr(int fd)
{
	char	*arr;
	char	*line;

	arr = NULL;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return (free(line), arr);
		line = split_atoi(line);
		if (!line)
			exit(0);
		arr = gnl_strjoin(arr, line);
		if (!arr)
			exit(0);
		free(line);
	}
	return (arr);
}

char	*split_atoi(char *line)
{
	char	**tmp;
	char	*str;
	int		i;

	i = 0;
	tmp = ft_split(line, ' ');
	if (!tmp)
		return (free(line), NULL);
	while (tmp[i])
		++i;
	str = ft_calloc(i, sizeof(int));
	if (!str)
		exit(0);
	i = 0;
	while (tmp[i])
	{
		if (*(tmp[i]) == '\n')
			str[i] = '\n';
		else
			str[i] = ft_atoi(tmp[i]);
		printf("str[i]=%d, ", str[i]);
		++i;
	}
	return (free(line), ft_free(tmp), str);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		++i;
	}
	free(s);
}


// 0 0 0 0 0
// 1 1 1 1 1
// 2 2 2 2 2
// while
// line= 0 0 0 0 0\n
// ft_split
// 0
// 0
// 0
// 0
// 0
// atoi
// arr = 0 0 0 0 0\n

// map 