/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordination_of_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:44:34 by houattou          #+#    #+#             */
/*   Updated: 2023/11/13 12:29:06 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	convert_degree(float degree)
{
	return (degree * M_PI / 180);
}

char	get_direction_of_player(t_all_data *data)
{
	if (data->map->direction == NO)
	{
		data->player->rotation_angle = convert_degree(270);
		return ('N');
	}
	if (data->map->direction == SO)
	{
		data->player->rotation_angle = convert_degree(90);
		return ('S');
	}
	if (data->map->direction == WE)
	{
		data->player->rotation_angle = convert_degree(0);
		return ('W');
	}
	data->player->rotation_angle = convert_degree(180);
	return ('E');
}

void	initialize_player(t_all_data *data)
{
	int		i;
	char	direction;

	data->player->radius = 3;
	data->player->move_speed = 18;
	i = 0;
	direction = get_direction_of_player(data);
	while (data->map->map[i])
	{
		if (!ft_strchr(data->map->map[i], direction))
		{
			i++;
			continue ;
		}
		break ;
	}
	data->player->y = (float)(i * SIZE_TITLE + SIZE_TITLE / 2) + 1;
	data->player->x = (float)(((ft_strchr(data->map->map[i], direction)
					- data->map->map[i]) * SIZE_TITLE) + SIZE_TITLE / 2) + 1;
}
