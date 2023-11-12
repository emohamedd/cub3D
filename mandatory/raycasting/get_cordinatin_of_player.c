/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cordinatin_of_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:44:34 by houattou          #+#    #+#             */
/*   Updated: 2023/11/12 19:52:53 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	convert_degree(float degree)
{
	return (degree * M_PI / 180);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
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
    data->player->y= (float)(i * SIZE_TILE  +  SIZE_TILE / 2) + 1;
    data->player->x =(float) (((ft_strchr(data->map->map[i], direction) - \
			data->map->map[i])*SIZE_TILE) + SIZE_TILE / 2) + 1;
}






