/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:56:34 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/14 21:24:12 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_line/get_next_line.h"
#include "../../include/cub3d.h"
#include "../../libft/libft.h"

void	read_map_and_parse(int fd, t_map *map, t_direc *dir)
{
	char	*line;
	char	*next_line;
	int		i;
	char	*tmp;

	i = 0;
	line = get_next_line(fd);
	check_file_opening(fd, line);
	check_empty_map(line);
	check_and_exit_if_empty_string(line);
	next_line = ft_strdup("");
	while (line)
	{
		tmp = next_line;
		next_line = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	map->all_map = ft_split(next_line, '\n');
	free(next_line);
}

void	validate_and_exit_if_invalid_map(t_map *map, t_direc *dir)
{
	map_parse(map);
	check_and_exit_if_invalid_map(map);
}

void	readfile(int fd, t_map *map, t_direc *dir)
{
	read_map_and_parse(fd, map, dir);
	validate_and_exit_if_invalid_map(map, dir);
	dir_parse(map, dir);
	close(fd);
}
