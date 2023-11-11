/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:54:28 by houattou          #+#    #+#             */
/*   Updated: 2023/11/11 21:40:56 by houattou         ###   ########.fr       */
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

// t_all_data *get_true_distance(t_all_data *data, float ray_angle)
// {
//     float angle =normalize_angle(ray_angle);

//     draw_horizontal_intersection(data, ray_angle);
   
//    draw_vertical_intersection(data, angle);

//    float dis_v = distance_between_points(data->player->x, data->player->y, 
//    data->cord->xstep_v, data->cord->ystep_v);
//    float dis_h = distance_between_points(data->player->x, data->player->y, data->cord->xstep_h, data->cord->ystep_h);
//      if(dis_v >= dis_h)
//    {
//         data->cord->xstep = data->cord->xstep_h;
//         data->cord->ystep = data->cord->ystep_h;
//         data->cord->distance = dis_h;
//         data->cord->is_horizontal = TRUE;
        
//    }
//    else
//    {
    
//         data->cord->xstep = data->cord->xstep_v;
//         data->cord->ystep = data->cord->ystep_v;
//         data->cord->distance = dis_v;
//         data->cord->is_vertical = TRUE;
//    }
//    return(data);
    
// }
t_all_data *draw_rays(t_all_data *data, int id, float ray_angle)
{
   float angle =normalize_angle(ray_angle);
//    data = get_true_distance(data, ray_angle);
   

    draw_horizontal_intersection(data, ray_angle);
   
   draw_vertical_intersection(data, ray_angle);


   float dis_v = distance_between_points(data->player->x, data->player->y, 
   data->cord->xstep_v, data->cord->ystep_v);
   float dis_h = distance_between_points(data->player->x, data->player->y, data->cord->xstep_h, data->cord->ystep_h);
     if(dis_v >= dis_h)
   {
        data->cord->xstep = data->cord->xstep_h;
        data->cord->ystep = data->cord->ystep_h;
        data->cord->distance = dis_h;
        data->cord->is_horizontal = TRUE;
        
   }
   else
   {
    
        data->cord->xstep = data->cord->xstep_v;
        data->cord->ystep = data->cord->ystep_v;
        data->cord->distance = dis_v;
        data->cord->is_vertical = TRUE;
   }
    // printf("hor is :%f\n", dis_h);
    // printf("ver is :%f\n", dis_v);
   float xtx;
   if (data->cord->is_vertical == TRUE)
   {
       xtx = (int)data->cord->ystep % SIZE_TITLE;
   }
   else
   {
       xtx = (int)data->cord->xstep % SIZE_TITLE;
   }
float new_distance =  data->cord->distance  * cos(ray_angle - data->player->rotation_angle);
draw_line(data->img_minimap, data->player->x*MINIMAP_SCAL_FACTOR, data->player->y*MINIMAP_SCAL_FACTOR, data->cord->xstep*MINIMAP_SCAL_FACTOR, data->cord->ystep*MINIMAP_SCAL_FACTOR, ft_pixel(125, 125, 255, 255));

    data->wall_height = (SIZE_TITLE/ new_distance) * ((SIZE_TITLE * data->map->width)/ 2)/ tan(FOV_ANGLE /2);
    data->exact_wall_height  = data->wall_height;
   if(data->wall_height > SIZE_TITLE * data->map->height )
   {
        data->wall_height = SIZE_TITLE * data->map->height;
   }
 

    data->y_start = ((SIZE_TITLE * data->map->height)/ 2) - (data->wall_height/2);
    data->y_end = ((SIZE_TITLE * data->map->height)/ 2) + (data->wall_height /2);

   if(dis_v > dis_h)
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
    // printf("xstep is :%f\n", data->cord->xstep);
    // printf("ystep is :%f\n", data->cord->ystep);

    // printf("hna %d\n",  data->wall_height);
   return(data);
}

void render_rays(t_all_data *data)
{
    int id;
    id = 0;
    int num_of_rays = SIZE_TITLE * data->map->width;
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


