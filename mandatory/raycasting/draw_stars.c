/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:24:49 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/15 14:26:45 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	initialize_star_parameters(t_all_data *data)
{
	data->s.num_stars = 70;
	data->s.star_radius = 1;
	data->s.k = 0;
}

void	generate_star_coordinates(t_all_data *data)
{
	data->s.x = rand() % WIDTH;
	data->s.y = rand() % (HEIGHT / 2);
}

void	draw_star_pixels(t_all_data *data)
{
	data->s.m = -data->s.star_radius;
	while (data->s.m <= data->s.star_radius)
	{
		data->s.n = -data->s.star_radius;
		while (data->s.n <= data->s.star_radius)
		{
			if (data->s.m * data->s.m + data->s.n
				* data->s.n <= data->s.star_radius * data->s.star_radius)
			{
				data->s.pixel_x = data->s.x + data->s.m;
				data->s.pixel_y = data->s.y + data->s.n;
				if (data->s.pixel_x >= 0 && data->s.pixel_x < WIDTH
					&& data->s.pixel_y >= 0 && data->s.pixel_y < HEIGHT / 2)
				{
					mlx_put_pixel(data->img, data->s.pixel_x, data->s.pixel_y,
						ft_pixel(255, 255, 255, 255));
				}
			}
			data->s.n++;
		}
		data->s.m++;
	}
}

void	add_stars_to_sky(t_all_data *data)
{
	initialize_star_parameters(data);
	while (data->s.k < data->s.num_stars)
	{
		generate_star_coordinates(data);
		draw_star_pixels(data);
		data->s.k++;
	}
}
