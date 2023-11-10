/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:44:22 by houattou          #+#    #+#             */
/*   Updated: 2023/11/10 19:42:09 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int is_game_running = FALSE;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

 

void render_single_tile(mlx_image_t *img, int x, int y, unsigned int color)
{
    int i;
    int j;

    j = (y * SIZE_TITLE) * MINIMAP_SCAL_FACTOR;
    while (j < ((y * SIZE_TITLE) + SIZE_TITLE) * MINIMAP_SCAL_FACTOR)
    {
        i = (x * SIZE_TITLE) * MINIMAP_SCAL_FACTOR;
        while (i < ((x * SIZE_TITLE) + SIZE_TITLE) * MINIMAP_SCAL_FACTOR)
        {
            mlx_put_pixel(img, i, j, color);
            i++;
        }
        j++;
    }
}

void draw_map(t_all_data *data)
{
    int i;
    int j;

    j = 0;
    while (j < data->map->height)
    {
        i = 0;
        while (i < data->map->width && data->map->map[j][i])
        {
            if (data->map->map[j][i] == '1')
                render_single_tile(data->img_minimap, i, j, ft_pixel(0, 0, 0, 255));
            else
                render_single_tile(data->img_minimap, i, j, ft_pixel(255, 255, 255, 255));
			i++;	
        }
		j++;
    }
}


