/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_horizontal_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:06:20 by houattou          #+#    #+#             */
/*   Updated: 2023/11/12 16:40:15 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/cub3d.h"


void get_horizontal_intersection(t_all_data *mlx, float ray_angle)
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
	while (true)
	{
        if((is_ray_facing_up && is_has_wall(mlx, mlx->cord->xstep_h , mlx->cord->ystep_h - SIZE_TITLE ))|| \
        (!is_ray_facing_up && (is_has_wall(mlx, mlx->cord->xstep_h, mlx->cord->ystep_h))) || (is_ray_facing_up && is_has_wall(mlx, mlx->cord->xstep_h + 1, mlx->cord->ystep_h + 1)))
                 break;
        mlx->cord->xstep_h +=  sign *SIZE_TITLE / tan(ray_angle);
        mlx->cord->ystep_h += sign * SIZE_TITLE;
	}
}