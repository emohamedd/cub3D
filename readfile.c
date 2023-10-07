/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:56:34 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/07 16:09:31 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
void readfile(int fd)
{
    char *line;
    char *next_line;
    int i  = 0;
    t_map map;

    line = get_next_line(fd);   
    check_map(fd, line);
    i = 0;
    next_line = ft_strdup("");
    while(line)
    {
        next_line = ft_strjoin(next_line, line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    map.rows = i;
    map.all_map = ft_split(next_line, '\n');
    dir_parse(&map);
    map_parse(&map);
    close(fd);
    free(line);
}