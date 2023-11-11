/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/11 21:41:50 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"


void raycasting(t_all_data *data)
{

    init(data);
    drawing(data);
    mlx_key_hook(data->mlx, &my_keyhook, data);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    mlx_image_to_window(data->mlx, data->img_minimap, 0, 0);
    mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    
}

int main(int ac , char **av)
{
    int		fd;
    t_all_data *data;
    data = init_data(data);
    parsing(data, ac, av);
    raycasting(data);
    return EXIT_SUCCESS;
}


