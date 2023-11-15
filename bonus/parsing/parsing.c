/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:10:51 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/15 16:54:04 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	parsing(t_all_data *data, int ac, char **av)
{
	int	fd;

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
		load_textures(data);
	}
}
