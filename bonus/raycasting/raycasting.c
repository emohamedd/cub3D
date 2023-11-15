/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:54:28 by houattou          #+#    #+#             */
/*   Updated: 2023/11/15 16:39:35 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_all_data	*smaller_distance(t_all_data *data)
{
	if (data->player->dis_v > data->player->dis_h)
	{
		data->cord->xstep = data->cord->xstep_h;
		data->cord->ystep = data->cord->ystep_h;
		data->cord->distance = data->player->dis_h;
		data->cord->is_horizontal = TRUE;
		data->cord->is_vertical = FALSE;
	}
	else
	{
		data->cord->xstep = data->cord->xstep_v;
		data->cord->ystep = data->cord->ystep_v;
		data->cord->distance = data->player->dis_v;
		data->cord->is_horizontal = FALSE;
		data->cord->is_vertical = TRUE;
	}
	return (data);
}

t_all_data	*get_valid_distance(t_all_data *data, float ray_angle)
{
	float	angle;

	angle = normalize_angle(ray_angle);
	get_horizontal_intersection(data, ray_angle);
	get_vertical_intersection(data, angle);
	data->player->dis_v = distance_between_points(data->player->x,
			data->player->y, data->cord->xstep_v, data->cord->ystep_v);
	data->player->dis_h = distance_between_points(data->player->x,
			data->player->y, data->cord->xstep_h, data->cord->ystep_h);
	data = smaller_distance(data);
	data->cord->distance = data->cord->distance * cos(ray_angle
			- data->player->rotation_angle);
	return (data);
}

t_all_data	*calcul_wall_height(t_all_data *data)
{
	data->wall_height = (SIZE_TITLE / data->cord->distance) * (WIDTH / 2)
		/ tan(data->player->fov_angle / 2);
	data->exact_wall_height = data->wall_height;
	if (data->wall_height > HEIGHT)
		data->wall_height = HEIGHT;
	data->y_start = (HEIGHT / 2) - (data->wall_height / 2);
	data->y_end = (HEIGHT / 2) + (data->wall_height / 2);
	return (data);
}

void	cast_rays(t_all_data *data, int id, float ray_angle)
{
	data = get_valid_distance(data, ray_angle);
	data = calcul_wall_height(data);
	if (data->cord->is_vertical == TRUE)
		data->xtx = (int)data->cord->ystep % SIZE_TITLE;
	else
		data->xtx = (int)data->cord->xstep % SIZE_TITLE;
	if (data->player->dis_v > data->player->dis_h)
	{
		if (data->player->is_ray_facing_up == TRUE)
			draw_wall_with_texture(data, id, data->xtx,
				data->textrs.no_texture);
		else
			draw_wall_with_texture(data, id, data->xtx,
				data->textrs.so_texture);
	}
	else
	{
		if (data->player->is_ray_facing_left == TRUE)
			draw_wall_with_texture(data, id, data->xtx,
				data->textrs.we_texture);
		else
			draw_wall_with_texture(data, id, data->xtx,
				data->textrs.ea_texture);
	}
}

void	start_raycasting(t_all_data *data)
{
	int	id;
	int	num_of_rays;

	id = 0;
	num_of_rays = WIDTH;
	data->ray_angle = normalize_angle(data->player->rotation_angle
			- (data->player->fov_angle / 2));
	while (id < num_of_rays)
	{
		cast_rays(data, id, data->ray_angle);
		data->ray_angle += normalize_angle(data->player->fov_angle
				/ num_of_rays);
		id++;
	}
}
