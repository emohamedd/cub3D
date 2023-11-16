/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:06:06 by houattou          #+#    #+#             */
/*   Updated: 2023/11/16 14:04:30 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_all_data	*init_data(t_all_data *data)
{
	data = (t_all_data *)malloc(sizeof(t_all_data));
	if (!data)
		return (NULL);
	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data->player)
		return (NULL);
	data->cord = (t_cord *)malloc(sizeof(t_cord));
	if (!data->cord)
		return (NULL);
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		return (NULL);
	data->dir = (t_direc *)malloc(sizeof(t_direc));
	if (!data->dir)
		return (NULL);
	data->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!data->mouse)
		return (NULL);
	data->mouse->x = 0;
	data->mouse->y = 0;
	data->player->fov_angle = convert_degree(60);
	return (data);
}

void	init_mlx(t_all_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		print_err("Error: mlx_init failed\n");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		print_err("Error: mlx_new_image failed\n");
}

void	init(t_all_data *data)
{
	initialize_player(data);
	init_mlx(data);
}
