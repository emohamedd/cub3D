/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:49:17 by houattou          #+#    #+#             */
/*   Updated: 2023/11/16 14:17:17 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	render_single_tile(mlx_image_t *img, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	j = (y * SIZE_TITLE) * MINIMAP_SCAL_FACTOR;
	while (j < ((y * SIZE_TITLE) + SIZE_TITLE) * MINIMAP_SCAL_FACTOR)
	{
		i = (x * SIZE_TITLE) * MINIMAP_SCAL_FACTOR;
		while (i < ((x * SIZE_TITLE) + SIZE_TITLE) * MINIMAP_SCAL_FACTOR)
		{
			mlx_put_pixel(img, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_map(t_all_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map->height)
	{
		i = 0;
		while (i < data->map->width && data->map->map[j][i])
		{
			if (data->map->map[j][i] == '1')
				render_single_tile(data->img_minimap, i, j, ft_pixel(0, 0, 0,
						255));
			else
				render_single_tile(data->img_minimap, i, j, ft_pixel(255, 255,
						255, 255));
			i++;
		}
		j++;
	}
}

void	draw_player(t_all_data *data)
{
	float	center_x;
	float	center_y;
	float	radius;
	float	x;
	float	y;

	center_x = data->player->x;
	center_y = data->player->y;
	radius = data->player->radius;
	x = center_x - radius;
	while (x <= center_x + radius)
	{
		y = center_y - radius;
		while (y <= center_y + radius)
		{
			if ((x - center_x) * (x - center_x) + (y - center_y) * (y
					- center_y) <= radius * radius)
			{
				mlx_put_pixel(data->img_minimap, x * MINIMAP_SCAL_FACTOR, y
					* MINIMAP_SCAL_FACTOR, ft_pixel(255, 55, 40, 255));
			}
			y++;
		}
		x++;
	}
}
