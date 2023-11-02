/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:03:35 by houattou          #+#    #+#             */
/*   Updated: 2023/11/01 15:48:01 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/cub3d.h"


t_all_data*	draw_vertical_intersection(t_all_data *mlx, float ray_angle)
{

	int		sign;
	bool	is_ray_facing_left;
	
	mlx->cord->ystep_v = 0;
    mlx->cord->xstep_v = 0;
	ray_angle = normalize_angle(ray_angle);
	is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	sign = 1;
	mlx->cord->xstep_v = ceil(mlx->player->x / SIZE_TITLE) * SIZE_TITLE;
	if (is_ray_facing_left)
	{
		mlx->cord->xstep_v -= SIZE_TITLE;
		sign = -1;
	}
	mlx->cord->ystep_v = mlx->player->y - (mlx->player->x - mlx->cord->xstep_v) * tan(ray_angle);
	while ((mlx->cord->xstep_v >= 0 && mlx->cord->xstep_v < WIDTH && mlx->cord->ystep_v >= 0 && mlx->cord->ystep_v < HEIGHT))
	{
		if ((is_ray_facing_left && is_has_wall(mlx, mlx->cord->xstep_v - SIZE_TITLE, mlx->cord->ystep_v))
		 || (!is_ray_facing_left && is_has_wall(mlx, mlx->cord->xstep_v, mlx->cord->ystep_v)))
		{
				
			   break ;
			
		}
		mlx->cord->xstep_v += sign * SIZE_TITLE;
		mlx->cord->ystep_v += sign * SIZE_TITLE * tan(ray_angle);
	}
// 	  printf(" here :data->cord->xstep : %d\n", mlx->cord->xstep_v);
//    printf(" here :data->cord->ystep : %d\n", mlx->cord->ystep_v);
	return(mlx);
	
}