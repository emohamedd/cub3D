/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/11/10 19:01:38 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"


void init_mlx(t_all_data *data)
{
    data->mlx = mlx_init(WIDTH,HEIGHT, "MLX42", true);
    data->img = mlx_new_image(data->mlx, SIZE_TITLE * data->map->width, SIZE_TITLE * data->map->height);
    data->img_minimap = mlx_new_image(data->mlx, 1000, 900);
    
}
void raycasting(t_all_data *data)
{
    
    initialize_player(data);
    init_mlx(data);
    drawing(data);
    mlx_key_hook(data->mlx, &my_keyhook, data);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    mlx_image_to_window(data->mlx, data->img_minimap, 0, 0);
    mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    
}

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
t_all_data *init_data(t_all_data *data)
{
    data = (t_all_data*)malloc(sizeof(t_all_data));
    data->player = (t_player *)malloc(sizeof(t_player));
    data->cord = (t_cord *)malloc(sizeof(t_cord));
    data->map =(t_map *)malloc(sizeof(t_map));
    data->dir = (t_direc *)malloc(sizeof(t_direc));
    return(data);
}

int main(int ac , char **av)
{
    int		fd;
    t_all_data *data;
    data = init_data(data);
    parsing(data, ac, av);
    raycasting(data);
    return EXIT_SUCCESS;
}


