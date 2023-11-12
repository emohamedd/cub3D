/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertical_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:03:35 by houattou          #+#    #+#             */
/*   Updated: 2023/11/12 10:52:02 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/cub3d.h"
#include "../../libft/libft.h"


void	get_vertical_intersection(t_all_data *mlx, float ray_angle)
{

	int		sign;
	bool	is_ray_facing_left;
	
	mlx->cord->ystep_v = 0;
    mlx->cord->xstep_v = 0;
    // printf("vertical angle %f\n", ray_angle);

	ray_angle = normalize_angle(ray_angle);
	// is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	sign = 1;
	mlx->cord->xstep_v =ceil(mlx->player->x / SIZE_TITLE) * SIZE_TITLE;
	if (is_ray_facing_left)
	{
		mlx->player->is_ray_facing_left = TRUE;
		mlx->cord->xstep_v -= SIZE_TITLE;
		sign = -1;
	}
	if(!is_ray_facing_left)
		mlx->player->is_ray_facing_left = FALSE;
		
	mlx->cord->ystep_v = mlx->player->y - (mlx->player->x - mlx->cord->xstep_v) * tan(ray_angle);
	while (true)
	{
		if ((is_ray_facing_left && is_has_wall(mlx, mlx->cord->xstep_v - SIZE_TITLE , mlx->cord->ystep_v))
		 || (!is_ray_facing_left && is_has_wall(mlx, mlx->cord->xstep_v, mlx->cord->ystep_v)) || (is_ray_facing_left && is_has_wall(mlx, mlx->cord->xstep_v + 1, mlx->cord->ystep_v)))
		{
			   break ;
			
		}
		mlx->cord->xstep_v += sign * SIZE_TITLE;
		mlx->cord->ystep_v += sign * SIZE_TITLE * tan(ray_angle);
	}

	// return(mlx);
	
}