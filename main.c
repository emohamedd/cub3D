/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:14:58 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/12 12:13:23 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// drawing the map in the window 

// void	draw_block(t_map *map, mlx_image_t *img, int x, int y, int color)
// {
// 	int i;
// 	int j;
// 	int mini_wi;
// 	float val;
// 	// int mini_he;

// 	mini_wi =  1500 / map->width;
// 	// mini_he =  1000 / map->height;
// 	val = 0.3;
// 	i = 0;
// 	while (i < mini_wi)
// 	{
// 		j = 0;
// 		while (j < mini_wi)
// 		{
// 			mlx_put_pixel(img, ((x * mini_wi) + j) * val , ((y * mini_wi) + i) * val , color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_map(t_map *map)
// {
// 	int x;
// 	int y;
// 	mlx_t *mlx = mlx_init(2000, 1500, "Cub3D", 1);
// 	mlx_image_t *img = mlx_new_image(mlx, 1000, 1000);
// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			if (map->map[y][x] == '1')
// 				draw_block(map, img, x, y, BLACK);
// 			else if (map->map[y][x] == '0')
// 				draw_block(map, img, x, y, WHITE);
// 			else if (map->map[y][x] == 'N')
// 				draw_block(map, img, x, y, RED);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_image_to_window(mlx, img, 0, 0);
// 	mlx_loop(mlx);
// }

int	main(int ac, char **av)
{
	t_map	map;
	t_direc	dir;
	int		fd;

	if (ac != 2)
		print_err("Wrong number of arguments\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		check_file_cub(av[1]);
		if (fd == -1)
		{
			print_err("File not found\n");
			exit(1);
		}
		else
			readfile(fd, &map, &dir);
	}
	// draw_map(&map);
	return (0);
}
