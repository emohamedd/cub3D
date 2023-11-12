/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:44:34 by houattou          #+#    #+#             */
/*   Updated: 2023/11/11 15:33:27 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	convert_degree(float degree)
{
	return (degree * M_PI / 180);
}
char get_direction_of_player(t_all_data *data)
{
   

	if (data->map->direction == NO)
	{
		data->player->rotation_angle = convert_degree(270);
		return ('N');
	}
	if (data->map->direction == SO)
	{
		data->player->rotation_angle  = convert_degree(90);
		return ('S');
	}
	if (data->map->direction == WE)
	{
		data->player->rotation_angle  = convert_degree(0);
		return ('W');
	}
	data->player->rotation_angle  = convert_degree(180);
	return ('E');


}
void initialize_player(t_all_data *data)
{
    int     i;
    
    data->player->radius = 3;
    data->player->move_speed = 18;
    i = 0;
    char direction = get_direction_of_player(data);
    
    while(data->map->map[i])
    {
        if(!ft_strchr(data->map->map[i], direction))
        {
            i++;
            continue;
        }
         break;
            
    }
    data->player->y= (float)(i * SIZE_TITLE  +  SIZE_TITLE / 2) + 1;
    data->player->x =(float) (((ft_strchr(data->map->map[i], direction) - \
			data->map->map[i])*SIZE_TITLE) + SIZE_TITLE / 2) + 1;
    // printf(" x is :%f\n", data->player->x);
    // printf(" y is :%f\n", data->player->y);
}


void draw_player(t_all_data *data)
{
   float center_x;
   float center_y;
   float radius;
   float x;
   float y;
   center_x = data->player->x;
   center_y = data->player->y;
   radius = data->player->radius;
   x = center_x - radius;
   while (x <= center_x + radius) 
   {
         y = center_y - radius;
        while (y <= center_y + radius) {
            if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= radius * radius) {
                mlx_put_pixel(data->img_minimap, x*MINIMAP_SCAL_FACTOR, y*MINIMAP_SCAL_FACTOR , ft_pixel(255, 0, 0, 255));
            }
            y++;
        }
        x++;
    } 
    render_rays(data);

}



