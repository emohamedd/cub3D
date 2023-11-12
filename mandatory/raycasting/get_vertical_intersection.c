/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertical_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:03:35 by houattou          #+#    #+#             */
/*   Updated: 2023/11/12 20:27:13 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/cub3d.h"
#include "../../libft/libft.h"

t_all_data *calcul_xstep_ystep_vertical(t_all_data *data)
{
	data->ray_angle = normalize_angle(data->ray_angle);
	
	data->is_player_facing_left = data->ray_angle > M_PI / 2 && data->ray_angle < 1.5 * M_PI;
	data->sign = 1;
	data->cord->xstep_v =ceil(data->player->x / SIZE_TILE) * SIZE_TILE;
	if (data->is_player_facing_left)
	{
		data->player->is_ray_facing_left = TRUE;
		data->cord->xstep_v -= SIZE_TILE;
		data->sign = -1;
	}
	if(!data->is_player_facing_left)
		data->player->is_ray_facing_left = FALSE;
		
	data->cord->ystep_v = data->player->y - (data->player->x - data->cord->xstep_v) * tan(data->ray_angle);
	return(data);
	
}
void	get_vertical_intersection(t_all_data *mlx)
{

	mlx = calcul_xstep_ystep_vertical(mlx);
	while (true)
	{
		if ((mlx->is_player_facing_left && is_has_wall(mlx, mlx->cord->xstep_v - SIZE_TILE , mlx->cord->ystep_v))
		 || (!mlx->is_player_facing_left && is_has_wall(mlx, mlx->cord->xstep_v, mlx->cord->ystep_v)) || \
		  (mlx->is_player_facing_left && is_has_wall(mlx, mlx->cord->xstep_v, mlx->cord->ystep_v)))
			   break ;
			
		mlx->cord->xstep_v += mlx->sign * SIZE_TILE;
		mlx->cord->ystep_v += mlx->sign * SIZE_TILE * tan(mlx->ray_angle);
	}

	// return(mlx);
	
}