/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:54:28 by houattou          #+#    #+#             */
/*   Updated: 2023/10/25 16:39:28 by houattou         ###   ########.fr       */
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
void	draw_horizontal_intersection(t_all_data *mlx, float ray_angle)
{
	
	bool	is_ray_facing_up;
    int sign;

    sign = 1;
     mlx->cord->ystep = 0;
    mlx->cord->ystep = 0;
	is_ray_facing_up = ray_angle > M_PI && ray_angle < 2 * M_PI;
	mlx->cord->ystep = floor(mlx->player->y / SIZE_TITLE) * SIZE_TITLE;
    if(is_ray_facing_up)
        sign = -1;
	if (!is_ray_facing_up)
		mlx->cord->ystep += SIZE_TITLE;
	mlx->cord->xstep = mlx->player->x + (mlx->cord->ystep - mlx->player->y) / tan(ray_angle);
	while ((mlx->cord->xstep >= 0 && mlx->cord->xstep < WIDTH && mlx->cord->ystep >= 0 && mlx->cord->ystep < HEIGHT))
	{
        printf("dkhlt\n");
		if ((is_ray_facing_up && is_has_wall(mlx, mlx->cord->xstep, mlx->cord->ystep - SIZE_TITLE)) || 
        (!is_ray_facing_up && is_has_wall(mlx, mlx->cord->xstep, mlx->cord->ystep)))
        {
            printf("im' here\n");
             draw_line(mlx->img, mlx->player->x, mlx->player->y,mlx->cord->xstep, mlx->cord->ystep, ft_pixel(255, 255, 0, 255));
        }
        printf("before incrementation %d\n",  mlx->cord->xstep);
      
        mlx->cord->xstep +=  sign *SIZE_TITLE / tan(ray_angle);
        mlx->cord->ystep += sign * SIZE_TITLE;
        printf("after incrementation %d\n" ,mlx->cord->xstep); 
	}
}




void draw_vertical_intersection(t_all_data *data, float ray_angle)
{
    bool is_ray_facing_left;
    int sign = 1;
    data->cord->ystep = 0;
    data->cord->ystep = 0;

    is_ray_facing_left = (ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI);

    data->cord->xstep = floor(data->player->x / SIZE_TITLE) * SIZE_TITLE;
    
    ray_angle = normalize_angle(ray_angle);
    if (is_ray_facing_left)
    {
        sign = -1;
        data->cord->xstep -= SIZE_TITLE; 
    }

    data->cord->ystep = data->player->y + (data->player->x - data->cord->xstep) * tan(ray_angle);
    

    while(((data->cord->xstep >= 0 && data->cord->xstep < WIDTH && data->cord->ystep >= 0 && data->cord->ystep < HEIGHT)))
    {
        if ((is_ray_facing_left && is_has_wall(data, data->cord->xstep - SIZE_TITLE, data->cord->ystep)) ||
            (!is_ray_facing_left && is_has_wall(data, data->cord->xstep, data->cord->ystep)))
        {
          break;
            draw_line(data->img, data->player->x, data->player->y, data->cord->xstep, data->cord->ystep, ft_pixel(255, 255, 0, 255));
    
        }
    
        data->cord->xstep += sign;
        data->cord->ystep += sign / tan(ray_angle);
    }
     draw_line(data->img, data->player->x, data->player->y, data->cord->xstep, data->cord->ystep, ft_pixel(255, 255, 0, 255));
}


void render_rays(t_all_data *data)
{
    int id;
    id = 0;
    int num_of_rays = WIDTH ;
    float ray_angle = normalize_angle(data->player->rotation_angle - (FOV_ANGLE / 2));
    while(id < num_of_rays)
    {
        draw_horizontal_intersection(data, ray_angle);
        draw_vertical_intersection(data, ray_angle);    
        ray_angle += FOV_ANGLE / num_of_rays;
        id++;
    }
}


