/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:48:29 by houattou          #+#    #+#             */
/*   Updated: 2023/11/12 19:46:22 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_if_have_wall(t_all_data *data, float x, float y)
{
    int	x_step;
    int	y_step;
    
    x_step = x + 1;
    y_step = y + 1;
    x_step = floor(x_step / SIZE_TILE);
    y_step = floor(y_step / SIZE_TILE);
    if (x < 0 || x > data->map->width * SIZE_TILE || y < 0 || y > data->map->height * SIZE_TILE)
		return (FALSE);
	if (data->map->map[(int)(data->player->y / SIZE_TILE)][(int)(x / SIZE_TILE)] == '1')
		return (FALSE);
	if (data->map->map[(int)(y / SIZE_TILE)][(int)(data->player->x / SIZE_TILE)] == '1')
		return (FALSE);
     if (x_step <= 0 || x_step >= data->map->width * SIZE_TILE || y_step <= 0 || y_step >= data->map->height * SIZE_TILE)
		return (FALSE);
     if (data->map->map[y_step][x_step] == '1')
                return (FALSE);   
	return (TRUE);
   
}

bool	is_has_wall(t_all_data *mlx, float x, float y)
{
    float	new_x;
    float	new_y;
    
	if (x <= 0 || x >= SIZE_TILE * mlx->map->width|| y <= 0 || y >= SIZE_TILE * mlx->map->height)
		return (TRUE);
 
	new_x = floor(x / SIZE_TILE);
	new_y = floor(y / SIZE_TILE);
	if (new_x <= 0 || new_x >=  mlx->map->width || new_y < 0 || new_y >= mlx->map->height)
		return (TRUE);
	if (mlx->map->map[(int)new_y][(int)new_x] == '1')
		return (TRUE);
	return (FALSE);
}