/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/13 23:04:35 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	mlx_t	*win;


	if (argc != 2)
		exit(0);
	map = open_parse(argv);
	print_map(map);
	
	mlx_set_setting(MLX_MAXIMIZED, true);
	win = mlx_init(map->x, map->y, "fdf", true);
	if (!win)
		exit(EXIT_FAILURE);
	straight_line(map, win);
	mlx_loop(win);
	mlx_terminate(win);
	exit(0);
}

void	straight_line(t_map *map, mlx_t	*win)
{
	mlx_image_t	*img;
	int	i;
	int j;

	j = 0;
	img = mlx_new_image(win, 64, 5);
	if (!img)
		exit(EXIT_FAILURE);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	// img->count = 0;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			// mlx_loop_hook(win, ft_hook, win);
			if (map->map[j][i] > map->map[j][i+1])
				brassenham_line(j, map->map[j][i], j, map->map[j][i+1], win);
			if (mlx_image_to_window(win, img, i * 64 + 100, j * 50 + 100) < 0)
				exit(EXIT_FAILURE);
			i++;
		}
		j++;
	}
}

//need to figure out how to take x and y from map
void	brassenham_line(int x0, int y0, int x1, int y1, mlx_t *win)
{
	int	dx;
	int	dy;
	int fraction;
	int i;
	int j;
	mlx_image_t	*img;

	img = mlx_new_image(win, 5, 1);
	if (!img)
		exit(EXIT_FAILURE);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	dx = x1 - x0;
	dy = y1 - y0;
	fraction = 2 * dy - dx;
	i = 0;
	j = 0;
	while (i + x0 < x1)
	{
		if (fraction >= 0)
		{
			j++;
			fraction -= 2 * dx;
		}
		++i;
		fraction += 2 * dy;
		if (mlx_image_to_window(win, img, i * 64 + 100, j * 50 + 100) < 0)
				exit(EXIT_FAILURE);
	}
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
	while (s[i])
	{
		free(s[i]);
		++i;
	}
	free(s);
}
