/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:44:34 by houattou          #+#    #+#             */
/*   Updated: 2023/11/06 12:56:03 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void initialize_player(t_all_data *data)
{
    data->player->radius = 3;
    data->player->turn_direction = 0;
    data->player->wlk_direction = 0;
    data->player->rotation_angle = (3 * M_PI / 2);
    data->player->move_speed = 18;
    data->player->rotation_speed = 3* (M_PI / 180);

    data->player->heigth = 1;
    data->player->width = 1;
    data->player->wlk_speed = 100;
    data->player->turn_speed = 45 * (M_PI / 180);

    for (int i = 0; i < data->map->height; i++)
    {
        for(int j = 0;  j < data->map->height;j++)
        {
            if(data->map->map[j][i] == 'E')
            {
                    data->player->x = (i  * SIZE_TITLE);
                    data->player->y = (j * SIZE_TITLE);
                    break;
                
            }
                
        }
    }
}

void draw_player(t_all_data *data)
{
   float center_x;
   float center_y;
   float radius;
  float x;
  float y;
   center_x = data->player->x;
   center_y = data->player->y;
   radius = data->player->radius;
   x = center_x - radius;
   while (x <= center_x + radius) {
         y = center_y - radius;
        while (y <= center_y + radius) {
            if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= radius * radius) {
                mlx_put_pixel(data->img, x*MINIMAP_SCAL_FACTOR, y*MINIMAP_SCAL_FACTOR , ft_pixel(255, 0, 0, 255));
            }
            y++;
        }
        x++;
    } 
    render_rays(data);

}
