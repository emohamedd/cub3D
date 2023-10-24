// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   raycasting.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/10/23 12:54:28 by houattou          #+#    #+#             */
// /*   Updated: 2023/10/24 18:27:11 by houattou         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../include/cub3d.h"


// float distance_between_points(float x1, float y1, float x2, float y2)
// {
//     return(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
// }
// float normalize_angle(float angle)
// {
//     angle = remainderf(angle, M_PI * 2);
//     if(angle < 0)
//         angle += 2 * M_PI;
//     return(angle);
// }
// // t_all_data finding_grid_insertion(t_all_data *data)
// // {
    
// // }
// t_all_data finding_cordination_of_hit_wall_hor(t_all_data *data, float ray_angle)
// {
//     float x_inter;
//     float y_inter;
    
//     y_inter = (data->player->y / SIZE_TITLE ) * SIZE_TITLE;

//     x_inter = (data->player->x) + (data->player->y - y_inter)/ tan(ray_angle);

//     while(x_inter < WIDTH && y_inter < HEIGHT)
//     {
//         if()
//     }
    
    
    
// }
// void render_rays(t_all_data *data)
// {
//     int id;
//     id = 0;
//     int num_of_rays = WIDTH;
//     float ray_angle = normalize_angle(data->player->rotation_angle - (FOV_ANGLE / 2));
//     while(id < num_of_rays)
//     {
//         // if(check_if_have_wall(data,(data->player->x + cos(ray_angle) * 80), data->player->y + sin(ray_angle) * 80) != TRUE)
//              draw_line(data->img, data->player->x, data->player->y, data->player->x + cos(ray_angle)*80, data->player->y + sin(ray_angle)*80,  ft_pixel(255, 255, 0, 255));
//         ray_angle += FOV_ANGLE / num_of_rays;
//         id++;
//     }
// }


