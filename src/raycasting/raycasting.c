/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:54:28 by houattou          #+#    #+#             */
/*   Updated: 2023/11/02 13:56:01 by houattou         ###   ########.fr       */
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


t_all_data *draw_rays(t_all_data *data, int id, float ray_angle)
{
    t_all_data *ptr;
   float angle =normalize_angle(ray_angle);

   data = draw_horizontal_intersection(data, ray_angle);
   ptr = draw_vertical_intersection(data, angle);
   float dis_v = distance_between_points(data->player->x, data->player->y, 
   data->cord->xstep_v, data->cord->ystep_v);
   float dis_h = distance_between_points(data->player->x, data->player->y, data->cord->xstep_h, data->cord->ystep_h);
   if(dis_v > dis_h)
   {
        data->cord->xstep = data->cord->xstep_h;
        data->cord->ystep = data->cord->ystep_h;
        data->cord->distance = dis_h;
   }
   else
   {
    
        data->cord->xstep = data->cord->xstep_v;
        data->cord->ystep = data->cord->ystep_v;
        data->cord->distance = dis_v;
   }
   draw_line(data->img, data->player->x*MINIMAP_SCAL_FACTOR, data->player->y*MINIMAP_SCAL_FACTOR, data->cord->xstep*MINIMAP_SCAL_FACTOR, data->cord->ystep*MINIMAP_SCAL_FACTOR, ft_pixel(255, 0, 255, 255));
//    printf("distance virtcal %f\n", dis_v);
//       printf("distance horizontal %f\n", dis_h);
//    data->cord->distance = distance_between_points(data->player->x, data->player->y, data->cord->xstep, data->cord->ystep);
//    printf("small distance %f\n", data->cord->distance);

   float wall_height = (SIZE_TITLE/ data->cord->distance) * (WIDTH/ 2)/ tan(FOV_ANGLE /2);
   if(wall_height > HEIGHT)
          wall_height = HEIGHT;
   printf("wall_height is %f\n", wall_height);

   float y_start = (WIDTH / 2) - (wall_height/2);
   float y_end = (WIDTH / 2) + (wall_height /2);

   
   draw_line(data->img, id, y_start, id, y_end, ft_pixel(255, 255, 255, 255) );
   return(data);
}






void render_rays(t_all_data *data)
{
    int id;
    id = 0;
    int num_of_rays = WIDTH ;
    float	wall_height;
    float ray_distance;
    float ray_angle = normalize_angle(data->player->rotation_angle - (FOV_ANGLE / 2));
    while(id < num_of_rays)
    {
      

        data = draw_rays(data, id, ray_angle);
        ray_angle += normalize_angle( FOV_ANGLE / num_of_rays);
        id++;
    }
}


