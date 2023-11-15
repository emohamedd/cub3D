/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:04:14 by houattou          #+#    #+#             */
/*   Updated: 2023/11/15 16:20:42 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_rgba(int r, int g, int b, int a)
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
				mlx_put_pixel(data->img, j, i, get_rgba(data->dir->redc,
						data->dir->greenc, data->dir->bluec, 255));
			}
			else
			{
				mlx_put_pixel(data->img, j, i, get_rgba(data->dir->redf,
						data->dir->greenf, data->dir->bluef, 255));
			}
			j++;
		}
		i++;
	}
}

void	drawing(t_all_data *data)
{
	draw_ceil_floor(data);
	start_raycasting(data);
}
