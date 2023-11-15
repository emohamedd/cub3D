/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertical_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:03:35 by houattou          #+#    #+#             */
/*   Updated: 2023/11/15 16:17:55 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../cub.h"

void	check_vertical_intersection(t_all_data *mlx, float *ray_angle)
{
	while (true)
	{
		if ((mlx->cord->is_player_facing_left && is_has_wall(mlx,
					mlx->cord->xstep_v - SIZE_TITLE, mlx->cord->ystep_v))
			|| (!mlx->cord->is_player_facing_left && is_has_wall(mlx,
					mlx->cord->xstep_v, mlx->cord->ystep_v))
			|| (mlx->cord->is_player_facing_left && is_has_wall(mlx,
					mlx->cord->xstep_v, mlx->cord->ystep_v)))
			break ;
		mlx->cord->xstep_v += mlx->cord->sign * SIZE_TITLE;
		mlx->cord->ystep_v += mlx->cord->sign * SIZE_TITLE * tan(*ray_angle);
	}
}

void	get_vertical_intersection(t_all_data *mlx, float ray_angle)
{
	mlx->cord->ystep_v = 0;
	mlx->cord->xstep_v = 0;
	ray_angle = normalize_angle(ray_angle);
	mlx->cord->is_player_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5
		* M_PI;
	mlx->cord->sign = 1;
	mlx->cord->xstep_v = ceil(mlx->player->x / SIZE_TITLE) * SIZE_TITLE;
	if (mlx->cord->is_player_facing_left)
	{
		mlx->player->is_ray_facing_left = TRUE;
		mlx->cord->xstep_v -= SIZE_TITLE;
		mlx->cord->sign = -1;
	}
	if (!mlx->cord->is_player_facing_left)
		mlx->player->is_ray_facing_left = FALSE;
	mlx->cord->ystep_v = mlx->player->y - (mlx->player->x - mlx->cord->xstep_v)
		* tan(ray_angle);
	check_vertical_intersection(mlx, &ray_angle);
}
