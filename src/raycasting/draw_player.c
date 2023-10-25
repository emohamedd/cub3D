/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:44:34 by houattou          #+#    #+#             */
/*   Updated: 2023/10/25 16:36:34 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void initialize_player(t_all_data *data)
{
    data->player->x = WIDTH / 2;
    data->player->y = HEIGHT / 2;
    data->player->radius = 3;
    data->player->turn_direction = 0;
    data->player->wlk_direction = 0;
    data->player->rotation_angle = (3 * M_PI / 2 );
    data->player->move_speed = 8;
    data->player->rotation_speed = 3* (M_PI / 180);

    data->player->heigth = 1;
    data->player->width = 1;
    data->player->wlk_speed = 100;
    data->player->turn_speed = 45 * (M_PI / 180);
}

void draw_player(t_all_data *data)
{
   int center_x;
   int center_y;
   int radius;
   int x;
   int y;
   center_x = data->player->x;
   center_y = data->player->y;
   radius = data->player->radius;
   x = center_x - radius;
   while (x <= center_x + radius) {
         y = center_y - radius;
        while (y <= center_y + radius) {
            if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= radius * radius) {
                mlx_put_pixel(data->img, x, y, ft_pixel(255, 0, 0, 255));
            }
            y++;
        }
        x++;
    } 
    render_rays(data);
    draw_line(data->img, data->player->x, data->player->y, data->player->x + cos(data->player->rotation_angle)*40, \
    data->player->y + sin(data->player->rotation_angle)*40,   ft_pixel(255, 255, 255, 0));
}
