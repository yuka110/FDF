/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 17:20:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/03/09 16:02:55 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*map;
	mlx_t	*mlx;
	mlx_image_t	*img;

	if (argc != 2)
		exit(0);
	map = open_parse(argv);
	print_map(map);
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(map->x, map->y, "fdf", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, map->x, map->y);
	if (!img)
		exit(EXIT_FAILURE);
	//mlx_loop_hook(mlx, ft_hook, mlx);
	ft_memset(img->pixels, 256, img->width * img->height * sizeof(int32_t));
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit(0);
}

// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

void	print_map(t_fdf *map)
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
