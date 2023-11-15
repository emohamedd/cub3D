/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:22 by houattou          #+#    #+#             */
/*   Updated: 2023/11/15 14:28:24 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <math.h>

int	get_color_from_texture(int x, int y, mlx_texture_t *texture)
{
	int	i;

	i = (x * 4) + ((y * 4) * texture->width);
	return (texture->pixels[i] << 24 | texture->pixels[i
			+ 1] << 16 | texture->pixels[i + 2] << 8 | texture->pixels[i + 3]);
}

void	draw_wall_with_texture(t_all_data *data, int id, float xtx,
		mlx_texture_t *texture)
{
	float	ytx;
	float	tx_inc;
	float	tmp_ystart;
	float	wall_top_pixel;

	tx_inc = texture->height / (float)data->exact_wall_height;
	tmp_ystart = ((HEIGHT) / 2) - (data->exact_wall_height / 2);
	wall_top_pixel = tmp_ystart;
	while (data->y_start < data->y_end)
	{
		ytx = (data->y_start - wall_top_pixel) * tx_inc;
		if (ytx >= texture->height)
		{
			ytx = 0;
		}
		mlx_put_pixel(data->img, id, data->y_start, get_color_from_texture(xtx,
				ytx, texture));
		data->y_start++;
		tmp_ystart++;
	}
}
