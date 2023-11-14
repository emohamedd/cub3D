
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:06:06 by houattou          #+#    #+#             */
/*   Updated: 2023/11/10 22:12:26 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"


void parsing(t_all_data *data, int ac , char **av)
{
    int fd;
    if (ac != 2)
		print_err("Wrong number of arguments\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		check_file_cub(av[1]);
		if (fd == -1)
		{
			print_err("File not found\n");
		}
		else
		readfile(fd, data->map, data->dir);
		// system("leaks cub3D");
        load_textures(data);
	}
    
}