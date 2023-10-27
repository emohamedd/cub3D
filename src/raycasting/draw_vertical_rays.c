/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:03:35 by houattou          #+#    #+#             */
/*   Updated: 2023/10/27 17:41:16 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/cub3d.h"


void	draw_vertical_intersection(t_all_data *mlx, float ray_angle)
{

	int		sign;
	bool	is_ray_facing_left;
	
	mlx->cord->ystep = 0;
    mlx->cord->ystep = 0;
	ray_angle = normalize_angle(ray_angle);
	is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	sign = 1;
	mlx->cord->xstep = ceil(mlx->player->x / SIZE_TITLE) * SIZE_TITLE;
	if (is_ray_facing_left)
	{
		mlx->cord->xstep -= SIZE_TITLE;
		sign = -1;
	}
	mlx->cord->ystep = mlx->player->y - (mlx->player->x - mlx->cord->xstep) * tan(ray_angle);
	while ((mlx->cord->xstep >= 0 && mlx->cord->xstep < WIDTH && mlx->cord->ystep >= 0 && mlx->cord->ystep < HEIGHT))
	{
		if ((is_ray_facing_left && is_has_wall(mlx, mlx->cord->xstep - SIZE_TITLE, mlx->cord->ystep)) || (!is_ray_facing_left && is_has_wall(mlx, mlx->cord->xstep, mlx->cord->ystep)) || 
		(is_ray_facing_left && is_has_wall(mlx, mlx->cord->xstep, mlx->cord->ystep)) || (!is_ray_facing_left && is_has_wall(mlx, mlx->cord->xstep - SIZE_TITLE, mlx->cord->ystep)))
		{
				draw_line(mlx->img, mlx->player->x, mlx->player->y,mlx->cord->xstep, mlx->cord->ystep, ft_pixel(255, 255, 0, 255));
			   break ;
			
		}
		mlx->cord->xstep += sign * SIZE_TITLE;
		mlx->cord->ystep += sign * SIZE_TITLE * tan(ray_angle);
	}
	
}