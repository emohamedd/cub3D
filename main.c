/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/11/09 15:43:23 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"


void drawing(t_all_data *data)
{
    int i, j;
    i = 0;

    while (i < ((SIZE_TITLE * data->map->height)))
    {
        j = 0;
        while (j < ((SIZE_TITLE * data->map->width)))
        {
            if (i < ((SIZE_TITLE * data->map->height) / 2))
            {
                mlx_put_pixel(data->img, j, i, ft_pixel(0, 0, 0, 255)); // Color of the sky
            }
            else
            {
                mlx_put_pixel(data->img, j, i, ft_pixel(0, 0, 0, 255)); // Darker blue color for the ground
            }

            j++;
        }
        i++;
    }

    int num_stars = 70; //  ch7almn njma
    int star_radius = 1; // Adjust the size of the stars hnaya

    int k = 0;
    while (k < num_stars)
    {
        int x = rand() % (SIZE_TITLE * data->map->width);
        int y = rand() % ((SIZE_TITLE * data->map->height) / 2);

        int m = -star_radius;
        while (m <= star_radius)
        {
            int n = -star_radius;
            while (n <= star_radius)
            {
                if (m * m + n * n <= star_radius * star_radius)
                {
                    int pixel_x = x + m;
                    int pixel_y = y + n;
                    if (pixel_x >= 0 && pixel_x < (SIZE_TITLE * data->map->width) && pixel_y >= 0 && pixel_y < ((SIZE_TITLE * data->map->height) / 2))
                    {
                        mlx_put_pixel(data->img, pixel_x, pixel_y, ft_pixel(255, 255, 255, 255)); // Draw stars in the sky
                    }
                }
                n++;
            }
            m++;
        }
        k++;
    }

    // shadow effect dyal pixels
    k = 0;
    while (k < num_stars)
    {
        int x = rand() % (SIZE_TITLE * data->map->width);
        int y = rand() % ((SIZE_TITLE * data->map->height) / 2);

        int m = -star_radius;
        while (m <= star_radius)
        {
            int n = -star_radius;
            while (n <= star_radius)
            {
                if (m * m + n * n <= star_radius * star_radius)
                {
                    int pixel_x = x + m;
                    int pixel_y = y + n + ((SIZE_TITLE * data->map->height) / 2);
                    if (pixel_x >= 0 && pixel_x < (SIZE_TITLE * data->map->width) && pixel_y >= 0 && pixel_y < (SIZE_TITLE * data->map->height))
                    {
                                                mlx_put_pixel(data->img, pixel_x, pixel_y, ft_pixel(255, 255, 240, 1)); // Adjust the shadow intensity
                    }
                }
                n++;
            }
            m++;
        }
        k++;
    }

    draw_map(data);
    draw_player(data);
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


