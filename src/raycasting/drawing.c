/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:04:14 by houattou          #+#    #+#             */
/*   Updated: 2023/11/10 17:38:30 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void add_stars_to_sky(t_all_data *data)
{
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
}
void add_stars_to_foor(t_all_data *data)
{
    int k = 0;
    int num_stars = 70; //  ch7almn njma
    int star_radius = 1;
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
    
}
void draw_ceil_floor(t_all_data *data)
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
                mlx_put_pixel(data->img, j, i, data->dir->s); // Color of the sky
            }
            else
            {
                mlx_put_pixel(data->img, j, i,  data->dir->f); // Darker blue color for the ground
            }

            j++;
        }
        i++;
    }
    add_stars_to_sky(data);
    add_stars_to_foor(data);
}

void drawing(t_all_data *data)
{
    draw_ceil_floor(data);
    draw_map(data);
    draw_player(data);
}