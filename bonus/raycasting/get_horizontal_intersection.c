/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_horizontal_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:06:20 by houattou          #+#    #+#             */
/*   Updated: 2023/11/15 16:48:20 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_horizontal_intersection(t_all_data *mlx, float *ray_angle)
{
	while (true)
	{
		if ((mlx->cord->is_player_facing_up && is_has_wall(mlx,
					mlx->cord->xstep_h, mlx->cord->ystep_h - SIZE_TITLE))
			|| (!mlx->cord->is_player_facing_up && (is_has_wall(mlx,
						mlx->cord->xstep_h, mlx->cord->ystep_h)))
			|| (mlx->cord->is_player_facing_up && is_has_wall(mlx,
					mlx->cord->xstep_h, mlx->cord->ystep_h)))
			break ;
		mlx->cord->xstep_h += mlx->cord->sign * SIZE_TITLE / tan(*ray_angle);
		mlx->cord->ystep_h += mlx->cord->sign * SIZE_TITLE;
	}
}

void	get_horizontal_intersection(t_all_data *mlx, float ray_angle)
{
	mlx->cord->sign = 1;
	mlx->cord->ystep_h = 0;
	mlx->cord->ystep_h = 0;
	mlx->cord->is_player_facing_up = ray_angle > M_PI && ray_angle < 2 * M_PI;
	if (mlx->cord->is_player_facing_up)
	{
		mlx->player->is_ray_facing_up = TRUE;
		mlx->cord->sign *= -1;
	}
	mlx->cord->ystep_h = floor(mlx->player->y / SIZE_TITLE) * SIZE_TITLE;
	if (!mlx->cord->is_player_facing_up)
	{
		mlx->cord->ystep_h += SIZE_TITLE;
		mlx->player->is_ray_facing_up = FALSE;
	}
	mlx->cord->xstep_h = mlx->player->x + (mlx->cord->ystep_h - mlx->player->y)
		/ tan(ray_angle);
	check_horizontal_intersection(mlx, &ray_angle);
}
