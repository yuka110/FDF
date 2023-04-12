/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/04/12 14:40:59 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		exit(0);
	map = open_parse(argv);
	//print_map(map);

	map->win = mlx_init(1080, 720, "fdf", true);
	if (!map->win)
		exit(EXIT_FAILURE);
	set_background(map);
	draw_line(map);
	
	mlx_scroll_hook(map->win, &zoom, map);
	mlx_key_hook(map->win, &key_input, map);
	mlx_loop(map->win);
	mlx_terminate(map->win);
	exit(0);
}

void	set_background(void *map)
{
	mlx_image_t	*img;
	mlx_t		*win;

	win = ((t_map *)map)->win;
	img = mlx_new_image(win, win->width, win->height);
	if (!img)
		exit(EXIT_FAILURE);
	ft_memset(img->pixels, 254, img->width * img->height * sizeof(int32_t));
	if (mlx_image_to_window(win, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	((t_map *)map)->img = img;
	return ;
}

void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			printf("%d ",map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free(s[i]);
		++i;
	}
	free(s);
}
