/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_Horizontal_rays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:06:20 by houattou          #+#    #+#             */
/*   Updated: 2023/11/06 12:41:17 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/cub3d.h"


t_all_data*	draw_horizontal_intersection(t_all_data *mlx, float ray_angle)
{
	
	bool	is_ray_facing_up;
    int sign;

    sign = 1;
    mlx->cord->ystep_h = 0;
    mlx->cord->ystep_h = 0;
    
	is_ray_facing_up = ray_angle > M_PI && ray_angle < 2 * M_PI;
    
    if(is_ray_facing_up)
    {
         mlx->player->is_ray_facing_up = TRUE;
        sign *= -1;
    }
	mlx->cord->ystep_h = floor(mlx->player->y / SIZE_TITLE) * SIZE_TITLE;
    if(!is_ray_facing_up)
    {
        mlx->cord->ystep_h += SIZE_TITLE;
        mlx->player->is_ray_facing_up = FALSE;
        
    }

	mlx->cord->xstep_h = mlx->player->x + (mlx->cord->ystep_h - mlx->player->y) / tan(ray_angle);
 
	while ((mlx->cord->xstep_h >= 0 && mlx->cord->xstep_h < SIZE_TITLE * mlx->map->width && mlx->cord->ystep_h >= 0 && mlx->cord->ystep_h < SIZE_TITLE * mlx->map->height))
	{
        if((is_has_wall(mlx, mlx->cord->xstep_h , mlx->cord->ystep_h - SIZE_TITLE) && is_ray_facing_up )|| \
        (!is_ray_facing_up && (is_has_wall(mlx, mlx->cord->xstep_h, mlx->cord->ystep_h))))
        {
            // printf("dkhlt \n");
            
    //   draw_line(mlx->img, mlx->player->x*MINIMAP_SCAL_FACTOR, mlx->player->y*MINIMAP_SCAL_FACTOR,
    //   mlx->cord->xstep_h*MINIMAP_SCAL_FACTOR, mlx->cord->ystep_h*MINIMAP_SCAL_FACTOR, ft_pixel(255, 255, 0, 255));
                 break;
        }
        mlx->cord->xstep_h +=  sign *SIZE_TITLE / tan(ray_angle);
        mlx->cord->ystep_h += sign * SIZE_TITLE;
	}
 
    return(mlx);
}