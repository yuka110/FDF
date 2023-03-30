/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/29 09:50:45 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	mlx_t	*win;
	mlx_image_t	*img;

	if (argc != 2)
		exit(0);
	map = open_parse(argv);
	print_map(map);

	// mlx_set_setting(, true);
	win = mlx_init(1080, 720, "fdf", true);
	if (!win)
		exit(EXIT_FAILURE);
	img = set_background(win);
	draw_line(img, map);

	mlx_loop(win);
	mlx_terminate(win);
	exit(0);
}

mlx_image_t	*set_background(mlx_t *win)
{
	mlx_image_t	*img;

	img = mlx_new_image(win, win->width, win->height);
	if (!img)
		exit(EXIT_FAILURE);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	if (mlx_image_to_window(win, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	return (img);
}


// static void ft_hook(void* param)
// {
// 	const mlx_t* win = param;

// 	ft_printf("WIDTH: %d | HEIGHT: %d\n", win->width, win->height);
// }

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
