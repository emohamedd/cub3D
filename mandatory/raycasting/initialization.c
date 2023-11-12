/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:06:06 by houattou          #+#    #+#             */
/*   Updated: 2023/11/12 12:40:51 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_all_data *init_data(t_all_data *data)
{
    data = (t_all_data*)malloc(sizeof(t_all_data));
    data->player = (t_player *)malloc(sizeof(t_player));
    data->cord = (t_cord *)malloc(sizeof(t_cord));
    data->map =(t_map *)malloc(sizeof(t_map));
    data->dir = (t_direc *)malloc(sizeof(t_direc));
    return(data);
}

void init_mlx(t_all_data *data)
{
    data->mlx = mlx_init(WIDTH,HEIGHT, "MLX42", true);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->img_minimap = mlx_new_image(data->mlx, 1000, 900);
    
}

void init(t_all_data *data)
{
    initialize_player(data);
    init_mlx(data);
    
}