/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/10 11:43:36 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	f(void)
{
	system("leaks -q fdf");
}

int	main(int argc, char **argv)
{
	t_map	*map;

	atexit(f);
	if (argc != 2)
		exit(0);
	map = open_parse(argv);
	if (!map)
		exit(EXIT_FAILURE);
	// print_map(map);
	map->win = mlx_init(1080, 720, "fdf", true);
	if (!map->win)
		exit(EXIT_FAILURE);
	map->img = mlx_new_image(map->win, map->win->width, map->win->height);
	if (!map->img)
		exit(EXIT_FAILURE);
	set_background(map);
	set_menu(map->win);
	draw_line(map);

	// mlx_key_hook(map->win, &key_input, map);
	mlx_scroll_hook(map->win, &zoom, map);
	mlx_loop_hook(map->win, &new_key_hook, map);
	mlx_loop(map->win);
	mlx_terminate(map->win);
	exit(EXIT_SUCCESS);
}

void	set_background(void *map)
{
	mlx_image_t	*img;
	mlx_t		*win;
	uint32_t	i;
	uint32_t	j;

	i = 30;
	win = ((t_map *)map)->win;
	img = ((t_map *)map)->img;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			mlx_put_pixel(img, j, i, 0x000000FF);
			++j;
		}
		++i;
	}
	if (mlx_image_to_window(win, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	((t_map *)map)->img = img;
	// if (mlx_image_to_window(win, set_menu(win), 0, 0) < 0)
	// 	exit(EXIT_FAILURE);
	return ;
}

void	set_menu(mlx_t *win)
{
	const char	*menu;

	menu = "[Zoom] Scroll, [Rotation] x-axis: 2/3 y-axis: 4/5 \
			z-axis: 6/7, [Translation] Arrows, [Close] ESC";
	if (mlx_put_string(win, menu, 10, 10) < 0)
		exit(EXIT_FAILURE);
}


// void	print_map(t_map *map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < map->y)
// 	{
// 		j = 0;
// 		while (j < map->x)
// 		{
// 			printf("%d ",map->map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

