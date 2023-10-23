/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:54:28 by houattou          #+#    #+#             */
/*   Updated: 2023/10/23 18:05:25 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



float normalize_angle(float angle)
{
    angle = remainderf(angle, M_PI * 2);
    if(angle < 0)
        angle += 2 * M_PI;
    return(angle);
}
		
void render_rays(t_all_data *data)
{
    int id;
    id = 0;
    int num_of_rays = WIDTH;
    float ray_angle = normalize_angle(data->player->rotation_angle - (FOV_ANGLE / 2));
    while(id < num_of_rays)
    {
        draw_line(data->img, data->player->x, data->player->y, data->player->x + cos(ray_angle)*80, data->player->y + sin(ray_angle)*80,  ft_pixel(255, 255, 0, 255));
        ray_angle += FOV_ANGLE / num_of_rays;
        id++;
    }
}


