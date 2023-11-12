/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_horizontal_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:06:20 by houattou          #+#    #+#             */
/*   Updated: 2023/11/12 20:29:24 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/cub3d.h"


t_all_data *calcul_xstep_ystep_horizontal(t_all_data *data)
{
    data->sign = 1;
    data->is_player_facing_up = data->ray_angle > M_PI && data->ray_angle < 2 * M_PI;
    
    if(data->is_player_facing_up)
    {
         data->player->is_ray_facing_up = TRUE;
        data->sign *= -1;
    }
	data->cord->ystep_h = floor(data->player->y / SIZE_TILE) * SIZE_TILE;
    if(!data->is_player_facing_up)
    {
        data->cord->ystep_h += SIZE_TILE;
        data->player->is_ray_facing_up = FALSE;
        
    }
    data->cord->xstep_h = data->player->x + (data->cord->ystep_h - data->player->y) / tan(data->ray_angle);
    return(data);
    
}
void get_horizontal_intersection(t_all_data *mlx)
{
	
	mlx = calcul_xstep_ystep_horizontal(mlx);
	while (true)
	{
        if((mlx->is_player_facing_up && is_has_wall(mlx, mlx->cord->xstep_h , mlx->cord->ystep_h - SIZE_TILE ))|| \
        (!mlx->is_player_facing_up && (is_has_wall(mlx, mlx->cord->xstep_h, mlx->cord->ystep_h))) || \
         (mlx->is_player_facing_up && is_has_wall(mlx, mlx->cord->xstep_h, mlx->cord->ystep_h)))
                 break;
        mlx->cord->xstep_h +=  mlx->sign *SIZE_TILE / tan(mlx->ray_angle);
        mlx->cord->ystep_h += mlx->sign * SIZE_TILE;
	}
}