/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/11/06 12:54:58 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"


void drawing(t_all_data *data)
{
    int i;
    int j;
    i = 0;
    while(i < ((SIZE_TITLE * data->map->height)) )
    {
        j = 0;
        while(j < ((SIZE_TITLE * data->map->width)) )
        {
            if( i < ((SIZE_TITLE * data->map->height)/ 2) )
                mlx_put_pixel(data->img, j, i,ft_pixel(0, 119, 190, 255));
            else
                mlx_put_pixel(data->img, j, i,ft_pixel(0, 100, 0, 255));
            j++;    
                    
        }
        i++;
    }
    draw_map(data);
    draw_player(data);
    render_rays(data);
}

void raycasting(t_all_data *data)
{
    
    initialize_player(data);
    data->mlx = mlx_init(WIDTH ,HEIGHT , "MLX42", true);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    drawing(data);
    draw_map(data);
    draw_player(data);
 

    mlx_key_hook(data->mlx, &my_keyhook, data);
    mlx_image_to_window(data->mlx, data->img, 0, 0);

    mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    
}
int main(int ac , char **av)
{
    int		fd;
    t_all_data *data = (t_all_data*)malloc(sizeof(t_all_data));
    data->player = (t_player *)malloc(sizeof(t_player));
    data->cord = (t_cord *)malloc(sizeof(t_cord));
    data->map =(t_map *)malloc(sizeof(t_map));
    data->dir = (t_direc *)malloc(sizeof(t_direc));


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
	}
   raycasting(data);
    return EXIT_SUCCESS;
}


