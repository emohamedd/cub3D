/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:04:14 by houattou          #+#    #+#             */
/*   Updated: 2023/11/16 14:18:33 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_ceil_floor(t_all_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < (HEIGHT))
	{
		j = 0;
		while (j < ((WIDTH)))
		{
			if (i < (HEIGHT) / 2)
			{
				mlx_put_pixel(data->img, j, i, ft_pixel(data->dir->redc,
						data->dir->greenc, data->dir->bluec, 255));
			}
			else
			{
				mlx_put_pixel(data->img, j, i, ft_pixel(data->dir->redf,
						data->dir->greenf, data->dir->bluef, 255));
			}
			j++;
		}
		i++;
	}
	add_stars_to_sky(data);
}

void	drawing(t_all_data *data)
{
	draw_ceil_floor(data);
	draw_map(data);
	draw_player(data);
	start_raycasting(data);
}
