/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:54:28 by houattou          #+#    #+#             */
/*   Updated: 2023/11/12 22:03:20 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


t_all_data *get_valid_distance(t_all_data *data, float ray_angle)
{
    float  angle;

    
    angle =normalize_angle(ray_angle);
    get_horizontal_intersection(data, ray_angle);
    get_vertical_intersection(data, angle);
    data->player->dis_v = distance_between_points(data->player->x, data->player->y, \
    data->cord->xstep_v, data->cord->ystep_v);
     data->player->dis_h  = distance_between_points(data->player->x, data->player->y, data->cord->xstep_h, data->cord->ystep_h);
    if(  data->player->dis_v  >  data->player->dis_h )
    {
        data->cord->xstep = data->cord->xstep_h;
        data->cord->ystep = data->cord->ystep_h;
        data->cord->distance = data->player->dis_h ;
        data->cord->is_horizontal = TRUE;

    }
    else
    {
        data->cord->xstep = data->cord->xstep_v;
        data->cord->ystep = data->cord->ystep_v;
        data->cord->distance =  data->player->dis_v ;
        data->cord->is_vertical = TRUE;
    }
    data->cord->distance  =  data->cord->distance  * cos(ray_angle - data->player->rotation_angle);
    return(data);
}
t_all_data *draw_rays(t_all_data *data, int id, float ray_angle)
{
    data = get_valid_distance(data, ray_angle);
    float xtx;
   if (data->cord->is_vertical == TRUE)
   {
       xtx = (int)data->cord->ystep % SIZE_TITLE;
   }
   else
   {
       xtx = (int)data->cord->xstep % SIZE_TITLE;
   }



   data->wall_height = (SIZE_TITLE/ data->cord->distance ) * (WIDTH/ 2)/ tan(FOV_ANGLE /2);
   data->exact_wall_height  = data->wall_height;
   if(data->wall_height > HEIGHT)
          data->wall_height = HEIGHT;
 

   data->y_start = (HEIGHT / 2) - (data->wall_height/2);
   data->y_end = (HEIGHT/ 2) + (data->wall_height /2);

   if(  data->player->dis_v >  data->player->dis_h)
   {
        if(data->player->is_ray_facing_up == TRUE)
        {
            //   draw_line(data->img, id, data->y_start, id, data->y_end, ft_pixel(0, 0, 0, 255));
                draw_wall_with_texture(data, id, ray_angle,  data->cord->xstep, data->cord->ystep, xtx, data->textrs.no_texture);
        }
            
        else
        {
            // draw_line(data->img, id, data->y_start, id, data->y_end, ft_pixel(0, 0, 0, 255));
            draw_wall_with_texture(data, id, ray_angle, data->cord->xstep, data->cord->ystep, xtx, data->textrs.so_texture);  // this is the color of the wall
        }
    }
    else
    {
       if(data->player->is_ray_facing_left == TRUE)
        {

            // draw_line(data->img, id, data->y_start, id, data->y_end, ft_pixel(0, 0, 0, 255));
             draw_wall_with_texture(data, id, ray_angle,data->cord->xstep, data->cord->ystep, xtx, data->textrs.we_texture);
        }
        else
        {
            //   draw_line(data->img, id, data->y_start, id, data->y_end, ft_pixel(0, 0, 0, 255));
              draw_wall_with_texture(data, id, ray_angle,data->cord->xstep, data->cord->ystep,   xtx, data->textrs.ea_texture);
        }
    }
   return(data);
}





void start_raycasting(t_all_data *data)
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
