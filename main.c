/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:14:58 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/11 11:38:04 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "mlx.h"

void	draw_map(t_map *map)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, map->width, map->height, "Cub3D");
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			else if (map->map[y][x] == '0')
				mlx_pixel_put(mlx, win, x, y, 0x000000);
			else if (map->map[y][x] == 'N')
				mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
}

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
	draw_map(&map);
	return (0);
}
