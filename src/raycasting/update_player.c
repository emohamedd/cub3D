/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:54 by houattou          #+#    #+#             */
/*   Updated: 2023/11/05 13:19:59 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define TWO_PI 2 * M_PI
#include "../../include/cub3d.h"



void ratate_player(mlx_key_data_t keydata, t_all_data *data)
{
    if(keydata.key == MLX_KEY_UP)
        data->player->rotation_angle = 3 * M_PI /2;
    else if(keydata.key == MLX_KEY_DOWN)
        data->player->rotation_angle = M_PI /2;
    else if(keydata.key == MLX_KEY_LEFT)
        data->player->rotation_angle -= 0.1;
    else if(keydata.key == MLX_KEY_RIGHT)
        data->player->rotation_angle += 0.1;
}






void update_player(t_all_data *mlx, mlx_key_data_t keydata)
{
    float new_x = 0;
    float new_y = 0;
    if (keydata.key == MLX_KEY_S)
    {
        new_x = mlx->player->x + mlx->player->move_speed * cos(mlx->player->rotation_angle);
        new_y = mlx->player->y + mlx->player->move_speed * sin(mlx->player->rotation_angle);
    }
    else if (keydata.key == MLX_KEY_D)
    {
        new_x = mlx->player->x + mlx->player->move_speed * cos(mlx->player->rotation_angle - M_PI / 2);
        new_y = mlx->player->y + mlx->player->move_speed * sin(mlx->player->rotation_angle - M_PI / 2);
    }
    else if (keydata.key == MLX_KEY_A)
    {
        new_x = mlx->player->x + mlx->player->move_speed * cos(mlx->player->rotation_angle + M_PI / 2);
        new_y = mlx->player->y + mlx->player->move_speed * sin(mlx->player->rotation_angle + M_PI / 2);
    }
    else if (keydata.key == MLX_KEY_W)
    {
        new_x = mlx->player->x - mlx->player->move_speed * cos(mlx->player->rotation_angle);
        new_y = mlx->player->y - mlx->player->move_speed * sin(mlx->player->rotation_angle);
    }
    
    if( (check_if_have_wall(mlx, new_x, new_y)) == FALSE)
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
      
	else if (  keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A \
			|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
                 update_player(mlx, keydata);
    else
        ratate_player(keydata, mlx);
    drawing(mlx);    
    draw_map(mlx);
    draw_player(mlx);
    //  draw_line(mlx->img, mlx->player->x, mlx->player->y, mlx->player->x + cos(mlx->player->rotation_angle)*40, \
    //     mlx->player->y + sin(mlx->player->rotation_angle)*40,   ft_pixel(255, 0, 0, 255));

}


