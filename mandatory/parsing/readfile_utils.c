/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:22:33 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/15 17:01:12 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_and_exit_if_invalid_map(t_map *map)
{
	if (valid_map(map) == 0 || check_map_char(map) == 0)
	{
		free_2d_arr(map->all_map);
		print_err("ERROR : Invalid MAP\n");
	}
}

void	check_file_opening(int fd, char *line)
{
	(void)line;
	if (fd == -1)
		print_err("ERROR : Failed to open file\n");
}

void	check_empty_map(char *line)
{
	if (!line)
		print_err("ERROR : Empty MAP\n");
}

void	check_empty_string(char *line)
{
	if (line[0] == '\n')
		print_err("ERROR : There is an Empty String in MAP\n");
}

void	check_and_exit_if_empty_string(char *line)
{
	if (line[0] == '\n')
		exit(0);
}
