/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/16 14:11:03 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	raycasting(t_all_data *data)
{
	init(data);
	drawing(data);
	mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop(data->mlx);
}

void	free_all_data(t_all_data *data)
{
	free_2d_arr(data->map->all_map);
	if (data->mlx)
		mlx_terminate(data->mlx);
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
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
	raycasting(data);
	free_all_data(data);
	return (EXIT_SUCCESS);
}
