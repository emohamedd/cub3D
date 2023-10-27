/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:54:28 by houattou          #+#    #+#             */
/*   Updated: 2023/10/27 12:23:37 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float distance_between_points(float x1, float y1, float x2, float y2)
{
    return(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
float normalize_angle(float angle)
{
    angle = remainderf(angle, M_PI * 2);
    if(angle < 0)
        angle += 2 * M_PI;
    return(angle);
}





// void draw_vertical_intersection(t_all_data *data, float ray_angle)
// {
//     bool is_ray_facing_left;
//     int sign = 1;
   

//     ray_angle = normalize_angle(ray_angle);
//     is_ray_facing_left = (ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI);
//     data->cord->xstep = ceil(data->player->x / SIZE_TITLE) * SIZE_TITLE;

//     if (is_ray_facing_left)
//     {
//         data->cord->xstep -= SIZE_TITLE; 
//         sign = -1;
//     }
//     if(!is_ray_facing_left)
//     {
//         sign = 1;
//     }

//     data->cord->ystep = data->player->y + (data->player->x - data->cord->xstep) * tan(ray_angle);
    
//     while(((data->cord->xstep >= 0 && data->cord->xstep < WIDTH  && floor(data->cord->ystep / SIZE_TITLE) <= HEIGHT_MAP && floor(data->cord->xstep / SIZE_TITLE) <= WIDTH_MAP
//     && data->cord->ystep >= 0 && data->cord->ystep < HEIGHT)))
//     {
//         if ((is_ray_facing_left && is_has_wall(data, data->cord->xstep - SIZE_TITLE, data->cord->ystep)) ||
//             (!is_ray_facing_left && is_has_wall(data, data->cord->xstep, data->cord->ystep)))
//             {
                
//                 draw_line(data->img, data->player->x, data->player->y, data->cord->xstep, data->cord->ystep, ft_pixel(255, 255, 0, 255));
//                         break;
//             }

//         data->cord->xstep += sign * SIZE_TITLE;
//         data->cord->ystep += sign / tan(ray_angle);
//     }
//     printf("xstep :%d\n", data->cord->xstep);
//     printf("ystep :%d\n", data->cord->ystep);
// }




void render_rays(t_all_data *data)
{
    int id;
    id = 0;
    int num_of_rays = WIDTH ;
    float ray_angle = normalize_angle(data->player->rotation_angle - (FOV_ANGLE / 2));
    while(id < num_of_rays)
    {
        draw_horizontal_intersection(data, ray_angle);
        // draw_vertical_intersection(data, ray_angle);    
        ray_angle += FOV_ANGLE / num_of_rays;
        id++;
    }
}


