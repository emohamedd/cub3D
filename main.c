/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/10/20 16:16:19 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"


void draw_line(t_all_data *data)
{
    float x;
    float y;
    float new_x;
    float new_y;
   x = MINIMAP_SCAL_FACTOR *data->player->x;
   y = MINIMAP_SCAL_FACTOR *data->player->y;
   new_x = x + cos(data->player->rotation_angle)*40;
   new_y = y + sin(data->player->rotation_angle)*40;
    mlx_put_pixel(data->img, new_x, new_y,ft_pixel(133, 13, 77, 255));
}


int main()
{
    t_all_data *data = (t_all_data*)malloc(sizeof(t_all_data));
    data->player = (t_player *)malloc(sizeof(t_player));
   
    
    initialize_player(data);
    data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    draw_map(data->mlx, data->img);
    draw_player(data);
    draw_line(data);
    mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    return EXIT_SUCCESS;
}


