/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:54 by houattou          #+#    #+#             */
/*   Updated: 2023/11/14 16:54:46 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ratate_player(mlx_key_data_t keydata, t_all_data *data)
{
	if (keydata.key == MLX_KEY_UP)
		data->player->rotation_angle = 3 * M_PI / 2;
	else if (keydata.key == MLX_KEY_DOWN)
		data->player->rotation_angle = M_PI / 2;
	else if (keydata.key == MLX_KEY_LEFT)
		data->player->rotation_angle -= 0.1;
	else if (keydata.key == MLX_KEY_RIGHT)
		data->player->rotation_angle += 0.1;
}

void	update_player(t_all_data *mlx, mlx_key_data_t keydata)
{
	float	new_x;
	float	new_y;

	new_x = 0;
	new_y = 0;
	if (keydata.key == MLX_KEY_A)
	{
		new_x = mlx->player->x + mlx->player->move_speed
			* cos(mlx->player->rotation_angle - M_PI / 2);
		new_y = mlx->player->y + mlx->player->move_speed
			* sin(mlx->player->rotation_angle - M_PI / 2);
	}
	else if (keydata.key == MLX_KEY_W)
	{
		new_x = mlx->player->x + mlx->player->move_speed
			* cos(mlx->player->rotation_angle);
		new_y = mlx->player->y + mlx->player->move_speed
			* sin(mlx->player->rotation_angle);
	}
	if ((check_if_have_wall(mlx, new_x, new_y)) == TRUE)
	{
		mlx->player->x = new_x;
		mlx->player->y = new_y;
	}
}

void	update_player_s(t_all_data *mlx, mlx_key_data_t keydata)
{
	float	new_x;
	float	new_y;

	new_x = 0;
	new_y = 0;
	if (keydata.key == MLX_KEY_S)
	{
		new_x = mlx->player->x - mlx->player->move_speed
			* cos(mlx->player->rotation_angle);
		new_y = mlx->player->y - mlx->player->move_speed
			* sin(mlx->player->rotation_angle);
	}
	else if (keydata.key == MLX_KEY_D)
	{
		new_x = mlx->player->x + mlx->player->move_speed
			* cos(mlx->player->rotation_angle + M_PI / 2);
		new_y = mlx->player->y + mlx->player->move_speed
			* sin(mlx->player->rotation_angle + M_PI / 2);
	}
	if ((check_if_have_wall(mlx, new_x, new_y)) == TRUE)
	{
		mlx->player->x = new_x;
		mlx->player->y = new_y;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_all_data	*mlx;

	mlx = (t_all_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx->mlx);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A)
		update_player(mlx, keydata);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
		update_player_s(mlx, keydata);
	else
		ratate_player(keydata, mlx);
	drawing(mlx);
}
