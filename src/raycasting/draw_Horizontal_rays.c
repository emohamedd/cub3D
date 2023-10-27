/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_Horizontal_rays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:06:20 by houattou          #+#    #+#             */
/*   Updated: 2023/10/27 12:37:26 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/cub3d.h"


void	draw_horizontal_intersection(t_all_data *mlx, float ray_angle)
{
	
	bool	is_ray_facing_up;
    int sign;

    sign = 1;
     mlx->cord->ystep = 0;
    mlx->cord->ystep = 0;

	is_ray_facing_up = ray_angle > M_PI && ray_angle < 2 * M_PI;
    
    if(is_ray_facing_up)
        sign = -1;
	mlx->cord->ystep = floor(mlx->player->y / SIZE_TITLE) * SIZE_TITLE;
    if(!is_ray_facing_up)
        mlx->cord->ystep += SIZE_TITLE;

	mlx->cord->xstep = mlx->player->x + (mlx->cord->ystep - mlx->player->y) / tan(ray_angle);
	while ((mlx->cord->xstep >= 0 && mlx->cord->xstep < WIDTH && mlx->cord->ystep >= 0 && mlx->cord->ystep < HEIGHT))
	{
        printf("dkhlt\n");
        if((is_has_wall(mlx, mlx->cord->xstep, mlx->cord->ystep - SIZE_TITLE) && is_ray_facing_up) || (!is_ray_facing_up && is_has_wall(mlx, mlx->cord->xstep, mlx->cord->ystep) || \
         (is_has_wall(mlx, mlx->cord->xstep, mlx->cord->ystep))) || (!is_ray_facing_up && is_has_wall(mlx, mlx->cord->xstep, mlx->cord->ystep - SIZE_TITLE)))
                 break;
     
		
        mlx->cord->xstep +=  sign *SIZE_TITLE / tan(ray_angle);
        mlx->cord->ystep += sign * SIZE_TITLE;
	}
    draw_line(mlx->img, mlx->player->x, mlx->player->y,mlx->cord->xstep, mlx->cord->ystep, ft_pixel(255, 255, 0, 255));
}