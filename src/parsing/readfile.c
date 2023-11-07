/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:56:34 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/03 10:12:46 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_line/get_next_line.h"

#include"../../include/cub3d.h"

#include "../../libft/libft.h"

void	check_map(int fd, char *line)
{
	if (fd == -1)
		print_err("ERROR : Failed to open file\n");
	if (!line)
		print_err("ERROR : Empty MAP");
	if (line[0] == '\n')
		print_err("ERROR : There is a Empty String on MAP\n");
	if (line[0] == '\n')
		exit(0);
}

void	readfile(int fd, t_map *map, t_direc *dir)
{
	char	*line;
	char	*next_line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	check_map(fd, line);
	i = 0;
	next_line = ft_strdup("");
	while (line)
	{
		next_line = ft_strjoin(next_line, line);
		// free(line);
		line = get_next_line(fd);
		i++;
	}
	map->all_map = ft_split(next_line, '\n');
	map_parse(map);
	if (valid_map(map) == 0)
		print_err("ERROR : Invalid MAP\n");
	if (check_map_char(map) == 0)
		print_err("ERROR : Invalid Num Player\n");
	dir_parse(map, dir);
	close(fd);
	free(line);
}
