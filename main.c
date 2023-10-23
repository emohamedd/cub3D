/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/10/23 10:46:49 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"



int main()
{
    t_all_data *data = (t_all_data*)malloc(sizeof(t_all_data));
    data->player = (t_player *)malloc(sizeof(t_player));
    data->rays = (t_rays *)malloc(sizeof(t_rays));
   
    
    initialize_player(data);
    data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    mlx_key_hook(data->mlx, &my_keyhook, data);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    draw_map(data->mlx, data->img);
    draw_player(data);
    // cast_all_rays(data);
    draw_line(data->img, data->player->x, data->player->y, data->player->x + cos(data->player->rotation_angle)*40, data->player->y + sin(data->player->rotation_angle)*40);
    mlx_loop(data->mlx);

    printf("mlx_key_hook\n");
    mlx_terminate(data->mlx);
    return EXIT_SUCCESS;
}


