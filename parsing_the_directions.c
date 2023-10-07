/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/07 18:34:10 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dir_parse(t_map *map)
{
    int i = 0;
    char **new_array;
    map->all_map[i] = ft_strtrim(map->all_map[i], " \t");
    map->direc = ft_split(map->all_map[i], '\n');

    while(map->all_map[i] && (map->all_map[i][0] != '1'))
    {
        map->direc[i] =  map->all_map[i];

        i++;
    }
     i = 0;
    int j = 0;
    while(map->direc[i])
    {
        j = 0;
        while (map->direc[i][j])
        {
            if (map->direc[i][j] == ' ' || map->direc[i][j] == '\t')
                map->direc[i][j] = 16;
            j++;
        }
        i++;  
    }
    i = 0;
    while (i < 6)
    {
        new_array = ft_split(map->direc[i], 16);
        if (new_array)
        {
            int k = 0;
            while (new_array[k])
            {
                printf("%s\n", new_array[k]);
                k++;
            }
        }
        i++;
    }
        map->direc[i] = NULL;
}

void map_parse(t_map * map)
{
    int i = 6;
    map->map = ft_split(map->all_map[i], '\n');
    while(map->all_map && map->all_map[i])
    {
        map->map[i] =  map->all_map[i];
        // printf("%s\n", map->map[i]);
        i++;
    }
      map->map[i] = NULL;
    

    // map->map[i] = NULL;
}