/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:03:35 by houattou          #+#    #+#             */
/*   Updated: 2023/10/27 11:04:56 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/cub3d.h"

void draw_vertical_intersection(t_all_data *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;
	bool	is_ray_facing_left;

	is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	sign = 1;
	cord.xstep = ceil(mlx->player->x / SIZE_TITLE) * SIZE_TITLE;
	if (is_ray_facing_left)
	{
		cord.xstep -= SIZE_TITLE;
		sign = -1;
	}
	cord.ystep = mlx->player->y - (mlx->player->x - cord.xstep) * tan(ray_angle);
    while(((mlx->cord->xstep >= 0 && mlx->cord->xstep < WIDTH  && floor(mlx->cord->ystep / SIZE_TITLE) <= HEIGHT_MAP && floor(mlx->cord->xstep / SIZE_TITLE) <= WIDTH_MAP
    && mlx->cord->ystep >= 0 && mlx->cord->ystep < HEIGHT)))
	{
		if ((is_ray_facing_left && \
				is_has_wall(mlx, cord.xstep - SIZE_TITLE, cord.ystep)) || \
			(!is_ray_facing_left && \
				is_has_wall(mlx, cord.xstep, cord.ystep)))
        {
            printf("im' here\n");
            
          draw_line(mlx->img, mlx->player->x, mlx->player->y, cord.xstep, cord.ystep, ft_pixel(255, 255, 0, 255));
                break ;
        }
		cord.xstep += sign * SIZE_TITLE;
		cord.ystep += sign * SIZE_TITLE * tan(ray_angle);
	}
    // printf("xstep :%d\n", cord.xstep);
    // printf("ystep :%d\n", cord.ystep);
    
}