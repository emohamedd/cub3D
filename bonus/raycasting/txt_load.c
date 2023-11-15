/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:38:13 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/15 16:18:31 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	load_textures(t_all_data *data)
{
	data->textrs.ea_texture = mlx_load_png(data->dir->ea);
	data->textrs.we_texture = mlx_load_png(data->dir->we);
	data->textrs.so_texture = mlx_load_png(data->dir->so);
	data->textrs.no_texture = mlx_load_png(data->dir->no);
	if (!data->textrs.ea_texture || !data->textrs.we_texture
		|| !data->textrs.so_texture || !data->textrs.no_texture)
	{
		print_err("Texture not found\n");
	}
}
