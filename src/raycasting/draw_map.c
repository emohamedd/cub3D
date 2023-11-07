/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:44:22 by houattou          #+#    #+#             */
/*   Updated: 2023/11/06 12:32:56 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int is_game_running = FALSE;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

 

bool	is_has_wall(t_all_data *mlx, float x, float y)
{
    float new_x;
    float new_y;
	if (x < 0 || x > SIZE_TITLE * mlx->map->width|| y < 0 || y > SIZE_TITLE * mlx->map->height)
		return (TRUE);
 
	new_x = floor(x / SIZE_TITLE);
	new_y = floor(y / SIZE_TITLE);
	if (new_x < 0 || new_x >=  mlx->map->width || new_y < 0 || new_y >= mlx->map->height)
		return (TRUE);
	if (mlx->map->map[(int)new_y][(int)new_x] == '1')
		return (TRUE);
	return (FALSE);

}
bool	check_if_have_wall(t_all_data *mlx, float x, float y)
{
	if (mlx->map->map[(int)(mlx->player->y / SIZE_TITLE)][(int)(x / SIZE_TITLE)] == '1')
		return (TRUE);
	if (mlx->map->map[(int)(y / SIZE_TITLE)][(int)(mlx->player->x / SIZE_TITLE)] == '1')
		return (TRUE);
	return (FALSE);
}


void    draw_map(t_all_data *data)
{
    int       i;
    int       j;
    int        x;
    int        y;



    i = 0;
    while (i < data->map->height)
    {
        j = 0;
        while (j < data->map->width)
        {
            y = i * SIZE_TITLE;
            while (y < (SIZE_TITLE * i) + SIZE_TITLE)
            {
                x = j * SIZE_TITLE;
                while (x < (SIZE_TITLE * j) + SIZE_TITLE)
                {
                    if (data->map->map[i][j] == 49)
                        mlx_put_pixel(data->img, x*MINIMAP_SCAL_FACTOR, y*MINIMAP_SCAL_FACTOR, ft_pixel(125, 128, 0, 33));
                    else 
                        mlx_put_pixel(data->img, x*MINIMAP_SCAL_FACTOR, y*MINIMAP_SCAL_FACTOR, ft_pixel(255, 255, 255, 255));
                    x++;
                }
                y++;
            }
            j++;
        }
        i++;
    }
}






