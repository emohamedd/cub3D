/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/08 10:04:14 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dir_parse(t_map *map, t_direc *dir)
{
    int dir_len = 0;
    int i = 0;
    char **new_array;
    map->all_map[i] = ft_strtrim(map->all_map[i], " \t");
    map->direc = ft_split(map->all_map[i], '\n');

    while(map->all_map[i] && (map->all_map[i][0] != '1'))
    {
        map->direc[i] =  map->all_map[i];
        i++;
    }
    dir_len = i;
    if (dir_len != 6)
        print_err("ERROR : Wrong number of directions\n");
    i = 0;
    int j = 0;
    while(i < dir_len)
    {
        j = 0;
        while (map->direc[i][j])
        {
            if (map->direc[i][j] == ' ' )
                map->direc[i][j] = 16;
            j++;
        }
        i++;  
    }
    i = 0;
    while (i < dir_len)
    {
        new_array = ft_split(map->direc[i], 16);
        dir->key = new_array[0];
        dir->value = new_array[1];
        printf("KEY : %s\n", dir->key);
        printf("VALUE : %s\n", dir->value);
        i++;
    }
    
        map->direc[i] = NULL;
}

