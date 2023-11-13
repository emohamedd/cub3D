/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/13 17:37:08 by emohamed         ###   ########.fr       */
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
    
}
void check_valid_width_height(t_map *map)
{
    if (map->width > WIDTH || map->height > HEIGHT)
    {
        printf("Error\n");
        exit(0);
    }
}
void free_all_data(t_all_data *data)
{
    free(data->player);
    free(data->cord);
    free(data->map);
    free(data->dir);
    if(data->mlx)
        mlx_terminate(data->mlx);
    if(data->img)    
        mlx_delete_image(data->mlx, data->img);
    if(data->img_minimap)    
        mlx_delete_image(data->mlx, data->img_minimap); 
    free(data);
}
int main(int ac , char **av)
{
    int		fd;
    t_all_data *data;
    data = init_data(data);
    parsing(data, ac, av);
    // system("leaks cub3D");
    check_valid_width_height(data->map);
    raycasting(data);
    free_all_data(data);
    return EXIT_SUCCESS;
}
