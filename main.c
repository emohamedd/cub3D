/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/10/25 16:40:06 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"



int main()
{
    t_all_data *data = (t_all_data*)malloc(sizeof(t_all_data));
    data->player = (t_player *)malloc(sizeof(t_player));
    // data->rays = (t_rays *)malloc(sizeof(t_rays[WIDTH]));
    data->cord = (t_cord *)malloc(sizeof(t_cord));
   
    
    initialize_player(data);
    data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    draw_map(data->mlx, data->img);
    draw_player(data);
    mlx_key_hook(data->mlx, &my_keyhook, data);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    // render_rays(data);
    // cast_all_rays(data);
    mlx_loop(data->mlx);

    printf("mlx_key_hook\n");
    mlx_terminate(data->mlx);
    return EXIT_SUCCESS;
}


