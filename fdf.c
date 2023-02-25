/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/25 18:32:38 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		exit(0);
	map = open_parse(argv);
	if (!map)
		exit(0);
	ft_free(map);

}

char	**open_parse(char **argv)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	line = "\0";
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(0);
	while (line)
	{
		//need to figure out how to count number of new line
		line = get_next_line(fd);
		++i;
		free (line);
	}
	map = ft_calloc(i, sizeof(char *));
	if (!map)
		return (ft_free(map), NULL);
	i = 0;
	//map[i] condition doesn't let it go in the while loop
	while (map[i])
	{
		printf("test2\n");
		map[i] = get_next_line(fd);
		if (!map[i])
			return (ft_free(map), NULL);
		printf("test2\n");
		ft_printf("%s", map[i]);
		++i;
	}
	close(fd);
	return (map);
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
