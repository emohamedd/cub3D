/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:54:28 by houattou          #+#    #+#             */
/*   Updated: 2023/10/28 18:14:52 by houattou         ###   ########.fr       */
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


void draw_rays(t_all_data *data, float ray_angle)
{
    t_all_data *ptr;
   float angle =normalize_angle(ray_angle);
//    printf("ray angle %f\n", ray_angle);
//    printf("angle : %f\n", angle);
   data = draw_horizontal_intersection(data, ray_angle);
   ptr = draw_vertical_intersection(data, angle);
   
    // printf(" after ray angle %f\n", ray_angle);
//    printf(" after angle : %f\n", angle);
//    data = draw_vertical_intersection(data,angle); 
//    printf("data->player->x : %f\n", data->player->x);
//    printf("data->player->y : %f\n", data->player->y);
//    printf("data->cord->xstep : %d\n", data->cord->xstep_v);
//    printf("data->cord->ystep : %d\n", data->cord->ystep_v);

   
    
   float dis_v = distance_between_points(data->player->x, data->player->y, data->cord->xstep_v, data->cord->ystep_v);
   float dis_h = distance_between_points(data->player->x, data->player->y, data->cord->xstep_h, data->cord->ystep_h);
   if(dis_v > dis_h)
   {
        data->cord->xstep = data->cord->xstep_h;
        data->cord->ystep = data->cord->ystep_h;
   }
   else
   {
        data->cord->xstep = data->cord->xstep_v;
        data->cord->ystep = data->cord->ystep_v;
    
   }
   draw_line(data->img, data->player->x, data->player->y, data->cord->xstep, data->cord->ystep, ft_pixel(255, 0, 255, 255));
    
//    printf("div_v %f\n", dis_v);
//    printf("div_h %f\n", dis_h);

    
}
void render_rays(t_all_data *data)
{
    int id;
    id = 0;
    int num_of_rays = WIDTH ;
    float ray_angle = normalize_angle(data->player->rotation_angle - (FOV_ANGLE / 2));
    while(id < num_of_rays)
    {

        draw_rays(data, ray_angle);
        ray_angle += normalize_angle( FOV_ANGLE / num_of_rays);
        id++;
    }
}


