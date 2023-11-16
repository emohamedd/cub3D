/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:26:14 by houattou          #+#    #+#             */
/*   Updated: 2023/11/16 14:11:10 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mouse_handler(void *param)
{
	int			x;
	int			y;
	t_all_data	*data;

	data = (t_all_data *)param;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x > data->mouse->x)
	{
		data->mouse->x = x;
		data->mouse->y = y;
		data->player->rotation_angle += 0.1;
	}
	if (x < data->mouse->x)
	{
		data->mouse->x = x;
		data->mouse->y = y;
		data->player->rotation_angle -= 0.1;
	}
	drawing(data);
}

void	raycasting(t_all_data *data)
{
	init(data);
	drawing(data);
	mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_loop_hook(data->mlx, &mouse_handler, data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_image_to_window(data->mlx, data->img_minimap, 0, 0);
	mlx_loop(data->mlx);
}

void	check_valid_width_height(t_map *map)
{
	if (map->width > WIDTH || map->height > HEIGHT)
		print_err("Error: Invalid width or height\n");
}

void	free_all_data(t_all_data *data)
{
	free_2d_arr(data->map->all_map);
	if (data->mlx)
		mlx_terminate(data->mlx);
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	if (data->img_minimap)
		mlx_delete_image(data->mlx, data->img_minimap);
}

int	main(int ac, char **av)
{
	t_all_data	*data;

	data = NULL;
	data = init_data(data);
	if (data == NULL)
	{
		free_all_data(data);
		return (EXIT_FAILURE);
	}
	parsing(data, ac, av);
	check_valid_width_height(data->map);
	raycasting(data);
	free_all_data(data);
	return (EXIT_SUCCESS);
}
