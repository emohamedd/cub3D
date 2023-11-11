/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:48:29 by houattou          #+#    #+#             */
/*   Updated: 2023/11/11 21:35:00 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool    check_if_have_wall(t_all_data *data, float x, float y)
{
    if (x <= 0 || x >= data->map->width * SIZE_TITLE || y <= 0 || y >= data->map->height * SIZE_TITLE)
		return (FALSE);
	if (data->map->map[(int)(data->player->y / SIZE_TITLE)][(int)(x / SIZE_TITLE)] == '1')
		return (FALSE);
	if (data->map->map[(int)(y / SIZE_TITLE)][(int)(data->player->x / SIZE_TITLE)] == '1')
		return (FALSE);
	return (TRUE);
    // int map_grid_x;
    // int map_grid_y;
    // int old_x;
    // int old_y;
    // map_grid_x = floor(x /SIZE_TITLE);
    // map_grid_y = floor(y / SIZE_TITLE);
    // old_x = floor(data->player->x /SIZE_TITLE);
    // old_y = floor(data->player->y / SIZE_TITLE);
    
    // if((data->map->map[map_grid_y][old_x] == 49) || data->map->map[old_y][map_grid_x] == 49)
    //     return(FALSE);
    // if(map_grid_y >= SIZE_TITLE * data->map->height || map_grid_x >= SIZE_TITLE * data->map->width || map_grid_x < 0 || map_grid_y < 0 || x <= 0 || y <= 0)
    //     return (FALSE);
    // if(data->map->map[map_grid_y][map_grid_x] == 49)
    //     return (FALSE);
    // return(TRUE);
}


bool	is_has_wall(t_all_data *mlx, float x, float y)
{
    float new_x;
    float new_y;
    float x_step;
    float y_step;
    x_step = x + 1;
    y_step = y + 1;
    x_step = floor(x_step / SIZE_TITLE);
    y_step = floor(y_step / SIZE_TITLE);
	if (x <= 0 || x >= SIZE_TITLE * mlx->map->width|| y <= 0 || y >= SIZE_TITLE * mlx->map->height)
		return (TRUE);
 
	new_x = floor(x / SIZE_TITLE);
	new_y = floor(y / SIZE_TITLE);
	if (new_x <= 0 || new_x >=  mlx->map->width || new_y <= 0 || new_y >= mlx->map->height)
		return (TRUE);
	if (mlx->map->map[(int)new_y][(int)new_x] == '1')
		return (TRUE);
    if(mlx->map->map[(int)y_step][(int)x_step] == '1')
        return(TRUE);
	return (FALSE);
}