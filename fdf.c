/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/03 18:13:06 by yitoh         ########   odam.nl         */
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
//once it's done, possibly remove this function
char	**open_parse(char **argv)
{
	int	**map;
	int	i;
	int	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(0);
	map = input_arr(fd);
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
	int		**arr;
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
		arr = double_strjoin(arr, line);
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

char	**double_strjoin(char **s1, char *s2)
{
	int			**arr;
	int			s2_len;
	static int	i;

	s2_len = ft_strlen(s2);
	if (!s1)
		arr[0] = gnl_substr(s2, 0, s2_len);
	else
	{
		arr[i] = ft_calloc(s2_len + 1, sizeof(int));
		if (!s1)
			return (ft_free(s1), NULL);
		gnl_memmove(s1[i], s2, s2_len);
	}
	i++;
	return (ft_free(s1), s1);
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

// 1. open file, get_next_line
// 2. split the line by space
// 3. put them into a struct map.num[i][j] = number
// 4. increament i and repeat the process
// POINT: research difference between struct and linked list