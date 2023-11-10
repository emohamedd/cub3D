
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:06:06 by houattou          #+#    #+#             */
/*   Updated: 2023/11/10 22:12:26 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

void player_direction(t_map *map)
{
    int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'N')
				map->direction = NO;
			else if (map->map[y][x] == 'S')
				map->direction = SO;
			else if (map->map[y][x] == 'W')
				map->direction = WE;
			else if (map->map[y][x] == 'E')
				map->direction = EA;
			x++;
		}
		y++;
	}
}
void parsing(t_all_data *data, int ac , char **av)
{
    int fd;
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
			readfile(fd, data->map, data->dir);
        load_textures(data);
        player_direction(data->map);
	}
    
}